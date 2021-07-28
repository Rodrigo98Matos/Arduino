// Mostrador Analógico
// 1023/5.67 = 180 graus
// 1023*9.7752 = 10000 homs

#include <Servo.h>

Servo s;
int graus;
int ohms;
int pot;

void setup() {
  Serial.begin(9600);
  s.attach(9);
  s.write(180);
  
  

}

void loop() {
  pot = analogRead(A0);
  graus = 180-(pot/5.67);
  ohms = (pot*9.7752);
  Serial.print(ohms);
  Serial.println("   Ohms");
  s.write(graus);
  _delay_ms(100);

}
