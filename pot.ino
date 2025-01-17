/* C++ code  */
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

/* By turning the shaft of the potentiometer, you change the amount of resistance on
 either side of the wiper, which is connected to the center pin of the potentiometer.
  This changes the voltage at the center pin. When the resistance between the center and the side connected to 5 volts is close to zero 
  (and the resistance on the other side is close to 10k ohm), the voltage at the center pin nears 5 volts. When the resistances are reversed, 
  the voltage at the center pin nears 0 volts, or ground. This voltage is the analog voltage that you're reading as an input. */