
#include <Servo.h>

Servo servo_9;

const int trigger1 = D5; //Trigger pin of 1st Sesnor
const int echo1 = D6;
const int echopin = D0;

const int trigpin = D1;

long duration;
int distance;
int distance2;

const int pin = D2;

const int pin2 = D3;

const int pin3 = D4;

void setup() {

    servo_9.attach(D7);
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
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


// 2nd ul

digitalWrite(trigger1, LOW);
delay(5);


digitalWrite(trigger1, HIGH);
delay(10);


digitalWrite(trigger1, LOW);

duration = pulseIn(echo1, HIGH);

distance2 = duration *0.034/2;

Serial.print("Distance of cap is :");
Serial.println(distance2);
  s
 if( distance > 40 )
  {
 servo_9.write(90);
    
  }
else {


servo_9.write(00);
}

// light ul

if( distance2  < 17&&distance2>=16){

  digitalWrite (pin, HIGH);
  delay(1);
  }
  
  else if( distance2  < 12&&distance2>=11 )
  {
    digitalWrite (pin2, HIGH);
  delay(1);
  }
  else if( distance2  < 7 )
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
