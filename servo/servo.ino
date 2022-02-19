#include <Servo.h>

Servo servo_9;

void setup()
{
  servo_9.attach(D0);

}

void loop()
{
  servo_9.write(180);
 
}
