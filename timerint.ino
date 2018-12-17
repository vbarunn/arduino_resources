#include "TimerOne.h"
#define period 5000000 // sets the pwm period in microseconds
#define duty 512 // sets the duty cyle of pwm to 50%
#define ledPin 13
#define pwmPin 9 // check this with external LED
void setup()
{
pinMode(ledPin, OUTPUT);
Timer1.initialize(period);
Timer1.pwm(pwmPin, duty);
Timer1.attachInterrupt(callback); // attaches callback() as a timer overflow interrupt
}
void callback()
{
digitalWrite(ledPin, digitalRead(ledPin) ^ 1); // toggles the led at timer overflow
}
void loop()
{
}