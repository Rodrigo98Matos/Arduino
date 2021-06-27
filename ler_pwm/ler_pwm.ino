void setup() {
  Serial.begin(9600);
  DDRD = 0b00000000;
}

void loop() {
  Serial.println(pulseIn(3,0));
  _delay_ms(500);
  // put your main code here, to run repeatedly:

}
