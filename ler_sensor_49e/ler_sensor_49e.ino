//Sonsor magnetico 49e

void setup() {
  Serial.begin(9600);

}

void loop() {
  int mag = analogRead(A0)-527;
  
  Serial.println(mag);
  
  _delay_ms(500);

}
