int azul = 8;
int vermelho = 9;
int botao = 2;
int velocidade;
int duracao;

void setup(){
  pinMode(azul,OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(botao,INPUT_PULLUP);
}

void loop(){
  velocidade = 0;
  if (botao == 1){
    velocidade++;
  }
  if (velocidade > 1){
    velocidade = 0;
  }
  if (velocidade == 0){
    duracao = 500;
  }
  if (velocidade == 1){
    duracao = 250;
  }
  digitalWrite(azul,HIGH);
  digitalWrite(vermelho,LOW);
  delay(duracao);

  digitalWrite(vermelho,HIGH);
  digitalWrite(azul,LOW);
  delay(duracao);
}
