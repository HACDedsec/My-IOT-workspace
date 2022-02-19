#include <ESP8266WiFi.h>
#include <Servo.h>


 Servo s1;
float temp; 
float tempPin = A0;   
       
int fanSpeed = 0;
 

void setup()
{

  s1.attach(8);

 pinMode(tempPin, INPUT);
 Serial.begin(9600);
  
  
}
void loop() {
int analogValue = analogRead(A0);
float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
float celsius = millivolts/10;
Serial.print("in DegreeC=   ");
Serial.println(celsius);
 temp = analogRead(tempPin);
 temp = (temp *5.0*100.0)/1024.0; 

 
 Serial.println(temp);
 delay(1000);
}
