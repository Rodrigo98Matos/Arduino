//byte passo[4] = [0b00000001,0b00000010,0b00000100,0b00001000];
void setup() {
  DDRB = 0x0F;

}

void loop() {
  for(int i = 0;i<=8;i=i*2){
    PORTB = i; _delay_ms(250);
  }

}
