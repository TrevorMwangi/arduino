const int ledPin = 9;
 // You can change this to the pin you're using

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize the external LED pin as an output
  pinMode(ledPin, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000);                // Wait for a second
  digitalWrite(ledPin, LOW);  // Turn the LED off
  delay(1000);                // Wait for a second
}

// Connections:

Connect the longer leg (anode) of the LED to a digital pin on the Arduino (e.g., pin 9).
Connect the shorter leg (cathode) of the LED to one end of the resistor.
Connect the other end of the resistor to the GND pin on the Arduino.