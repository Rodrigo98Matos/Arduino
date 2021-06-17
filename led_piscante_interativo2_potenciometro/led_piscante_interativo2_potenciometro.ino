byte azul = 8;
byte vermelho = 9;
void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(azul, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop(){
  digitalWrite(azul, HIGH);
  digitalWrite(vermelho,LOW);
  delay(analogRead(A0));

  Serial.println(analogRead(A0));
  
  digitalWrite(vermelho, HIGH);
  digitalWrite(azul, LOW);
  delay(analogRead(A0));
}
