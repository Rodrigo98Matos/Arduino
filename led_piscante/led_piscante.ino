// 1° Projeto
int ledpin = 13;
void setup(){
  pinMode(ledpin, OUTPUT);
}
void loop(){
  digitalWrite(ledpin, HIGH); //Ligar o LED na porta 10
  delay(1000); // esperar 1 segundo com o LED ligado
  digitalWrite(ledpin, LOW); // Desligar o LED na porta 10
  delay(1000);
}
