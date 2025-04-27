#include "HX711.h"
#include <Servo.h>

// Pin Definitions
#define DT  3
#define SCK 2
#define SERVO_PIN 9
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 7

// HX711 and Servo objects
HX711 scale;
Servo dumpTruckServo;

// Weight limits
const float weightLimit = 500.0; // grams
const float halfLimit = weightLimit * 0.5; 
const float overLimit = weightLimit * 1.2; // 120% of limit

void setup() {
  Serial.begin(9600);

  // HX711 setup
  scale.begin(DT, SCK);
  scale.set_scale();    // You must adjust this based on your calibration
  scale.tare();          // Reset the scale to 0

  // Servo setup
  dumpTruckServo.attach(SERVO_PIN);

  // RGB LED setup
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  setColor(0, 0, 0); // LED off
}

void loop() {
  float weight = scale.get_units(5); // Get average of 5 readings
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" g");

  if (weight > overLimit) {
    setColor(255, 0, 0); // Red (too much)
    dumpTruckServo.write(0); // Keep it in starting position
  } else if (weight >= weightLimit) {
    setColor(0, 255, 0); // Green (ready to dump)
    dumpTruckServo.write(90); // Move the servo to dump
    delay(2000); // wait 2 seconds while dumping
    dumpTruckServo.write(0); // return to start
  } else if (weight >= halfLimit) {
    setColor(0, 0, 255); // Blue (half full)
    dumpTruckServo.write(0); // no dumping yet
  } else {
    setColor(0, 0, 0); // LED off (not much weight)
    dumpTruckServo.write(0);
  }

  delay(300); // Small delay
}

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
