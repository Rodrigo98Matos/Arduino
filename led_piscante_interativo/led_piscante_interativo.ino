int azul = 8;
int vermelho = 9;
int botao = 2;

void setup(){
  pinMode(azul,OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(botao,INPUT_PULLUP);
}

void loop(){
  digitalWrite(azul,HIGH);
  digitalWrite(vermelho,LOW);
  delay(500);
  
  if (digitalRead(botao) == LOW){
    mudar();
  }
  digitalWrite(vermelho,HIGH);
  digitalWrite(azul,LOW);
  delay(500);

  if (digitalRead(botao) == LOW){
    mudar();
  }
}

void mudar(){
  while(1){
    digitalWrite(azul,HIGH);
    digitalWrite(vermelho,LOW);
    delay(250);

    if(digitalRead(botao) == LOW){
      break;
    }
  
    digitalWrite(vermelho,HIGH);
    digitalWrite(azul,LOW);
    delay(250);
  
    if(digitalRead(botao) == LOW){
      break;
    }
  }
}
