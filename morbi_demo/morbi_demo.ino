

/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "dxOt-YRQJJy3lS9MRjFfPM6eIRgN0nc1";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "maharaja granite";
char pass[] = "Rajaghera@2323";



const int a = D0;
const int b = D1;
const int c = D2;
const int d = D3;
const int e = D4;
const int f = D5;
const int g = D6;
const int h = D7;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);


digitalWrite(D0, HIGH);
digitalWrite(D1, HIGH);
digitalWrite(D2, HIGH);
digitalWrite(D3, HIGH);
digitalWrite(D4, HIGH);
digitalWrite(D5, HIGH);
digitalWrite(D6, HIGH);
digitalWrite(D7, HIGH);



  
}

void loop()
{
  Blynk.run();
}
