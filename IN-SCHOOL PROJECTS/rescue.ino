#include <LedControl.h>

// Pin connections
 DIN_PIN = 11;   // MOSI
 CLK_PIN = 13;   // Clock
 CS_PIN = 10;    // Load (CS)
 SWITCH_PIN = 2; // Switch input
 BUZZER_PIN = 8; // Buzzer output

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 3); // 3 displays

void setup() {
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Use internal pull-up
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize all LED matrices
  for (int i = 0; i < 3; i++) {
    lc.shutdown(i, false);    // Wake up displays
    lc.setIntensity(i, 8);    // Set brightness (0-15)
    lc.clearDisplay(i);       // Clear display
  }
}

void loop() {
  bool switchState = digitalRead(SWITCH_PIN) == LOW; // Active LOW (pressed/on)

  if (switchState) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer ON
    scrollMessage("HELP! HELP! HELP!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer OFF
    showMessage("PHEW!");
    delay(500); // So "PHEW!" stays visible
  }
}

void scrollMessage(String message) {
  static unsigned long lastScroll = 0;
  static int scrollPos = 0;
  int scrollSpeed = 100; // milliseconds per scroll

  if (millis() - lastScroll > scrollSpeed) {
    lastScroll = millis();
    lc.clearDisplay(0);
    lc.clearDisplay(1);
    lc.clearDisplay(2);

    for (int i = 0; i < message.length(); i++) {
      lc.setChar(2 - (i / 8), 7 - (i % 8) + scrollPos, message.charAt(i), false);
    }
    scrollPos++;
    if (scrollPos > 8) {
      scrollPos = 0;
    }
  }
}

void showMessage(String message) {
  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);

  for (int i = 0; i < message.length() && i < 24; i++) {
    lc.setChar(2 - (i / 8), 7 - (i % 8), message.charAt(i), false);
  }
}
