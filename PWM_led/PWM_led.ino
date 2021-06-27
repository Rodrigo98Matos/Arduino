void setup(){
  DDRD = 0b01100000;
}

void loop(){
  for(int i=0,c=255;i<=255;i++,c--){
    analogWrite(6,i);
    analogWrite(5,c);
    _delay_ms(10);
  }
  for(int i = 255,c=0;i>=0;i--,c++){
    analogWrite(6,i);
    analogWrite(5,c);
    _delay_ms(10);
  }
}
