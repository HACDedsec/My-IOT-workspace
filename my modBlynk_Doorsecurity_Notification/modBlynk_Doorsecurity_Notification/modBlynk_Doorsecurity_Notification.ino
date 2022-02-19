//Viral Science www.youtube.com/c/viralscience  www.viralsciencecreativity.com
//Blynk Door Security Notification System

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "LXQGU8gbTAHabnoDWc1apgt7fd1MjlPq"; //Enter the authentication code sent by Blynk to your Email
char ssid[] = "Khusali plastic"; //Enter your WIFI SSID
char pass[] = "Kevin@123"; //Enter your WIFI Password
int flag=0;

const int buzzerPin =D3;
boolean buzzer_mode = false;

void notifyOnButtonPress()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1 && flag==0) {
 digitalWrite (D2, LOW);
  flag=0;
    
  }
  else if (isButtonPressed==0)
  {
    Serial.println("Someone Opened the door");
    Blynk.notify("Alert : Someone Opened the door");
    digitalWrite (D2, HIGH);
    
    flag=1;
    
  }
}




void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(D1,INPUT_PULLUP);
pinMode(D2, OUTPUT);
timer.setInterval(16000L,notifyOnButtonPress); 

 pinMode(buzzerPin,OUTPUT);
}





void loop()
{
   int isButtonPressed = digitalRead(D1);
 if (isButtonPressed==1 && flag==0){
  tone(buzzerPin,1000);
  delay(3000);
   noTone(buzzerPin); }
   
  Blynk.run();
  timer.run();
}
