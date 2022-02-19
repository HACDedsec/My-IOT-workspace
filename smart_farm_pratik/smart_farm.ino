int sensorPin = A0; 
int sensorValue;  
int limit = 300; 

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Bfv6TNkso-3fq1JlZBQanPMuLs8ZMbP2";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "smartfarm";
char pass[] = "password@001";


const int a = D0;
void setup() {

    Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);


  
digitalWrite(D1, HIGH);
 Serial.begin(9600);
 pinMode(13, OUTPUT);
}

void loop() {

    Blynk.run();

 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 
 if (sensorValue<limit) {
 digitalWrite(13, HIGH); 
 }
 else {
 digitalWrite(13, LOW); 
 }
 
 delay(1000); 
}
