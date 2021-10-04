//escravo uno_II
#include <Wire.h>
#define uno_II 8
byte c;
void setup() {
  //fast PWM, TOP = 0xFF, OC0A e OC0B habilitados
  DDRD |= (1<<PD6);
  TCCR0A = 0b10000011; //PWM não invertido no pino OC0A
  TCCR0B = 0b00000011; //liga TC0, prescaler = 64
  Wire.begin(uno_II);
  OCR0A = 0;
  Wire.onReceive(recebe);
}
void recebe(){
  while (Wire.available()) {c = Wire.read();}
  OCR0A = c;
}
void loop() {}
