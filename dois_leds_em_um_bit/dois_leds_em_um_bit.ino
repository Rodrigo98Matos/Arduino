void setup() {
  

}

void loop() {
  DDRB |= (1<<5);
  PORTB |= (1<<5); _delay_ms(500);
  for(int i = 0;i < 250;i++){
    PORTB |= (1<<5); _delay_ms(1);
    PORTB &= ~(1<<5); _delay_ms(1);
  }
  PORTB &= ~(1<<5); _delay_ms(500);
  DDRB &= ~(1<<5); _delay_ms(500);
}
