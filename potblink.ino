// Define pin connections
const int ledPin = 9;        // PWM pin connected to the LED
const int potPin = A0;       // Analog pin connected to the potentiometer

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  // Initialize the potentiometer pin as an input (optional, handled by analogRead)
}

void loop() {
  // Read the potentiometer value (0 to 1023)
  int potValue = analogRead(potPin);

  // Map the potentiometer value to a range suitable for PWM (0 to 255)
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  // Set the LED brightness using PWM
  analogWrite(ledPin, pwmValue);

  // Small delay to stabilize readings
  delay(10);
}
