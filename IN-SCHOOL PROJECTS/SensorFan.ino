const int lightPin = A0;
const int potPin = A1;
const int fanPin = 9; // PWM output to transistor base

int lightThreshold = 500; // Adjust as needed (0–1023)

void setup() {
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(lightPin);
  int potValue = analogRead(potPin);
  int fanSpeed = map(potValue, 0, 1023, 0, 255);

  Serial.print("Light: ");
  Serial.print(lightLevel);
  Serial.print(" | Pot: ");
  Serial.print(potValue);
  Serial.print(" | Fan Speed: ");
  Serial.println(fanSpeed);

  if (lightLevel > lightThreshold) {
    analogWrite(fanPin, fanSpeed); // Turn on fan with variable speed
  } else {
    analogWrite(fanPin, 0); // Turn off fan
  }

  delay(100);
}
