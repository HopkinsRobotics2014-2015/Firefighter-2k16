

//We need pins for the motors

//Handles the actual navigation, not including position checking

public class pvec3f
{
  private:
    float x, y, angle;
  public:
   pvec3f(float _x = 0, float _y = 0, float _angle = 0) {
      x = _x;
      y = _y;
      angle = _angle;
    }
    pvec3f()
    {
      x = 0;
      y = 0;
      angle = 0;
    }

    //Gets a copy of the vector
   pvec3f * get() {
     pvec3f * ret = newpvec3f(x, y);
      return ret;
    }

    float getX() {
      return x;
    }
    float getY() {
      return y;
    }
    float getAngle() {
      return angle;
    }
    void setX(float _x) {
      x = _x;
    }
    void setY(float _y) {
      y = _y;
    }
    void setAngle(float _angle) {
      angle = _angle;
    }

    //Adds v to the current vector
    void add(Vec3f * v) {
      x += v->getX();
      y += v->getY();
      angle += v->getAngle();
    }
    //Sets this = this - v
    void subtract(Vec3f * v) {
      x -= v->getX();
      y -= v->getY();
      angle -= v->getAngle();
    }

    //Returns the dot product
    float dot(Vec3f * v) {
      return x * v->getX() + y * v->getY();
    }

    //Getting the magnitude squared is faster since there is no need
    //to take a square root
    float magnitudeSquared() {
      return x * x + y * y;
    }

    float magnitude() {
      return sqrt(magnitudeSquared());
    }

    void operator=(Vec3f * v) {
      x = v->getX();
      y = v->getY();
      angle = v->getAngle();
    }

};

//Serves as walls for the map
class Line
{
  private:
   pvec3f * start;
   pvec3f * end;
  public:
    Line(Vec3f _start,pvec3f _end) {
      start = newpvec3f(0, 0);
      end = newpvec3f(0, 0);
      start = _start.get();
      end = _end.get();
    }

   pvec3f * getStart() {
      return start;
    }
   pvec3f * getEnd() {
      return end;
    }

    void setStart(Vec3f * v) {
      start = v->get();
    }

    void setEnd(Vec3f * v) {
      end = v->get();
    }

    //Returns whether the two line collide
    bool collides(Line l) {
     pvec3f * deltaStart = l.getStart()->get();
      deltaStart->subtract(start);
     pvec3f * deltaEnd = l.getEnd()->get();
      deltaEnd->subtract(end);
      return (deltaStart->getX() * deltaEnd->getX() < 0) &&
             (deltaStart->getY() * deltaEnd->getY() < 0);
    }
};

Vec3f turnAround()
{
  float apple = turn(PI);
  if (apple < PI)
  {
    Move(-1.5);
    float kiwi = turn(PI);
    if(kiwi < PI)
    {
    turn(-kiwi);
    Move(-5);
    float peach = turn(PI);
    Move(-5);
    turn(-apple);
    }
    else
    {
      Move(-1.5);
      turn(-(apple));
    }
  }
}

Vec3f attempt(Vec3f moveToAttempt)
{
  float anAngle = atan(moveToAttempt.y/moveToAttempt.x);
}

//3d move

//Rabbot, i'm gonna leave how you want to call this function to you, but here is a function that asks for scan for fire and then figures out how much the robot needs to turn to
//face the fire



void fireTime() {
  // this intializes the sensors in terms of degrees.
  //until we know if the robot can rotate fully in one room, I am coding for five fire sensors so that rotation wont be an issue with this configuration
  int fireSensor1 = 0;
  int fireSensor2 = 0;
  int fireSensor3 = PI / 2;
  int fireSensor4 = PI;
  int fireSensor5 = -PI / 2;
  if (searchForFire()) {
    int Sensor = fireHere();
    for (int i = 1; i < 6; i++) {
      if (fireSensor[i] == Sensor) {
        float Sensor = fireSensor[i];
      }
    }
    //HERE IS WHERE WE ROTATE THE ROBOT TO THE FLAME. NEED TO FIGURE OUT IF WE ARE DOING THIS WITH TWO MICE, ULTRASONICS, OR PRE-DETERMINED ROTATION VALUES
    Turn (-Sensor);
  }
  sprayAndPray();
}

//This function has the robot slowly approach the flame while blowing the fan.

void sprayAndPray() {
  while (flameSensorRead(0)) {
    //IM OFFLINE RN BUT FIND FAN COMMAND. RUN FAN AT MAX
    pinMode(motorPin, OUTPUT);
    analogWrite(motorPin, 210);
  }
  analogWrite(motorPin, 191);
  returnHome();
}

//This will direct the robot back to the start after the flame has been put out
void returnHome() {

}
