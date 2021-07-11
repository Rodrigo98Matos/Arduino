void setup() {
  Serial.begin(9600);

}

void loop() {
  int pot = analogRead(A0);
  int pot2 = analogRead(A1);
  Serial.printf('%d %d\n',pot,pot2);
  //Serial.print("\t");
  //Serial.println(pot2);
  _delay_ms(500);

}
