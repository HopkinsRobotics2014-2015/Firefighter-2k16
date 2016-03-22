
#ifndef TheLibrary_h
#define TheLibrary_h

#include "Arduino.h"



class pvec3f
{
  public:
  float x, y, angle;
  pvec3f();
  pvec3f(float _x, float _y, float _angle);
  pvec3f get();
  float getX();
  float getY();
  float getAngle();
  void setX(float _x);
  void setY(float _y);
  void setAngle(float _angle);
  void add(pvec3f v);
  void subtract(pvec3f v);
  float dot(pvec3f v);
  float magnitudeSquared();
  float magnitude();
  void operator = (pvec3f v);
  void operator -> (void);
};

class motor
{
  public:
    int pin;
    int fullFs;
    int fullSs;
    int fullRs;
    int halfFs;
    int halfRs;
    int quarterFs;
    int quarterRs;
    motor();
    void fullF();
    void fullS();
    void fullR();
    void halfF();
    void halfR();
    void quarterF();
    void quarterR();
    void operator = (motor v);
    motor get();
};






class checkpoint
{
  public:
    float x;
    float y;
    //checkpoint[4] neigbhors;
    checkpoint(float _x, float _y);
    checkpoint();
    void operator = (checkpoint penis);
    void operator = (checkpoint* penis);
};




class ultrasonic
{
  public:
    int pinE;
    int pinT;
    long myRead;
    long takeRead();
    ultrasonic();
    void operator = (ultrasonic v);
    ultrasonic get(void);
};

#endif
