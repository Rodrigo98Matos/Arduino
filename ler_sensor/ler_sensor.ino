void setup() {
  Serial.begin(9600);

}

void loop() {
  int pot = analogRead(A0);
  
  Serial.println(pot);
  
  _delay_ms(500);

}
