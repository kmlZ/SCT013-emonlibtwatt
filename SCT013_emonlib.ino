// Pomiar mocy pozornej

#include "EmonLib.h"                   
float volt = 228.0;

void setup()
{  
  Serial.begin(9600);
  
  emon1.current(A1, 55.0);             
}

void loop()
{
  double Irms = emon1.calcIrms(1480);

 if (Irms >= 2.75)
 {
   volt = 220.0;
 }

 if (Irms >= 2.9)
 {
   volt = 218.0;
 }

 if (Irms >= 4.5)
 {
   volt = 217.0;
 }

 if (Irms >= 5.5)
 {
   volt = 215.0;
 }

 if (Irms >= 7.5)
 {
   volt = 209;
 }

 if (Irms > 10)
 {
   volt = 207;
 }
 
 
 
 
 
 
  
  Serial.print("Watt: ");
  Serial.print(Irms*218.0);	       // Apparent power
  Serial.print("   A: ");
  Serial.println(Irms);		       // Irms
  Serial.print("Volt: ");
  Serial.print(volt);
}
