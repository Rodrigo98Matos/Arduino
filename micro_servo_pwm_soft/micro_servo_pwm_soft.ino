#define set_bit(reg,bit_x) (reg|=(1<<bit_x))
#define clr_bit(reg,bit_x) (reg&=~(1<<bit_x))
void setup() {
  set_bit(DDRD,3);
}
void servo(int g){
  //g é um número inteiro entre 0 e 1024
  int duty_cycle = (2000-(g/0.512))+500;
  for(int i =0;i<=10;i++){
    set_bit(PORTD,3);_delay_us(duty_cycle);
    clr_bit(PORTD,3);_delay_us(20000-duty_cycle);
  }
}
void loop() {
  servo(0);
  _delay_ms(500);
  servo(512);
  _delay_ms(500);
  servo(1024);
  _delay_ms(500);
}
