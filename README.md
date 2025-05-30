# ESP32-Water-Level-Monitoring-System

A system that monitors water level and volume using an HC-SR04 ultrasonic sensor and sends data to Blynk IoT platform.

## Features
- Real-time water level measurement
- Volume calculation based on container/tank dimensions
- Blynk IoT integration for remote monitoring
- Serial output for debugging

## Hardware Requirements
- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- Jumper Wires

## Wiring Diagram
TRIG_PIN (26) -> HC-SR04 Trig
ECHO_PIN (27) -> HC-SR04 Echo
GND -> HC-SR04 GND
VCC (5V) -> HC-SR04 VCC


## Setup
1. Clone this repository
2. Open in Arduino IDE
3. Install required libraries:
   - Blynk by Volodymyr Shymanskyy
   - WiFi for ESP32
4. Update configuration in `ultrasonic_water_level.ino`:
   - WiFi credentials
   - Blynk auth token
   - Container/Tank dimensions
5. Upload to ESP32

## Blynk Setup
1. Create new project in Blynk app
2. Add two Gauge widgets:
   - Pin V0 for water level
   - Pin V1 for water volume

