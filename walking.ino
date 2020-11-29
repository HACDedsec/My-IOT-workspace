

const int echopin = D0;

const int trigpin = D1;

long duration;
int distance;

const int pin = D2;

const int pin2 = D3;

const int pin3 = D4;

void setup() {
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(pin, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);

Serial.begin(9600);


}

void loop() {
digitalWrite(trigpin, LOW);
delay(5);


digitalWrite(trigpin, HIGH);
delay(10);


digitalWrite(trigpin, LOW);

duration = pulseIn(echopin, HIGH);

distance = duration *0.034/2;

Serial.print("Distance is :");
Serial.println(distance);



if( distance  < 25&&distance>=20){

  digitalWrite (pin, HIGH);
  delay(1);
  }
  else if( distance  < 20&&distance>=10 )
  {
    digitalWrite (pin2, HIGH);
  delay(1);
  }
  else if( distance  < 10 )
  {
    digitalWrite (pin3, HIGH);
  delay(1);
  }
  else{
     digitalWrite (pin, LOW );
     digitalWrite (pin2, LOW );
     digitalWrite (pin3, LOW );
    }
}
