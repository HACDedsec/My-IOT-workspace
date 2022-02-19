
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "yiSh0xh9ngmkBV2C9B7dz0wNhIW8i_Mf";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "D";
char pass[] = "office@#111";





const int a = D0;
const int b = D1;
const int c = D2;
const int d = D3;
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);



  
digitalWrite(D1, HIGH);
digitalWrite(D2, HIGH);
digitalWrite(D0, HIGH);
digitalWrite(D3, HIGH);
}

void loop()
{
  Blynk.run();
}
