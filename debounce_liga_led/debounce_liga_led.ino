int guarda_estado, estado = 0;
void setup() {
  DDRB |= (1<<2); //LED no pino 10 e o resto dos pinos como entrada
  PORTD = 0b00001000;
}
void loop() {
  estado = PIND & (1<<3);
  if(estado){
    guarda_estado = !guarda_estado;
    while(PIND & (1<<3)){}
    _delay_ms(50);
  }
  if(guarda_estado == 1){
    PORTB |= (1<<2);
  }else{
    PORTB &= ~(1<<2);
  }
}
