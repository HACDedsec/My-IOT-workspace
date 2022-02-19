#define BLYNK_PRINT Serial
#include <Servo.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "1efb1a7ef7034ee2a580527dbb340d7b";


char ssid[] = "OOB-IT";
char pass[] = "blackhole";
char ssid1[] = "Divine2.";
char pass1[] = "divine@1234";


int buzzer = 1;
int smokeA0 = A0;

int sensorThres = 400;

void setup() {
  
   Serial.begin(9600);
Blynk.begin(auth, ssid1, pass1);
  Blynk.begin(auth, ssid, pass);
    
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);

  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
   Blynk.run();
}
