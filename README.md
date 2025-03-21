# Motion-Activated LED System with LDR

## Overview
This Arduino-based project controls LEDs using IR sensors and an LDR (Light Dependent Resistor). The system dims or brightens LEDs based on motion detection while turning them off when sufficient ambient light is detected.

## Features
- **LDR Light Detection**: Turns off all LEDs when ambient light is above a threshold.
- **IR Sensor-Based Motion Detection**: Adjusts LED brightness based on motion detected by three IR sensors.
- **LED Dimming Control**: LEDs remain dim and brighten only when motion is detected.

## Components Used
- **Arduino Board** (Uno, Mega, etc.)
- **LDR (Light Dependent Resistor)**
- **IR Sensors (x3)**
- **LEDs (x3)**
- **Resistors** (as required)
- **Connecting Wires**

## Circuit Diagram
(You can include an image of your circuit diagram here)

## Code Explanation
1. **Pin Initialization**: Defines pins for LDR, IR sensors, and LEDs.
2. **LDR Light Detection**: Reads the analog value of the LDR to determine ambient light levels.
3. **IR Sensor Motion Detection**: Reads digital input from IR sensors.
4. **LED Brightness Control**:
   - LEDs remain dim (50/255 brightness) when no motion is detected.
   - LEDs brighten (255/255 brightness) when motion is detected.
   - LEDs turn off completely when ambient light is sufficient.

## Arduino Code
```cpp
const int ldrPin = A0;
const int irPin1 = 2;
const int irPin2 = 3;
const int irPin3 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int ledPin3 = 7;

void setup() {
    pinMode(ldrPin, INPUT);
    pinMode(irPin1, INPUT);
    pinMode(irPin2, INPUT);
    pinMode(irPin3, INPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
}

void loop() {
    int ldrValue = analogRead(ldrPin);
    int irValue1 = digitalRead(irPin1);
    int irValue2 = digitalRead(irPin2);
    int irValue3 = digitalRead(irPin3);
    
    if (ldrValue > 600) {
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
    } else {
        analogWrite(ledPin1, irValue1 == HIGH ? 50 : 255);
        analogWrite(ledPin2, irValue2 == HIGH ? 50 : 255);
        analogWrite(ledPin3, irValue3 == HIGH ? 50 : 255);
    }
    delay(100);
}
```

## How to Use
1. **Connect Components**: Assemble the circuit as per the wiring diagram.
2. **Upload Code**: Copy and paste the Arduino code into the IDE and upload it to your board.
3. **Test the System**:
   - Cover/uncover the LDR to see if LEDs turn off.
   - Move in front of IR sensors to see LEDs brighten.

## Customization
- Adjust `ldrValue > 600` threshold to change sensitivity to light.
- Modify `int ledBrightness = 50;` to adjust the dim level of LEDs.
- Increase `delay(100);` for more stability in readings.



