# IoT air-quality prototype: repository guide

This ESP32/Arduino prototype reads temperature and humidity from a DHT22 and an analog signal from an MQ-135, then publishes telemetry to ThingsBoard over MQTT. The repository also contains Wokwi simulation configuration.

## Where to look

- `src/` — application firmware and sensor/telemetry logic.
- `platformio.ini` — ESP32 board, framework, serial monitor, and library configuration.
- `diagram.json` and `wokwi.toml` — Wokwi circuit and simulation settings.
- `include/`, `lib/`, and `test/` — PlatformIO project directories.
- `README.md` — the existing project description and broader goals.

## Implementation scope

The checked-in firmware focuses on sensor readings and telemetry publication. Treat dashboard, alerting, or analytics capabilities described as goals separately from functionality verified in the firmware. Sensor readings are prototype data and are not documented here as calibrated air-quality measurements.

Existing configuration and source paths are unchanged.
