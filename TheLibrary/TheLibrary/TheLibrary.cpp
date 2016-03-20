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
    analogWrite((*this).pin,(*this).fullFs);
  }
void motor:: fullS()
  {
    pinMode(pin, OUTPUT);
    analogWrite((*this).pin,(*this).fullSs);
  }
void motor:: fullR()
  {
    pinMode(pin, OUTPUT);
    analogWrite(this->pin,this  -> fullRs);
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

float ultrasonic::takeRead() {
  digitalWrite(this -> pin, LOW);
  delay(2);
  digitalWrite(this -> pin, HIGH);
  delay(5);
  digitalWrite(this -> pin, LOW);
  pinMode (this -> pin, INPUT);
  digitalWrite(this-> pin, HIGH);
  float theRead;
  theRead = pulseIn(this->pin, HIGH) / 58.138;
  digitalWrite(this->pin, LOW);
  myRead = theRead;
  return theRead; //in
  }
ultrasonic ultrasonic:: get()
{
  ultrasonic *r = new ultrasonic();
  (*r).pin = pin;
  (*r).myRead = myRead;
  return *r;
}
void ultrasonic:: operator=(ultrasonic r)
{
  pin = r.pin;
  myRead = r.myRead;
}










