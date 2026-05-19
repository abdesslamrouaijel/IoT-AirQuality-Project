#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// ================= WIFI =================
#define WIFI_SSID     "Wokwi-GUEST"
#define WIFI_PASSWORD ""

// ================= THINGSBOARD =================
#define TB_SERVER     "eu.thingsboard.cloud"
#define TOKEN         "Qj2dhj86Lhl7wznoLiTK"

// ================= SENSORS =================
#define DHTPIN 14
#define DHTTYPE DHT22 
#define MQ135_PIN 34   // ✅ MQ-135 analog pin

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(MQ135_PIN, INPUT); // MQ-135 setup
  
  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  client.setServer(TB_SERVER, 1883);
}

// ================= MQTT RECONNECT =================
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to ThingsBoard...");

    if (client.connect("Wokwi_ESP32_Device", TOKEN, NULL)) {
      Serial.println("CONNECTED!");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retry in 5s");
      delay(5000);
    }
  }
}

// ================= LOOP =================
void loop() {
  if (WiFi.status() != WL_CONNECTED) return;
  if (!client.connected()) reconnect();

  static unsigned long lastSend = 0;

  if (millis() - lastSend > 5000) {
    lastSend = millis();

    float t = dht.readTemperature();
    float h = dht.readHumidity();
    int gasValue = analogRead(MQ135_PIN); // ✅ MQ-135 reading

    if (!isnan(t) && !isnan(h)) {

      Serial.print("Temp: "); Serial.print(t);
      Serial.print(" | Humidity: "); Serial.print(h);
      Serial.print(" | Gas: "); Serial.println(gasValue);

      // ================= JSON PAYLOAD =================
      String payload = "{";
      payload += "\"temperature\":" + String(t) + ",";
      payload += "\"humidity\":" + String(h) + ",";
      payload += "\"airQuality\":" + String(gasValue);
      payload += "}";

      // ================= SEND =================
      if (client.publish("v1/devices/me/telemetry", payload.c_str())) {
        Serial.println("Sent: " + payload);
      } else {
        Serial.println("Failed to publish telemetry");
      }

    } else {
      Serial.println("Error: Failed to read from DHT22!");
    }
  }

  client.loop();
}