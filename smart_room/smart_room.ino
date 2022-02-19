
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "M9ymyE8dduRgbHxAylYWdUyVsJvI6sjs";
char ssid[] = "smarthome";
char pass[] = "password@001";


const int a=D2;
const int b=D3;
const int c=D0;
const int d=D1;

void setup()
{
  // Debug console
  Serial.begin(9600);

  

  Blynk.begin(auth, ssid, pass);
  


  


  digitalWrite(D0,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
 
}

void loop()
{


  Blynk.run();


}
