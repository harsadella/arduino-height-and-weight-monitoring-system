# Arduino Height and Weight Monitoring System

## Overview

This project is an Arduino-based height and weight monitoring system developed for academic purposes. The system combines an ultrasonic sensor for height measurement and a load cell with HX711 module for weight measurement.

Measurement results are displayed in real time on a 16x2 I2C LCD and simultaneously sent to the serial monitor for monitoring and data observation.

---

## Main Features

* Automatic height measurement using ultrasonic sensor
* Automatic weight measurement using load cell and HX711 module
* Real-time data display on 16x2 I2C LCD
* Serial monitor output for measurement logging
* Simple and reliable measurement logic

---

## Hardware Components

* Arduino Board
* Ultrasonic Sensor (HC-SR04 or compatible)
* Load Cell
* HX711 Load Cell Amplifier
* 16x2 I2C LCD Display
* Breadboard and Jumper Wires
* Stable Power Supply

---

## Pin Configuration

| Component          | Arduino Pin |
| ------------------ | ----------- |
| Ultrasonic Trigger | 10          |
| Ultrasonic Echo    | 11          |
| HX711 DOUT         | 3           |
| HX711 CLK          | 2           |
| I2C LCD            | SDA / SCL   |

---

## Software Requirements

* Arduino IDE
* Required Libraries:

  * Wire
  * LiquidCrystal_I2C
  * HX711

---

## System Architecture

The Arduino controls two main measurement subsystems:

* **Height Measurement:** Ultrasonic sensor calculates distance to determine height based on a fixed reference pole.
* **Weight Measurement:** Load cell reads weight data through the HX711 amplifier.

Both measurements are processed by the Arduino and displayed on the LCD while being logged to the serial monitor.

---

## Operation Flow

1. Arduino initializes sensors, LCD, and HX711 module
2. Ultrasonic sensor measures distance to calculate height
3. Load cell measures weight in grams
4. Invalid or negative values are filtered
5. Height and weight values are displayed on the LCD
6. Measurement data is printed to the serial monitor

---

## Display Information

* **LCD Line 1:** Height value (cm)
* **LCD Line 2:** Weight value (g)

---

## Installation Steps

1. Clone this repository: https://github.com/harsadella/arduino-height-and-weight-monitoring-system
2. Open the project in Arduino IDE
3. Install all required libraries
4. Assemble the circuit according to the pin configuration
5. Upload the main code to the Arduino board
6. Open Serial Monitor to view measurement data

---

## Project Purpose

This project was developed as an academic assignment to demonstrate:

* Sensor integration using Arduino
* Distance and weight measurement principles
* Data processing and filtering
* Real-time display and serial communication

---

## License

This project is intended for educational and learning purposes.
