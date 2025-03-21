// Define pins
const int ldrPin = A0;
const int irPin1 = 2;
const int irPin2 = 3;
const int irPin3 = 4;
const int ledPin1 = 5;
const int ledPin2 = 6;
const int ledPin3 = 7;

void setup() {
  // Initialize pins
  pinMode(ldrPin, INPUT);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
  pinMode(irPin3, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // Read LDR value
  int ldrValue = analogRead(ldrPin);
  
  // Read IR sensor values
  int irValue1 = digitalRead(irPin1);
  int irValue2 = digitalRead(irPin2);
  int irValue3 = digitalRead(irPin3);

  // Check if LDR detects light (adjust threshold as necessary)
  if (ldrValue > 600) {  // Threshold value; adjust based on your LDR sensitivity
    // Turn off all LEDs if light is detected by the LDR
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  } else {
    // If no light is detected by the LDR
    // Check each IR sensor separately

    // LED 1 control
    if (irValue1 == HIGH) {
      // Bright LED1 if motion detected by IR1
      int ledBrightness = 50;  // Adjust dim level (0-255)
      analogWrite(ledPin1, ledBrightness);
      
    } else {
      // Dim LED1 if no motion detected by IR1
      analogWrite(ledPin1, 255); // Full brightness
    }

    // LED 2 control
    if (irValue2 == HIGH) {
      // Bright LED2 if motion detected by IR2
      int ledBrightness = 50;  // Adjust dim level (0-255)
      analogWrite(ledPin2,ledBrightness ); // Full brightness
    } else {
      // Dim LED2 if no motion detected by IR2
      analogWrite(ledPin2, 255);
    }

    // LED 3 control
    if (irValue3 == HIGH) {
      // Bright LED3 if motion detected by IR3
      int ledBrightness = 50;  // Adjust dim level (0-255)
      analogWrite(ledPin3, ledBrightness);
      
    } else {
      // Dim LED3 if no motion detected by IR3
     analogWrite(ledPin3, 255); // Full brightness
    }
  }
  
  // Short delay for stability
  delay(100);
}
