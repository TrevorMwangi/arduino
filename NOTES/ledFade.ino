int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; <= 255; i++){
    analogWrite(ledPin, i); //increase brightness
    delay(10);
  }
  for (int i = 255; i >= 0; i--){
    analogWrite(ledPin, i); //decrease brightness
    delay(10);
  }
}