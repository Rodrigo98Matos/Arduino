#define set_bit(reg,bit_x) (reg|=(1<<bit_x))
double temp[3] = {0.0, 0.0, 0.0};
bool convertido = 1;
int lerAnalog(byte pin){//pin 0 a 7
  ADMUX = 0b01000000 + pin; // tensão de referência AVCC e pin como entrada do ADC (REFS)
  if (convertido) {
    set_bit(ADCSRA,ADSC); // iniciar leitura em A0
    convertido = 0;
  }
  if (!(ADCSRA & (1<<ADSC))) {
    convertido = 1;
    return (ADC);
  }
}
void ler_temp(){
  double  Rsup = 10000.0,                         //Resistor superior
          Rd0 = 10000.0,                          //Resistencia do NTC a 25°C
          T0 = 298.15,                            //25°C em Kelvin
          T1 = 273.15,                             //Temperatura de referência 1
          T2 = 373.15,                             //Temperatura de referêcia 2
          RT1 = 35563.0,                          //Reseistência do NTC em T1
          RT2 = 549.4,                            //Resistência do NTC em T2
          beta = log(RT1/RT2)/((1/T1)-(1/T2)),    //Constante do termistor
          Rinf = Rd0*exp(-beta/T0),               //Parâmetro de resistência
          Vadc = 0.0,                             //Tensão lida pelo ADC
          Rntc = 0.0;                             //Resistencia do NTC                           

  float leitura = lerAnalog(1);// lerAnalog(A0);
  Vadc = (5.0*leitura)/1023;
  Rntc = (Rsup*Vadc)/(5.0-Vadc);
  temp[0] = beta/log(Rntc/Rinf);                  //Temperatura em Kelvin
  temp[1] = temp[0] - 273.15;                     //Remperatura em Celsius
  temp[2] = (temp[1] * 9/5) + 32;
}
void setup() {
  ADCSRA = 0b10000111; // Enable ADC, prescaler = 128
  Serial.begin(9600);
}

void loop() {
  char escala[3];
  escala[0] = "K";escala[1] = "C"; escala[2] = "F";
  ler_temp();
  for(int i = 0; i <= 2; i++){
    Serial.print(temp[i]);Serial.print("\t");
  }
  Serial.println();
  _delay_ms(500);
}
