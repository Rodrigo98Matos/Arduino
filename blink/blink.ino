//hello world
void setup() {
  DDRB |= (1<<5);
  //pinMode(13,OUTPUT);
}

void loop() {
  PORTB |= (1<<5); _delay_ms(1000);
  //digitalWrite(13,HIGH); delay(1000);
  PORTB &= ~(1<<5); _delay_ms(1000);
  //digitalWrite(13,LOW); delay(1000);
}
