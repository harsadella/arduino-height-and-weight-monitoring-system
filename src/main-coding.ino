#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

// ================= PIN =================
#define trigPin 10
#define echoPin 11
#define DOUT 3
#define CLK 2

// ================= OBJECTS =================
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711 scale;

// ================= VARIABLES =================
float distance;
float height;
float weight;                // in grams
const float poleHeight = 60.0;
const float calibration_factor = 428;

void setup() {
  Serial.begin(9600);

  // Ultrasonik
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // LCD
  lcd.init();
  lcd.backlight();

  // HX711
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);
  scale.tare();   // tare the scale

  // ================= INITIAL DISPLAY =================
  lcd.setCursor(0, 0);
  lcd.print("TEAM NAME");
  lcd.setCursor(0, 1);
  lcd.print("STUDENT ID");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEAM NAME");
  lcd.setCursor(0, 1);
  lcd.print("STUDENT ID");
  delay(2000);

  lcd.clear();
}

void loop() {
// ================= ULTRASONIC =================
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH, 30000);
distance = duration * 0.034 / 2;

if (distance > 0 && distance <= poleHeight) {
  height = poleHeight - distance;
} else {
  height = 0;
}

// ================= LOAD CELL =================
weight = scale.get_units(10); // GRAMS

if (weight < 0) weight = 0;   // prevent negative value

// ================= SERIAL MONITOR =================
Serial.println("=== MEASUREMENT DATA ===");
Serial.print("Height (cm): ");
Serial.println(height);
Serial.print("Weight (grams): ");
Serial.println(weight);
Serial.println("========================");
Serial.println();

// ================= LCD =================
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("H:");
lcd.print(height, 1);
lcd.print("cm");

lcd.setCursor(0, 1);
lcd.print("W:");
lcd.print(weight, 0);
lcd.print("g");

delay(3000);
}
