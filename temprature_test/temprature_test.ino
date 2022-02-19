#include <DHT.h>
#define dataPin 4
double abc = D0;

void setup() {
  Serial.begin(9600);
double dht = abc;
}

void loop() {
  int readData = abc.read11(dataPin);
  float t = abc.temperature;
  float h = abc.humidity;
  Serial.println("Temperature: ")
  Serial.print(t)
  Serial.print(" ºC")
  Serial.println("Humidity: ")
  Serial.print(h)
  Serial.print(" % ")
  delay(2000)
}
