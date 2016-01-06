//We need pins for the motors

//Handles the actual navigation, not including position checking

class Vec2f
{
  private:
    float x, y;
  public:
    Vec2f(float _x, float _y){
      x = _x;
      y = _y;
    }
    
    //Gets a copy of the vector
    Vec2f * get(){
      Vec2f * ret = new Vec2f(x,y);
      return ret;
    }
    
    float getX(){
      return x;
    }
    float getY(){
      return y;
    }
    void setX(float _x){
      x = _x;
    }
    void setY(float _y){
      y = _y;
    }
    
    //Adds v to the current vector
    void add(Vec2f * v){
      x += v->getX();
      y += v->getY();
    }
    //Sets this = this - v
    void subtract(Vec2f * v){
      x -= v->getX();
      y -= v->getY();
    }
    
    //Returns the dot product
    float dot(Vec2f * v){
      return x * v->getX() + y * v->getY();
    }
    
    //Getting the magnitude squared is faster since there is no need
    //to take a square root
    float magnitudeSquared(){
      return x * x + y * y;
    }
    
    float magnitude(){
      return sqrt(magnitudeSquared());
    }
    
    void operator=(Vec2f * v){
      
    }
    
};

//Serves as walls for the map
class Line
{
  private:
    Vec2f * start, end;
  public:
    Line(Vec2f _start, Vec2f _end){
      start = new Vec2f(0,0);
      end = new Vec2f(0,0);
      start = _start.get();
      end = _end.get();
    }
    
    Vec2f * getStart(){
      return start;
    }
    Vec2f * getEnd(){
      return end;
    }
    
    void setStart(Vec2f * v){
      start = v->get();
    }
        
    void setEnd(Vec2f * v){
      end = v->get();
    }
    
    //Returns whether the two line collide
    bool collides(Line l){
      Vec2f * deltaStart = l.getStart()->get();
      deltaStart->subtract(start);
      Vec2f * deltaEnd = l.getEnd()->get();
      deltaEnd->subtract(end);
      return (deltaStart->getX() * deltaEnd->getX() < 0) &&
             (deltaStart->getY() * deltaEnd->getY() < 0);
    }
};



//Rabbot, i'm gonna leave how you want to call this function to you, but here is a function that asks for scan for fire and then figures out how much the robot needs to turn to
//face the fire



void fireTime() {
// this intializes the sensors in terms of degrees.
//until we know if the robot can rotate fully in one room, I am coding for five fire sensors so that rotation wont be an issue with this configuration
  int fireSensor1 = 0;
  int fireSensor2 = 0;
  int fireSensor3 = PI/2;
  int fireSensor4 = PI;
  int fireSensor5 = -PI/2;
if (searchForFire()) {
 int Sensor = fireHere();
 for (int i = 1; i < 6; i++){
  if (fireSensor[i] == Sensor){
    float Sensor = fireSensor[i];
  }
 }
 //HERE IS WHERE WE ROTATE THE ROBOT TO THE FLAME. NEED TO FIGURE OUT IF WE ARE DOING THIS WITH TWO MICE, ULTRASONICS, OR PRE-DETERMINED ROTATION VALUES
 Turn (-Sensor)
}
sprayAndPray()
}

//This function has the robot slowly approach the flame while blowing the fan.

void sprayAndPray() {
while (flameSensorRead(0)) {
  //IM OFFLINE RN BUT FIND FAN COMMAND. RUN FAN AT MAX
pinMode(motorPin,OUTPUT);
analogWrite(motorPin,210);
}
analogWrite(motorPin,191);
returnHome();
}

//This will direct the robot back to the start after the flame has been put out
void returnHome(){
  
}
