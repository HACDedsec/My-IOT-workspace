
#include <Servo.h>
Servo myservo; 
const int echopin = D0;
const int trigpin = D1;

const int echopin2 = D5;
const int trigpin2 = D6;

long duration;
int distance;

const int pin = D2;

const int pin2 = D3;

const int pin3 = D4;

void setup() {

   myservo.attach(7);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(pin, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);

Serial.begin(9600);


}

void loop() {
  
 int pos;
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


if( distance  < 15 )
  {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);            
  }

  }
  else{

     for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
  }   
}
  }
