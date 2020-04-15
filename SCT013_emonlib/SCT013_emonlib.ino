// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
EnergyMonitor emon2;
float volt = 228.0;

void setup()
{  
  Serial.begin(9600);
  
  emon1.current(2,45.5);             // Current: input pin, calibration.
  emon2.current(4, 59.5);
}

void loop()
{
  double Irms1 = emon1.calcIrms(1480);  // Calculate Irms only 1480
  double Irms2 = emon2.calcIrms(1480);
 if (Irms1 >= 2.75 || Irms2 >= 2.75)
 {
   volt = 220.0;
 } 
 if (Irms1 >= 2.9 || Irms2 >= 2.9)
 {
   volt = 218.0;
 } 
 if (Irms1 >= 4.5 || Irms2 >= 4.5)
 {
   volt = 217.0;
 } 
 if (Irms1 >= 5.5 || Irms2 >= 5.5)
 {
   volt = 215.0;
 }
 if (Irms1 >= 7.0 || Irms2 >= 7.0)
 {
  volt = 209.0; 
 }
 
 emon1.serialprint();
 emon2.serialprint();
 
 
//  Serial.println("");
//  Serial.print("Watt 1: ");
//  Serial.print(Irms1*volt);	       // Apparent power
//  Serial.print("    ");
//  Serial.print("Amp: ");
//  Serial.println(Irms1);		       // Irms
//
//  Serial.print("Watt 2: ");                     
//  Serial.print(Irms2*volt);
//  Serial.print("    ");
//  Serial.print("Amp: ");
//  Serial.print(Irms2);
}
