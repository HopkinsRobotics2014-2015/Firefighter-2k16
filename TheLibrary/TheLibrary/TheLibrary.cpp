#include "Arduino.h"
#include "TheLibrary.h"

pvec3f:: pvec3f(float _x, float _y, float _angle) {
      x = _x;
      y = _y;
      angle = _angle;
    }
pvec3f:: pvec3f()
    {
      x = 0;
      y = 0;
      angle = 0;
    }
float pvec3f:: getX() {
      return x;
    }
float pvec3f:: getY() {
      return y;
    }
float pvec3f:: getAngle() {
      return angle;
    }
void pvec3f:: setX(float _x) {
      x = _x;
    }
void pvec3f:: setY(float _y) {
      y = _y;
    }
void pvec3f::setAngle(float _angle) {
      angle = _angle;
    }
void pvec3f:: add(pvec3f v) {
      x += v.getX();
      y += v.getY();
      angle += v.getAngle();
    }
void pvec3f::subtract(pvec3f v) {
      x -= v.getX();
      y -= v.getY();
      angle -= v.getAngle();
    }
float pvec3f:: dot(pvec3f v) {
      return x*v.getX() + y * v.getY();
    }
float pvec3f:: magnitudeSquared() {
      return x * x + y * y;
    }
float pvec3f:: magnitude() {
      return sqrt(magnitudeSquared());
    }
pvec3f pvec3f:: get(){
  pvec3f *ret = new pvec3f(x,y,angle);
  return *ret;
}
void pvec3f::operator = (pvec3f v) {
      x = (v.get()).getX();
      y = (v.get()).getY();
      angle = (v.get()).getAngle();
    }
motor::motor()
  {
    return;
  }
void motor::fullF()
  {
    pinMode(pin, OUTPUT);
    analogWrite(pin, fullFs);
  }
void motor:: fullS()
  {
    pinMode(pin, OUTPUT);
    analogWrite(pin, fullSs);
  }
void motor:: fullR()
  {
    pinMode(pin, OUTPUT);
    analogWrite(pin , fullRs);
  }
void motor:: halfF()
{
  pinMode(pin,OUTPUT);
  analogWrite(pin, halfFs);
}
void motor:: halfR()
{
  pinMode(pin,OUTPUT);
  analogWrite(pin, halfRs);
}
void motor:: quarterF()
{
  pinMode(pin,OUTPUT);
  analogWrite(pin, quarterFs);
}
void motor:: quarterR()
{
  pinMode(pin,OUTPUT);
  analogWrite(pin, quarterRs);
}
motor motor:: get(){
  motor *r = new motor();
  (*r).pin = pin;
  (*r).fullFs = fullFs;
  (*r).fullSs = fullSs;
  (*r).fullRs = fullRs;
  return *r;
}
void motor::operator = (motor v) {
    pin = (v.get()).pin;
    fullFs = (v.get()).fullFs;
    fullSs = (v.get()).fullSs;
    fullRs = (v.get()).fullRs;
}

checkpoint::checkpoint(float _x, float _y)
{
   x = _x;
   y = _y;
}
checkpoint::checkpoint()
{
  x=0;
  y=0;
}
void checkpoint:: operator = (checkpoint penis)
{
  x = penis.x;
  y = penis.y;
}
void checkpoint:: operator = (checkpoint* penis)
{
  *this = *penis;
  return;
}
ultrasonic::ultrasonic()
{
  return;
}

long ultrasonic::takeRead() {
  //pinMode(pinT, OUTPUT);
  //pinMode(pinE,INPUT);
  digitalWrite(pinT, LOW);
  delayMicroseconds(2);
  digitalWrite(pinT, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinT, LOW);
  long theRead;
  theRead = pulseIn(pinE, HIGH);
  theRead = theRead/58.138;
  myRead = theRead;
  return theRead; //in
  }
ultrasonic ultrasonic:: get()
{
  ultrasonic *r = new ultrasonic();
  (*r).pinE = pinE;
  (*r).pinT = pinT;
  (*r).myRead = myRead;
  return *r;
}
void ultrasonic:: operator=(ultrasonic r)
{
  pinE = r.pinE;
  pinT = r.pinT;
  myRead = r.myRead;
}










