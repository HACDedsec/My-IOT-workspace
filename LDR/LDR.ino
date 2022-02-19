const int ledPin = 10;

const int ldrPin = 0;

void setup() {

Serial.begin(38400);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);

if (ldrStatus <=300) {

digitalWrite(ledPin, HIGH);

Serial.println("LDR is DARK, LED is ON");

}

else {

digitalWrite(ledPin, LOW);

Serial.println("---------------");

}

}
