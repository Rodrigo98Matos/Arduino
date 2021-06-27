void setup(){
  Serial.begin(9600);
}

void loop(){
  int pot = analogRead(A0);
  int foto = analogRead(A1);
  Serial.print("Potenciometro:\t");
  Serial.println(pot);
  Serial.print("LDR:\t");
  Serial.println(foto);
  delay(500);
}
