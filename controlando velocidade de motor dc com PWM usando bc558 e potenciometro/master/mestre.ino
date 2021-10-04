//Mestre
#include <Wire.h>
#define uno_I 4// endereço do escravo 1
#define uno_II 8//escravo 2
byte c;
void setup() {
  Wire.begin();
}
void loop() {
  Wire.requestFrom(uno_I, 1);
  while (Wire.available()) {
    c = Wire.read();
  }
  _delay_ms(50);
  Wire.beginTransmission(uno_II);
  Wire.write(c);
  Wire.endTransmission();_delay_ms(100);
}
