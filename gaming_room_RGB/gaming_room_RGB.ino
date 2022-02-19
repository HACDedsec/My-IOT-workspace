
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "y_l1ARorgoB1VS0nXpjyi8skAzgCRlMq";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "smarthome";
char pass[] = "password@#1";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
