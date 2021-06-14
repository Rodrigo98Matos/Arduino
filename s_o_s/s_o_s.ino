int led = 10, led2 = 8;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop(){
  for (int i = 0;i<3;i++){
    digitalWrite(led,1);
    delay(150);
    digitalWrite(led, 0);
    delay(100);
  }
  delay(100);
  for (int i = 0;i<3;i++){
    digitalWrite(led, 1);
    delay(400);
    digitalWrite(led,0);
    delay(100);
  }
  delay(100);
  for (int i = 0;i<3;i++){
    digitalWrite(led,1);
    delay(150);
    digitalWrite(led,0);
    delay(100);
  }
  delay(5000);
  
  for (int i = 0;i<3;i++){
    digitalWrite(led2,1);
    delay(150);
    digitalWrite(led2, 0);
    delay(100);
  }
  delay(100);
  for (int i = 0;i<2;i++){
    digitalWrite(led2, 1);
    delay(400);
    digitalWrite(led2,0);
    delay(100);
  }
  delay(100);
  for (int i = 0;i<3;i++){
    digitalWrite(led2,1);
    delay(150);
    digitalWrite(led2,0);
    delay(100);
  }
  delay(5000);
}
