// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
float volt = 228.0;

void setup()
{  
  Serial.begin(9600);
  
  emon1.current(1, 60.6);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only 1480

 if (Irms >= 2.75)
 {
   volt = 220.0;
 } else if (Irms >= 2.9)
 {
   volt = 218.0;
 } else if (Irms >= 4.5)
 {
   volt = 217.0;
 } else if (Irms >= 5.5)
 {
   volt = 215.0;
 } else
 {
   volt = 225.0;
 }
 
 
 
 
  
  Serial.print("Watt: ");
  Serial.print(Irms*218.0);	       // Apparent power
  Serial.print("   A: ");
  Serial.println(Irms);		       // Irms
  Serial.print("Volt: ");
  Serial.print(volt);
}
