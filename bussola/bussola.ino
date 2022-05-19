#include <Wire.h> //Biblioteca de Comunicacao I2C 
#include "MechaQMC5883.h" //Biblioteca do Sensor QMC5883 - Modulo GY-273

 

 
MechaQMC5883 bussola; //Criacao do objeto para o sensor 
 
int x = 0, y = 0, z = 0;
int angulo = 0;
 
void setup()
{
  
  Wire.begin(); //Inicializacao da Comunicacao I2C
  Serial.begin(9600); //Inicializacao da comunicacao Serial
  
  bussola.init(); //Inicializando o Sensor QMC5883
}
 
void loop() 
{ 
  bussola.read(&x,&y,&z); //Obter o valor dos eixos X, Y e Z do Sensor
  Serial.println(String(x/8)+"\t"+String(y/8)+"\t"+String(z/8));
//  angulo = atan2(x, y)/0.0174532925; //Calculo do angulo usando os eixos X e Y atraves da formula
// 
//  //lcd.clear();
//  
//  //Ajuste do angulo entre 0 e 360 graus
//  if(angulo < 0) 
//  angulo+=360;
//  
//  angulo = 360-angulo;
// 
//  //lcd.setCursor(0,0);
//  //lcd.print("Direcao:");
// 
//  //lcd.setCursor(0,1);
//  
//  Serial.println(angulo); //Imprime o valor do angulo na Serial do Arduino
// 
//  //Apresentando o sentido com base no angulo encontrado
//  if (angulo > 338 || angulo < 22)
//  {
//    Serial.println("Norte");
//    //lcd.print("Norte");
//  }
//  if (angulo > 22 && angulo < 68)
//  {
//    Serial.println("Nordeste");
//    //lcd.print("Nordeste");
//  }
//  if (angulo > 68 && angulo < 113)
//  {
//    Serial.println("Leste");
//    //lcd.print("Leste");
//  }
//  if (angulo > 113 && angulo < 158)
//  {
//    Serial.println("Suldeste");
//    //lcd.print("Suldeste");
//  }
//  if (angulo > 158 && angulo < 203)
//  {
//    Serial.println("Sul");
//    //lcd.print("Sul");
//  }
//  if (angulo > 203 && angulo < 248)
//  {
//    Serial.println("Suldoste");
//    //lcd.print("Suldoeste");
//  }
//  if (angulo > 248 && angulo < 293)
//  {
//    Serial.println("Oeste");
//    //lcd.print("Oeste");
//  }
//  if (angulo > 293 && angulo < 338)
//  {
//    Serial.println("Noroeste");
//    //lcd.print("Noroeste");
//  }
 
  delay(500); //Delay de 500 ms entre novas leituras
}
