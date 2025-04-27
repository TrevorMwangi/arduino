// C++ code
//
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(32, 16, 2);

void setup()
{
  lcd_1.init();

  lcd_1.setCursor(0, 0);
  lcd_1.backlight();
  lcd_1.display();
}

void loop()
{
  lcd_1.setCursor(0, 0);
  lcd_1.print("haseeb");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.setCursor(0, 1);
  lcd_1.print("electronics");
  delay(2000); // Wait for 2000 millisecond(s)
  lcd_1.clear();
}