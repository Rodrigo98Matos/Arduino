byte numero[4] = {0b11111100, 0b01100000, 0b11011010, 0b11110010};
byte estado = 0, disp = numero[0], mostrador = 0, resultado;
int valor1 = 0, valor2 = 0;
void setup() {
  DDRD = 0b11111110;// A B C D E F G
  DDRC = 0b00000111; // Mostrador binario
  DDRB &= ~(1<<0); // Botão vermelho
  DDRB &= ~(1<<1); // Botão Branco "Enter"
}

void loop() {
  PORTD = disp; PORTC = mostrador;
  switch (estado){
    case 0:
      if(PINB & (1<<0)){
        valor1++;
        if(valor1 == 4){valor1 = 0;};// 0b00000111 0 6 4 + 4 
        while(PINB & (1<<0)){}
        _delay_ms(50);
      }
      if(PINB & (1<<1)){
        estado = 1;
        while(PINB & (1<<1)){}
        _delay_ms(50);
      }
      disp = numero[valor1];
      break;
     case 1:
      if(PINB & (1<<0)){
        valor2++;
        if(valor2 == 4){valor2 = 0;};
        while(PINB & (1<<0)){}
        _delay_ms(50);
      }
      disp = numero[valor2];
      if(PINB & (1<<1)){
        resultado = valor1 + valor2;
        valor1 = 0; valor2 = 0;
        estado = 2;
        while(PINB & (1<<1)){}
        _delay_ms(50);
      }
      break;
     case 2:
      disp = numero[0]; mostrador = resultado;
      if(PINB & (1<<1)){
        estado = 0; mostrador = 0;
        while(PINB & (1<<1)){}
        _delay_ms(50);
      }
      break;
  }
}
