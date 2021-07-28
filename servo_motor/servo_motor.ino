#include <Servo.h>

Servo s;
int pos;
void setup() {
  s.attach(11);
  Serial.begin(9600);
  s.write(0);

}

void loop() {
  for(pos = 0; pos <= 180; pos++){
    s.write(pos);
    _delay_ms(15);
  }
  //s.write(45);
  _delay_ms(1000);
  //s.write(135);
  //_delay_ms(1000);
  for(pos = 180; pos >= 0; pos--){
    s.write(pos);
    _delay_ms(15);
  }

}
