//Viral Science www.youtube.com/c/viralscience  www.viralsciencecreativity.com
//Blynk Door Security Notification System

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "9l4zi5ZYC0jQqwhdvWRi384fdE_7N955"; //Enter the authentication code sent by Blynk to your Email
char ssid[] = "smarthome"; //Enter your WIFI SSID
char pass[] = "password@001"; //Enter your WIFI Password
int flag=0;



void notifyOnButtonPress()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Someone Opened the door");
    Blynk.notify("Alert : Someone Opened the door");
    flag=1;
  }
  else if (isButtonPressed==0)
  {
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(D1,INPUT_PULLUP);
timer.setInterval(16000L,notifyOnButtonPress); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
