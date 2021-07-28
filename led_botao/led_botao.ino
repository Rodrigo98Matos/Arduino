void setup(){
  pinMode(13, OUTPUT);
  pinMode(2,INPUT_PULLUP);
}

void loop(){
  int botao = digitalRead(2);
  if (botao == 0){
    digitalWrite(13, 1);
    digitalWrite(8, 1);
    
  }
  else{
    digitalWrite(13,0);
    digitalWrite(8,0);
  }
}
