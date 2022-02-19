
#include <ESP8266WiFi.h>           // Header file for Wifi Module 
#include <BlynkSimpleEsp8266.h>  // header file for blynk 
#include <RBDdimmer.h>           // header file for robodyn dimmer

char auth[] = "M9ymyE8dduRgbHxAylYWdUyVsJvI6sjs";  // blynk auth key 

char ssid[] = "i";   // Wifi Name
char pass[] = "password@001";  // Wifi Password

#define outputPin  D2  // PWM pin for dimmer
#define zerocross  D1 // for boards with CHANGEBLE input pins

dimmerLamp dimmer(outputPin, zerocross); //initialase port for dimmer for ESP8266, ESP32, Arduino due boards

int outVal = 0; // Intialisation value for dimmer
int dim_val; // dimmer value to dim the appliance
 
void setup()
{
   
 
  Serial.begin(9600); // begin serial communication
  
   Blynk.begin(auth, ssid, pass);
 
}


BLYNK_WRITE(V0)  {  // Set to your virtual pin  
  outVal = param.asInt(); // Get State of Virtual Button
  dim_val = map(outVal, 0, 1023, 0, 100); // mapped the value for dimmer
  dimmer.setPower(dim_val);               // Set dimmer power
  Blynk.virtualWrite(V1, dim_val); //sending to Blynk
}

void loop()
{
  Blynk.run(); // Run blynk server
}
