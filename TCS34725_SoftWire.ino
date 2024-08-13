/*
Exemplo de teste da biblioteca SoftWire com a biblioteca TCS34725.h para arduino UNO e NANO
Criado por Julio Cesar Goldner Vendramini
Utilizando pinos digitais para emulação de SDA e SCL
Com esta biblioteca é possível utilizar qualquer pino digital 
para emulação de SDA e SCL para utilizar com o sensor TCS34725
*/

#include "SoftWire.h"
#include "TCS34725.h"

//defina os pinos para utilizar como SDA e SCL para cada sensor
#define SDApin 2
#define SCLpin 3
#define SCLpin2 4
#define SDApin2 5

//declare os sensores escolhendo o tempo de integração e ganho
TCS34725 tcs = TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);
TCS34725 tcs2 = TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X);

//essas variáveis servem para verificar se o sensor foi encontrado
bool sensor1 = false;
bool sensor2 = false;


void setup(void) {
  Serial.begin(9600);
  //declaração do primeiro sensor  
  if (tcs.begin(0x29, SDApin, SCLpin)) {
    Serial.println("Found sensor");
    sensor1=true;
  } else {
    Serial.println("No TCS34725 found ... check your connections");
  }

  //declaração do segundo sensor
  if (tcs2.begin(0x29, SDApin2, SCLpin2)) {
    Serial.println("Found sensor");
    sensor2=true;
  } else {
    Serial.println("No TCS34725 found ... check your connections");
  }

  
}
uint16_t r, g, b, c;
void loop(void) {
  
  if(sensor1){
    tcs.getRawData(&r, &g, &b, &c);
    Serial.println("SENSOR1!!!!!!!!!!!!!!!!!!!!");
    Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
    Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
    Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
    Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  }
  if(sensor2){
    tcs2.getRawData(&r, &g, &b, &c);
    Serial.println("SENSOR2!!!!!!!!!!!!!!!!!!!!");
    Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
    Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
    Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
    Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  }
}