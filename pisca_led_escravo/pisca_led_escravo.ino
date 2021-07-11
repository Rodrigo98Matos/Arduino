void setup()
{
  Serial.begin(9600);

  pinMode(9, OUTPUT);
}

void loop()
{
  if(Serial.available()){
    char c = Serial.read();
    Serial.println(c);
    if (c == 'A') {
      digitalWrite(9, 1);
    }
    if(c=='a'){
      digitalWrite(9,0);
    }
  }
}
