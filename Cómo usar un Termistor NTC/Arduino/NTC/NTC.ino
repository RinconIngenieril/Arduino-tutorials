/*
 * Tutorial: Cómo usar un termistor NTC
 * Web: https://www.rinconingenieril.es/como-usar-un-termistor-ntc/
 * 
 * agosto 2017
 * 
 * Enrique, RincónIngenieril 
 */

#include <math.h>

//Valores fijos del circuito
float rAux = 10000.0;
float vcc = 5.0;
float beta = 3977.0;
float temp0 = 298.0;
float r0 = 10000.0;

//Variables usadas en el cálculo
float vm = 0.0;
float rntc = 0.0;
float temperaturaK = 0.0;


void setup() {
  Serial.begin(9600); 
}

void loop() {

  //Bloque de cálculo
  vm=(vcc / 1024)*( analogRead(0) );                //Calcular tensión en la entrada
  rntc = rAux / ((vcc/vm)-1);                       //Calcular la resistencia de la NTC
  temperaturaK = beta/(log(rntc/r0)+(beta/temp0));  //Calcular la temperatura en Kelvin

  //Restar 273 para pasar a grados celsus
  Serial.println(temperaturaK - 273);
  
  delay(1000); 
}
