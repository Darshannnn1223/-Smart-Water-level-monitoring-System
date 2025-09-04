#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 6;
const int echoPin = 7;

const int ledEmpty = 3;
const int ledMedium = 4;
const int ledFull = 5;

const int buzzer = 10;
const int motorIn3 = 8;
const int motorIn4 = 9;

long duration;
int distance;
bool pumpStatus = false;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledEmpty, OUTPUT);
  pinMode(ledMedium, OUTPUT);
  pinMode(ledFull, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);

  digitalWrite(ledEmpty, LOW);
  digitalWrite(ledMedium, LOW);
  digitalWrite(ledFull, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, LOW);

  pumpStatus = false;

  lcd.setCursor(0, 0);
  lcd.print("Water Level Sys");
  delay(2000);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  if (distance > 10) {
    digitalWrite(ledEmpty, HIGH);
    digitalWrite(ledMedium, LOW);
    digitalWrite(ledFull, LOW);
    digitalWrite(buzzer, LOW);
    turnPumpOn();
    lcd.setCursor(0, 1);
    lcd.print("Tank: Empty");
  } else if (distance > 3 && distance <= 10) {
    digitalWrite(ledEmpty, LOW);
    digitalWrite(ledMedium, HIGH);
    digitalWrite(ledFull, LOW);
    digitalWrite(buzzer, LOW);
    turnPumpOn();
    lcd.setCursor(0, 1);
    lcd.print("Tank: Medium");
  } else if (distance <= 2) {
    digitalWrite(ledEmpty, LOW);
    digitalWrite(ledMedium, LOW);
    digitalWrite(ledFull, HIGH);
    digitalWrite(buzzer, HIGH);
    turnPumpOff();
    lcd.setCursor(0, 1);
    lcd.print("Tank: Full");
  }

  delay(1000);
}

void turnPumpOn() {
  if (!pumpStatus) {
    digitalWrite(motorIn3, HIGH);
    digitalWrite(motorIn4, LOW);
    pumpStatus = true;
  }
}

void turnPumpOff() {
  if (pumpStatus) {
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, LOW);
    pumpStatus = false;
  }
}
