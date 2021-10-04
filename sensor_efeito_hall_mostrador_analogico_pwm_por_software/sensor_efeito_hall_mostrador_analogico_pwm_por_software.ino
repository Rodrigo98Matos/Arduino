#define set_bit(reg,bit_x) (reg|=(1<<bit_x))
#define clr_bit(reg,bit_x) (reg&=~(1<<bit_x))
bool convertido = 1;
void servo(int g){//g é um número inteiro entre 0 e 1024
  int duty_cycle = (2000-(g/0.512))+500;
  for(int i =0;i<=10;i++){
    set_bit(PORTD,3);delayMicroseconds(duty_cycle);
    clr_bit(PORTD,3);delayMicroseconds(20000-duty_cycle);
  }
}
void setup(){
  ADCSRA = 0b10000111; // Enable ADC, prescaler = 128
  ADMUX = 0b01000000; // tensão de referência AVCC e A0 como entrada do ADC (REFS)
}
int lerA0(){
  if (convertido) {
    set_bit(ADCSRA,ADSC); // iniciar leitura em A0
    convertido = 0;
  }
  if (!(ADCSRA & (1<<ADSC))) {
    //int valor = ADC;
    convertido = 1;
    return (ADC);
  }
}
void loop() {
  servo(lerA0());
  _delay_ms(100);
}
