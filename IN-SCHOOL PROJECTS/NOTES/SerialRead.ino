int pot = A0;

void setup(){
    Serial.begin(9600);
    pinMode(pot, INPUT);
}

void loop(){
    int potvalue = analogRead(pot);
    Serial.println(potvalue);
}