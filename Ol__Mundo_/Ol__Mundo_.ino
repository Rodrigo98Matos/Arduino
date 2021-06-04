// C++ code
//
int counter;

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  for (counter = 0; counter < 10; ++counter) {
    digitalWrite(9, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(9, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}
