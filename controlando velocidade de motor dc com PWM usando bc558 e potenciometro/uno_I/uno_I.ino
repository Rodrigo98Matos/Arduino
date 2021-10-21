//uno_I
//Escravo lê sonsor e envia leitura através da comunicação i²c, quando solicitado
//Autor: Rodrigo Matos
#include <Wire.h>
#define uno_I 4
#define set_bit(reg,bit_x) (reg|=(1<<bit_x))
#define clr_bit(reg,bit_x) (reg&=~(1<<bit_x))
byte valor;
bool convertido = 1;
void setup() {
  ADCSRA = 0b10000111; // Enable ADC, prescaler = 128
  ADMUX = 0b01100000; //tensão de referência AVCC / conversão alinhada a esquerda / A0 como entrada para o ADC
  Wire.begin(uno_I);
  Wire.onRequest(enviar);
}
void enviar(){
  if (convertido) {
    set_bit(ADCSRA,ADSC); // 1 no segundo bit do ADCSRA iniciar leitura em A0
    convertido = 0;
  }
  if (!(ADCSRA & (1<<ADSC))) {//avalia se a leitura já foi concluída
    convertido = 1;
    valor = ADCH;
  }
  Wire.write(valor);
}
void loop() {}
