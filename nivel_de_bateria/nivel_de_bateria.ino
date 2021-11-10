//Nivel de duas baterias de 4.2V em serie
void setup() {
  Serial.begin(9600);
}
void loop() {
  float Vcc = (analogRead(A0) * 5) / 1023;
  float Vin = Vcc / 0.5;//22000/(22000+22000) = 0.5
  int nivel = (Vin * 100) / 8.4;
  Serial.print("Nível de Bateria:\t"); Serial.print(nivel);Serial.println("%");
  delay(2000);
}
