//ArduinoJson 5.13.5

#include <WiFi.h>
#include <WiFiClient.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "esmarthome8266-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "msfEE8FalISL9ELHZNwGsohtpeeMBto2fjDbB8RN"
#define WIFI_SSID "zuk"
#define WIFI_PASSWORD "password@123"

void setup() {
  Serial.begin(9600);
  pinMode(D12,OUTPUT);
  pinMode(D13,OUTPUT);
  pinMode(D14,OUTPUT);
  pinMode(D27,OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.set("D0_STATUS",0);
  Firebase.set("D1_STATUS",0);
  Firebase.set("D2_STATUS",0);
  Firebase.set("D3_STATUS",0);

}

int p0 = 0;
int p1 = 0;
int p2 = 0;
int p3 = 0;

void loop() {
  // set value
  p0 = Firebase.getInt("D0_STATUS");
    p1 = Firebase.getInt("D1_STATUS");
      p2 = Firebase.getInt("D2_STATUS");
        p3 = Firebase.getInt("D3_STATUS");
  // handle error
  if (p0==1) {
      Serial.println("LED1 ON");
      digitalWrite(D0,LOW);  
       }
  else
  {
      Serial.println("LED1 OFF");
      digitalWrite(D0,HIGH);  
  }
  if (p1==1) {
      Serial.println("LED2 ON");
      digitalWrite(D1,LOW);  
       }
  else
  {
      Serial.println("LED2 OFF");
      digitalWrite(D1,HIGH);  
  }
  if (p2==1) {
      Serial.println("LED3 ON");
      digitalWrite(D2,LOW);  
       }
  else
  {
      Serial.println("LED3 OFF");
      digitalWrite(D2,HIGH);  
  }
  if (p3==1) {
      Serial.println("LED4 ON");
      digitalWrite(D3,LOW);  
       }
  else
  {
      Serial.println("LED4 OFF");
      digitalWrite(D3,HIGH);  
  }
  
}
