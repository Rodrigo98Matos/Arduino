int verde = 8;
int amarelo = 9;
int vermelho = 10;
int pverde = 11;
int pvermelho = 12;
int botao = 2;
int tempominimo = 5000;
unsigned long atual;

void setup(){
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(pverde, OUTPUT);
  pinMode(pvermelho, OUTPUT);
  pinMode(botao, INPUT);

  digitalWrite(verde, HIGH);
  digitalWrite(pvermelho,HIGH);
}

void loop(){
  int estado = digitalRead(botao);
  if (estado == HIGH && (millis() - tempominimo) > 5000){
    funcionamento();
  }
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, HIGH);
  delay(2000);
  
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);
  delay(1000);

  digitalWrite(pvermelho, LOW);
  digitalWrite(pverde, HIGH);
  delay(tempominimo);

  for (int i = 0; i < 10; i++){
    digitalWrite(pverde, HIGH);
    delay(250);
    digitalWrite(pverde, LOW);
    delay(250);
  }
  digitalWrite(verde, HIGH);
  digitalWrite(pvermelho, HIGH);
  delay(500);
  
  digitalWrite(amarelo, HIGH);
  digitalWrite(vermelho, LOW);
  delay(1000);
  
  digitalWrite(verde, HIGH);
  digitalWrite(amarelo,LOW);

  atual = millis();
}
void funcionamento(){
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, HIGH);
  delay(2000);
  
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);
  delay(1000);

  digitalWrite(pvermelho, LOW);
  digitalWrite(pverde, HIGH);
  delay(tempominimo);

  for (int i = 0; i < 10; i++){
    digitalWrite(pverde, HIGH);
    delay(250);
    digitalWrite(pverde, LOW);
    delay(250);
  }
  digitalWrite(pvermelho, HIGH);
  delay(500);
  
  digitalWrite(amarelo, HIGH);
  digitalWrite(vermelho, LOW);
  delay(1000);
  
  digitalWrite(verde, HIGH);
  digitalWrite(amarelo,LOW);

  atual = millis();
}
