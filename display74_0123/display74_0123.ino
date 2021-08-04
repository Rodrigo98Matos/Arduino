int num1 = 0, num2 = 0, num3 = 0, num4 = 0, cont = 0;
byte abcdef[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
byte digito[4] = {0b000001110, 0b000001101, 0b000001011,0b00000111};

void setup() {
  DDRD = 0b11111111; // F E D C B A
  DDRB = 0b00001111; // 4 3 2 1 DP G
}

void loop() {
  PORTD = abcdef[num1]; PORTB = digito[0];
  _delay_ms(1);
  PORTD = abcdef[num2]; PORTB = digito[1];
  _delay_ms(1);
  PORTD = abcdef[num3]; PORTB = digito[2];
  _delay_ms(1);
  PORTD = abcdef[num4]; PORTB = digito[3];
  _delay_ms(1);
  PORTD = 0b10000000; PORTB = digito[2];
  _delay_ms(1);
  cont++;
  if (cont == 200){
    num1++;
    if (num1 == 10){
      num2++;
      if (num2 == 6){
        num3++;
        num2 = 0;
        if (num3 == 10){
          num4++;
          if (num4 == 6){
            num4 = 0;
          }
          num3 = 0;
        }
      }
      num1 = 0;
    }
    cont = 0;
  }
}
