📌 Project: Automatic Water Level Controller with Pump & Alert System

This project is an Arduino-based water level monitoring and control system that automatically manages a water pump based on the tank’s water level. It uses an ultrasonic sensor to measure water level distance, and provides real-time status updates on an I2C LCD display.

🔧 Features:

Ultrasonic Sensor – Measures the water level distance in cm.

LED Indicators –

Red LED → Tank Empty

Yellow LED → Medium Level

Green LED → Tank Full

Buzzer Alert – Sounds when the tank is full.

Motor Pump Control –

Turns ON when the tank is empty or medium level.

Turns OFF when the tank is full.

I2C LCD Display – Shows real-time distance and tank status.

⚡ Hardware Used:

Arduino Uno

Ultrasonic Sensor (HC-SR04)

I2C LCD (16x2)

LEDs (Red, Yellow, Green)

Buzzer

Motor Driver (L293D or L298N)

Water Pump

💻 Software:

Arduino IDE

LiquidCrystal_I2C Library

Wire Library

🚀 Working Principle:

The ultrasonic sensor continuously measures the distance of water from the sensor.

Based on the distance:

If >10 cm → Tank Empty → Pump ON

If 3–10 cm → Tank Medium → Pump stays ON

If ≤2 cm → Tank Full → Pump OFF + Buzzer ON

The LCD displays both distance in cm and tank status.
