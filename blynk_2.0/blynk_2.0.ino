#define BLYNK_TEMPLATE_ID "TMPLPFq8dyTI"
#define BLYNK_DEVICE_NAME "Home"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD

#include "BlynkEdgent.h"


BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  digitalWrite(D0,!pinValue);
  
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  digitalWrite(D1,!pinValue);
  
}
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  digitalWrite(D2,!pinValue);
  
}
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  digitalWrite(D4,!pinValue);
  
}

const int a = D0;
const int b = D1;
const int c = D2;
const int d = D4;


void setup()
{

  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D4,OUTPUT);


  
digitalWrite(D0, HIGH);
digitalWrite(D1, HIGH);
digitalWrite(D2, HIGH);
digitalWrite(D4, HIGH);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
