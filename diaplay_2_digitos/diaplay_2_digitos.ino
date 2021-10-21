/*
Rodrigo Matos
Contatos de 00 a 99:
  Na linguagem Arduino tem o pinMode(pino, estado_do_pino) onde só podemos declarar o estado de um pino de cada vez.
  Na linguagem C podemos usar os registradores DDRx do ATmega328p, onde podemos declarar todos os pinos do registrador com apenas um unico comando.
    Para registrar os estados de entrada e saída do microcontrolador podemos utilizar os registradores de estado DDRD, DDRB e DDRC.
      Onde o DDRD é responsavel por registrar o estado de cada um dos pinos de 0 a 7.
      O DDRB registra o estado dos pinos de 8 a 13
      E O DDRC registra o estado dos pinos A0 a A6 (o Arduino pro-mini possui até o pino A7)

  Na linguagem arduino tem o comando digitelWrite(pino, estado_do_pino) onde só podemos ligar os desligar um pino de cada vez.
  Na linguagem C podemos usar os registradores PORTx do ATmega328p, onde podemos declarar todos os pinos do registrador com apenas um unico comando.
    Para ligar ou desligar uma saida digital do microcontrolador, podemos usar os registradores PORTD, PORTB e PORTC.
      Os registradores são responsaveis pelos mesmos pinos de acordo com a ultima letra de cada registrador.

  Para informar o estado ou se está ligado ou desligado de cada pino para o registrador, podemos usar binários (0b), hexadecimais (0x) ou decimais.
    Cada bit coresponde a um pino do registrador
                PORTD                   PORTB                     PORTC
      pinos 7 6 5 4 3 2 1 0         13 12 11 10 9 8           A5 A4 A3 A2 A1 A0
      bits  1 1 1 1 1 1 1 1     0 0 1  1  1  1  1 1      0 0  1  1  1  1  1  1

      para informar que estamos usando um número em binário, utilizamos 0b no inicio do número.
  Cada segimento do Display é representado por uma letra
        ___
      F| A |B
       |___|
      E| G |C
       |___|
         D  .dp
    Minha dica é que conecte os segimentos em ordem, em apenas um registrador, para facilitar na programação:
      segimento 1 1 1 1 1 1 1 1
      PORTD     A B C D E F G dp

      Os pinos 0 e 1 do PORTD são o RX e TX, para evitar problemas, desconectis os pinos durante a gravação do programa.

    Para um displey com de apenas um dígito, conecte o Catodo comum no GND, mas para display com mais de um digito, conecte cada catodo em um pino de um outro registrador.
      catodo          4  3  2 1    para 4 digitos
      PORTB     13 12 11 10 9 8

      O código a seguir é para display com 2 dígitos
*/
byte numero[10] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11100110};
byte digito[2] = {0b00000010, 0b00000001}; //O bit que que estiver em 0 indica o dígito a ser exbido por ter 0V na saída, o bit que estiver em 1 tem 5V na saída e por isso não tem diferença de potencial para fechar o circuito
int n1 = 0, n2 = 0;
void setup() {
  DDRD = 0b11111111; //Define todos os bits como saída
  DDRB = 0b00000011; //Define os bits 0 e 1 como saída
  PORTB = 0b11111100;//Ativa os resistores de pullup internos para as portas que não serão usadas
}

void loop() {
   for(int i = 0; i<+250;i++){//como os comandos dentro do for consomem 4 ms o for tem 250 iterações para durar 1 segundo
    PORTD = numero[n1]; PORTB = digito[0];//Exibe apenas o dígito 1
    _delay_ms(2);
    PORTD = numero[n2]; PORTB = digito[1];//Exibe apenas o dígito 2
    _delay_ms(2);
    }
    n1++;//soma 1 ao valor de n1
    if(n1>9){//verifica se o n1 é maior q 9
      n1 = 0;//zera o valor de n1
      n2++;//soma 1 a n2
    }
    if(n2>9){//se o valor de n2 for maior que 9
      n2 = 0;//zera n2
    }
}
