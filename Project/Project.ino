#define BLYNK_PRINT Serial
const int ledPin = 10;  //LDR
const int ldrPin = A0;  //LDR


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "alTioj-akM4lhhFrBdeHwAIdlo3RpkHu";
char ssid[] = "zuk";
char pass[] = "divine@321";

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  //LDR
  pinMode(ldrPin, INPUT);  //LDR
  Blynk.begin(auth, ssid, pass);}
void loop()
{
  Blynk.run();
  int ldrStatus = analogRead(ldrPin);  //LDR
if (ldrStatus <=300) {  //LDR
digitalWrite(ledPin, LOW);  //LDR
}
else {
digitalWrite(ledPin, HIGH);  //LDR
}
}
