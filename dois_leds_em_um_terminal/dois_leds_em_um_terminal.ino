//Dois LEDs em um unico terminal
void setup() { 
}
void loop() {
  pinMode(13, OUTPUT);
  digitalWrite(13, 1);delay(1000);
  for(int i=0;i<50;i++){
    digitalWrite(13,1);delay(10);
    digitalWrite(13,0);delay(10);
  }
  digitalWrite(LED_BUILTIN, 0);delay(1000);
  pinMode(13, INPUT);delay(1000);
}
