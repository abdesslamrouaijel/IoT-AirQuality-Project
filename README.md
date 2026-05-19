# Mini Projet IoT : Surveillance de la Qualité de l'Air (Smart Environment)

Ce projet consiste à mettre en place un système de surveillance de la qualité de l'air en temps réel. L'objectif principal est de détecter toute pollution anormale afin d'assurer un environnement sain en envoyant des alertes instantanées et en visualisant les données sur un tableau de bord.

## 🎯 Objectif
Surveiller la qualité de l'air en temps réel afin de détecter toute pollution anormale et assurer un environnement sain.

## 🛠️ Composants et Matériel

### Matériel (Hardware)
* **Microcontrôleur / Ordinateur monocarte :** ESP32 ou Raspberry Pi
* **Capteur de température et d'humidité :** DHT22
* **Capteur de qualité de l'air :** MQ-135

### Cloud et Services
* **Plateforme IoT :** ThingsBoard
* **Protocoles & Notifications :** Alerte via MQTT, SMS, Email, WhatsApp

## 🚀 Étapes de Réalisation

1. **Mesure en temps réel :** Acquisition des données de température, d'humidité et de qualité de l'air via les capteurs DHT22 et MQ-135.
2. **Transmission des données :** Envoi des données collectées à la plateforme **ThingsBoard** en utilisant le protocole **MQTT**.
3. **Seuils et Alertes MQTT :** Déclenchement automatique d’une alerte MQTT si le seuil de pollution dépasse un niveau critique prédéfini.
4. **Notifications multi-canaux :** Envoi d'une alerte par **SMS**, **Email** et **WhatsApp** en cas de pollution excessive.
5. **Visualisation :** Affichage et suivi des données historiques et en temps réel sur un **dashboard interactif** personnalisé sur ThingsBoard.

## 📁 Structure du Projet

Le projet est développé sous l'environnement **PlatformIO** et configuré pour la simulation sur **Wokwi** :

```text
├── .pio/                 # Fichiers de build et bibliothèques mis en cache par PlatformIO
├── .vscode/              # Configuration locale de VS Code
├── include/              # Fichiers d'en-tête globaux (.h)
├── lib/                  # Bibliothèques privées du projet
├── src/                  # Code source principal du projet (ex: main.cpp)
├── test/                 # Tests unitaires et de validation
├── .gitignore/           # Fichiers et dossiers à exclure du suivi Git
├── diagram.json          # Configuration du circuit électronique pour Wokwi
├── README.md             # Présentation et documentation du projet (ce fichier)
├── platformio.ini        # Fichier de configuration principal de PlatformIO (cartes, dépendances)
└── wokwi.toml            # Configuration de l'intégration et du lancement de la simulation Wokwi