void setup()
{
  //pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop()
{
  Serial.write('A');
  _delay_ms(500);
  Serial.write('a');
  _delay_ms(500);
}
