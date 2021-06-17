byte botao1 = 2;
byte botao2 = 4;
byte azul = 8;
byte vermelho = 9;

void setup(){
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2,  INPUT_PULLUP);
  pinMode(azul, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop(){
  if (digitalRead(botao1) == 0){
    digitalWrite(azul, HIGH);
    digitalWrite(vermelho, HIGH);
  }else{
    digitalWrite(azul, LOW);
    digitalWrite(vermelho, LOW);
  }
  if(digitalRead(botao2) == 0){
    pisca();
  }
}

void pisca(){
  while(1){
      digitalWrite(azul, HIGH);
      digitalWrite(vermelho, LOW);
      delay(300);
      if (digitalRead(botao1) == 0){
        break;
      }
      digitalWrite(vermelho, HIGH);
      digitalWrite(azul, LOW);
      delay(300);
      if(digitalRead(botao1) == 0){
        break;
      }
  }
}
