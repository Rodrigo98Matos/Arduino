void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}

void loop(){
  int botao1 = digitalRead(2), botao2 = digitalRead(4);
  if (botao1 == 0){
    digitalWrite(13,1);
  }
  else{
    digitalWrite(13,0);
  }
  if(botao2 == 0){
    digitalWrite(12,1);
  }
  else{
    digitalWrite(12,0);
  }
}
