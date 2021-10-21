#define set_bit(reg,bit_x) (reg|=(1<<bit_x))
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
double ler_lux(){
  double  Raux = 10000.0,                         //Resistor superior
          Vadc = 0.0,                             //Tensão lida pelo ADC
          R = 0.0;                             //Resistencia do NTC
  float leitura = lerAnalog(0);// lerAnalog(A0);
  Vadc = (leitura*5.0)/1023.0;
  R = (Raux*Vadc)/(5.0-Vadc);;
  double LDR = (255.84*pow(R,-10/9));
  return LDR;
}
void setup() {
  ADCSRA = 0b10000111; // Enable ADC, prescaler = 128
  Serial.begin(9600);
}
void loop() {
  double LDR = ler_lux();
  Serial.print(LDR);Serial.println("  lm/m²");
  _delay_ms(500);

}
