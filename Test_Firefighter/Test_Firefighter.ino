#include <TheLibrary.h>

//I KNOW HOW TO FIX IT







// put your setup code here, to run once:
int North = 1;
int South = 2;
int East = 3;
int West = 4;
int CW = 0;
int CCW = 1;

pvec3f currentOrientation;

motor motors[2];
float reads[6];
ultrasonic ultrasonics[6];

int U1 = 1;
int U2 = 2;
int U3 = 3;
int U4 = 4;
int leftMotor = 5;
int rightMotor = 6;

void declareMotor(int i)
{
  //motor[] motors = motors;
  motor *r = new motor();
  switch (i)
  {
    case (0):
    motors[0] = *r;
    motors[0].pin = 1;
    motors[0].fullFs = 225;
    motors[0].fullSs = 189;
    motors[0].fullRs = 157;
    CW = 0;
    break;
    
    case (1):
    motors[1] = *r;
    motors[1].fullFs = 240;
    motors[1].fullSs = 191;
    motors[1].fullRs = 130;
    motors[1].pin = 2;
    CCW = 1;
    break;
    default:
    break;
  }
}

void declareUltrasonics()
{

  for(int *i = 0; *i < 6; *i++)
  {
    ultrasonics[*i] = new ultrasonic();
    ultrasonics[*i].pin = i+1;
  }
}



void fullF()
{
  motors[*CW].fullR();
  motors[*CCW].fullF();
}
void fullS()
{
  motors[*CW].fullS();
  motors[*CCW].fulls();
}
void fullR();
{
  motors[*CW].fullF();
  motors[*CCW].fullR();
}
void fullCCW()
{
  motors[*CW].fullF();
  motors[*CCW].fullF();
}
void fullCW()
{
  motors[*CW].fullR();
  motors[*CCW].fullR();
}

void setup() {
    checkpoints = new checkpoint[17];
  checkpoints[0] = new checkpoint (23, 42);
  checkpoints[1] = new checkpoint (23, 114);
  checkpoints[2] = new checkpoint (23, 166);
  checkpoints[3] = new checkpoint (23, 221);
  checkpoints[4] = new checkpoint (97, 23);
  checkpoints[5] = new checkpoint (97, 114);
  checkpoints[6] = new checkpoint (97, 175);
  checkpoints[7] = new checkpoint (97, 221);
  checkpoints[8] = new checkpoint (143, 73);
  checkpoints[9] = new checkpoint (143, 114);
  checkpoints[10] = new checkpoint (150, 175);//(150,17);
  checkpoints[11] = new checkpoint (150, 221);//(150,22);
  checkpoints[12] = new checkpoint (169, 23);//(169,23);
  checkpoints[13] = new checkpoint (169, 73);//(169,73);
  checkpoints[14] = new checkpoint (220, 23);//(220,23);
  checkpoints[15] = new checkpoint (220, 114);//(220,11);
  checkpoints[16] = new checkpoint (220, 222);//(220,22);
  background(255);
  size(800, 600);
  visualize();
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  public motors[] = new motor[2];
  declareMotor(0);
  declareMotor(1);
  mouse_init();
  determineOrientation();
 
    
  go(1,2);
  Align();
  Move (0, 100, -90);
  Move (0, 74, -90);
  Move (0, 72, 0);
//firefight
  rotate (180);
  Move (0, 74, 90);
  Move (0, 72, -90);
  Move (0, 107, -90);
  Move (0, 74, 0);
//firefight
  rotate (180);
  Move (0, 74, 90);
  Move (0, 46, -90);
  Move (0, 53, 0);
//firefight
  Move (0, 70, 90);
  Move (0, 198, 90);
  Move (0, 51, 90);
  Move (0, 50, 0);
//firefight
  rotate (180);
  Move (0, 50, 90);
  Move (0, 72, 90);
}




void loop() {

}

void determineOrientation()
{
 int orientation;
 takeReads();
 if((10-reads[South]) < 2 && -2 < (10- reads[South]) && (10-reads[East]) < 2 && (10-reads[East]) > -2)
 {
  orientation = North;
  //minimize(East);
  Align();
  currentOrientation.angle = 0;
  currentOrientation.x = 23;
  currentOrientation.y = 42;
 }
 setNeighbors(oritentation); 
}



// change the hard coded distances to subtract using the checkponts
// figure out how to communicate with the mouse
// write out all the instructions for the robot
// Confirm location with ultrasonics




//Checkpoints Start
checkpoint[] checkpoints;




//Map One Dog 1



void link(int a, int b) {
  checkpoints[a-1].neighbors.add(checkpoints[b-1]);
  checkpoints[b-1].neighbors.add(checkpoints[a-1]);
}

//Serves as walls for the map
/*
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

    float setStart(Vec3f * v) {
      start = v->get();
    }

    float setEnd(Vec3f * v) {
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
*/
void visualize() {
  for (checkpoint cp : checkpoints) {
    ellipse(map(cp.x, 0, 244, 40, 760), map(cp.y, 0, 244, 40, 560), 20, 20);
    for (checkpoint neighbor : cp.neighbors) {
      line(map(cp.x, 0, 244, 40, 760), map(cp.y, 0, 244, 40, 560), map(neighbor.x, 0, 244, 40, 760), map(neighbor.y, 0, 244, 40, 560));
    }
  }
}
//checkpoint 1 hard way example
//THis is assuming i have the checkpoints be values and not variables
//checkpoints.get(1).neighbors.add(checkpoint.get(2));
//checkpoint 1 slightly better way using variables for checkpoints
//ex. checkpoint 1 = new checkpoint (23,42)
// Checkpoint 1 
//1.neighbors.add(2);

//Even easier way will be used in this program
//Use the link function so that you only have to say link(1,2)

//No Walls or Dog code
/*
 link(1,2);
 link(2,6);
 link(3,4);
 link(4,8);
 link(5,13);
 link(5,6);
 link(6,7);
 link(6,10);
 link(7,8);
 link(7,11);
 link(8,12);
 link(9,10);
 link(9,14);
 link(10,16);
 link(11,12);
 link(12,17);
 link(13,14);
 link(13,15);
 link(15,16);
 link(16,17);

 */

//Map One Dog 1

void setNeighbors(int map) {
  
  for (checkpoint cp : checkpoints){
    cp.neighbors.clear();
  }
  
  switch (map) {

  case 1:
  link(1,2);
  link(2,6);
  link(3,4);
  link(4,8);
  link(5,13);
  link(5,6);
  link(6,7);
  link(6,10);
  link(7,8);
  link(7,11);
  link(8,12);
  link(9,10);
  link(9,14);
  link(10,16);
  link(11,12);
  link(12,17);
  link(13,14);
  link(13,15);
  link(15,16);
  link(16,17);
  break;
  // Map One Dog 1
  case 3:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  // Map Two Dog 1
  case 4:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(8, 12);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  case 5:
    // Map 3 dog 1
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 14);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  //Map One Dog 2
  case 6:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(16, 17);
    break;
  case 7:
  //Map Two Dog 2

  link(1, 2);
  link(2, 6);
  link(3, 4);
  link(4, 8);
  link(5, 13);
  link(5, 6);
  link(6, 7);
  link(6, 10);
  link(7, 8);
  link(8, 12);
  link(9, 10);
  link(9, 14);
  link(10, 16);
  link(11, 12);
  link(12, 17);
  link(13, 15);
  link(16, 17);
  break;
  case 8: // Map 3 dog 2
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(6, 10);
    link(7, 8);
    link(7, 11);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 14);
    link(13, 15);
    link(16, 17);
    break;
  //Map One Dog 3
  case 9:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(7, 8);
    link(7, 11);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  case 10:
    // Map 2 Dog 3
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(7, 8);
    link(8, 12);
    link(9, 10);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  case 11:
    link(1, 2);
    link(2, 6);
    link(3, 4);
    link(4, 8);
    link(5, 13);
    link(5, 6);
    link(6, 7);
    link(7, 8);
    link(7, 11);
    link(9, 14);
    link(10, 16);
    link(11, 12);
    link(12, 17);
    link(13, 14);
    link(13, 15);
    link(15, 16);
    link(16, 17);
    break;
  }
}

void draw(){
  background(255);
  visualize();
}

void keyPressed(){
  if (1 <= key - '0' && key - '0' <= 9) setNeighbors(key - '0' + 2);
}

// Checkpoints Start
int distanceToAlign = 25;

void Move(float x,float y,float z)
{
  pvec3f pie = new pvec3f();
  float pie.x = x;
  float pie.y = y;
  float pie.angle = z;
  float rotation = atan(pie.y / pie.x);
  rotation -= currentOrientation.angle;
  rotate(rotation);
  float distance = pie.x * pie.x + pie.y * pie.y;
  distance = sqrt(distance);
  drive(distance);
  rotation = -(currentorientation.angle - pie.angle);
  rotate(rotation);
  //callibrate(pie);
  return;
}

void rotate(float angle)
{
  //Here is a proposition
  takeReads();
  float firstReads[ultrasonics.length] = reads
  float currentReads[ultrasonics.length] = reads;
  float startAngle = currentOrientation.angle;
  fullCW();
  //This is the second hardest program to write here
  //We need to find rotation. Take measurements on all sides
  //Begin rotation, and go either until the distance matches the distance we want or starts to decrease.
  //If it starts to decrease we align to the maximum so as to figure out the angle we have allready turned.
  //Wait there is an issue. What would happen if the distance was decreasing first.
}
/*
void callibrate(pvec3f kiwi)
{
  //This is the hardest program to write here
}
*/

//float CheckDistance (int Pin) {
//  digitalWrite(Pin, LOW);
//  delay(2);
//  digitalWrite(Pin, HIGH);
//  delay(5);
//  digitalWrite(Pin, LOW);
//  pinMode (Pin, INPUT);
//  digitalWrite(Pin, HIGH);
//  return pulseIn(Pin, HIGH) / 58.138; //in
//}

void Align () {
  //take ultrasonic readings for all ultrasonics
  bool noBack = true;
  float North = CheckDistance (U1);
  float East = CheckDistance (U2);
  float South = CheckDistance (U3);
  float West = CheckDistance (U4);
  float first = min (U1, U2);
  float second = min (first, U3);
  float Min = min (second, U4);
  if (Min == North) {
    float one = CheckDistance (U1);
    pinMode(leftMotor, OUTPUT);
    analogWrite(leftMotor, 119);
    delay(1);
    float two = CheckDistance (U1);
    while (two <= one) {
      float two = CheckDistance (U1);
      noBack = false;
    }
    analogWrite(leftMotor, 191);
    if (noBack == false) {
      float one = CheckDistance (U1);
      analogWrite(leftMotor, 240);
      delay(1);
      float two = CheckDistance (U1);
      while (two <= one) {
      float two = CheckDistance (U1);
    }
    analogWrite(leftMotor,191);
    }
  }
  if (Min == East) {
    float one = CheckDistance (U2);
    pinMode(leftMotor, OUTPUT);
    analogWrite(leftMotor, 119);
    delay(1);
    float two = CheckDistance (U2);
    while (two <= one) {
      float two = CheckDistance (U2);
      noBack = false;
    }
    analogWrite(leftMotor, 191);
    if (noBack == false) {
      float one = CheckDistance (U2);
      analogWrite(leftMotor, 240);
      delay(1);
      float two = CheckDistance (U2);
      while (two <= one) {
      float two = CheckDistance (U2);
    }
    analogWrite(leftMotor,191);
    }
  }
  if (Min == South) {
    float one = CheckDistance (U3);
    pinMode(leftMotor, OUTPUT);
    analogWrite(leftMotor, 119);
    delay(1);
    float two = CheckDistance (U3);
    while (two <= one) {
      float two = CheckDistance (U3);
      noBack = false;
    }
    analogWrite(leftMotor, 191);
    if (noBack == false) {
      float one = CheckDistance (U3);
      analogWrite(leftMotor, 240);
      delay(1);
      float two = CheckDistance (U3);
      while (two <= one) {
      float two = CheckDistance (U3);
    }
    analogWrite(leftMotor,191);
    }
  }
  if (Min == West) {
    float one = CheckDistance (U4);
    pinMode(leftMotor, OUTPUT);
    analogWrite(leftMotor, 119);
    delay(1);
    float two = CheckDistance (U4);
    while (two <= one) {
      float two = CheckDistance (U4);
      noBack = false;
    }
    analogWrite(leftMotor, 191);
    if (noBack == false) {
      float one = CheckDistance (U4);
      analogWrite(leftMotor, 240);
      delay(1);
      float two = CheckDistance (U4);
      while (two <= one) {
      float two = CheckDistance (U4);
    }
    analogWrite(leftMotor,191);
    }
  }
}

//Firefighter Start
int fireSensorFR = 1;
int fireSensorFL = 2;
int fireSensorL = 3;
int fireSensorB = 4;
int fireSensorR = 5;

int Sensors [4] = {fireSensorFR,fireSensorFL,firesensorL,fireSensorB,fireSensorR};
int Temps [4];

int fire = 0;



//Later on we may want to try a continuous search, but for
//now navigation will relinquish control to searchForFire()

//returns whether a fire was found
bool searchForFire(){
    for (int i = 0; i < 5; i++) {
      //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensors[i]);
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 //Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float Temps[i] = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset. CELCIUS
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print("sensor" sensors[i]);Serial.print(Temps[i]); Serial.println(" degrees C");
    }
if (Temps[i] > VALUE HERE) {
 return true;
 fire = Sensors[i];
 fireHere();
    }
 else() {
  return false;
 }
}

//records which sensor is true
void fireHere() {
  return fire;
}

//This is a function that navigation can call to check one of the flame sensors
bool flameSensorRead(int i) {
  int reading = analogRead(sensors[i]);
   float voltage = reading * 5.0;
 voltage /= 1024.0; 
 float Temps[i] = (voltage - 0.5) * 100 ;
 if (Temps[i] > VALUE HERE) {
 return true;
 fire = Sensors[i];
 fireHere();
    }
 else() {
  return false;
 }
}

void extinguishFire(){
}

//Movement start
//Need to define this. This is the variable that is multiplied by the distance to get the time the robot needs to move the specified distance. Not doing it this way.
float Speed;


//Returns the distance moved
float drive(float dist) {
  int primary = SOUTH;
  fullS();
  takeReads();
  if(ultrasonics[NORTH].myRead < ultrasonics[SOUTH].myRead)
  {
    primary = NORTH;
  }
  float startRead = ultrasonics[primary].myRead;
  fullF();
  float current;
  float last;
  current = startRead;
  doWhile(abs(current - startRead) < dist)
  {
   current = ultrasonics[primary].takeRead();
  }

   fullS();
  
  currentOrientation.y += sin(currentOrientation.angle)*dist;
  currentOrientation.x += cos(currentOrientation.angle)*dist;
}


//Returns the number of radians turned
//angle is in radians, since radians make arc length easier
float Turn(float angle) {
  float Time;
  if (angle > 0) {
    pinMode(motors[CCW].pin,,OUTPUT);
    char initialRead = mouse.mouse_Read();
    analogWrite(motors[CCW].pin,motors[CCW].fullF);
    doWhile(subtract(mouse.mouse_Read(), initialRead) < angle/mouse.radius)
    {
      delay(1);
    }
    analogWrite(motors[CCW].pin,motors[CCW].fullS);
  }
  else {
    pinMode(motors[CW].pin,OUTPUT);
    char initialRead = mouse.mouse_Read();
    analogWrite(motors[CW].pin, motors[CW].fullF);
    doWhile( subtractY(mouse.mouse_Read() , initialRead)< angle/mouse.radius)
    {
      delay(1);
    }
    analogWrite(motors[CW].pin,motors[CW].fullS);
  }
}

void subtractY(char hex, char idk)
{
  //We have to get the mouse hooked up to do readings
}




//TODO: make sure other files get these definitions
#define DIR_NORTH 0
#define DIR_SOUTH 1
#define DIR_WEST  2
#define DIR_EAST  3

//Follows wall until the front sensor can't see the wall anymore
//returns the distance traveled
float WallFollow(int wallSide) {
}

//Navigation Start

//We need pins for the motors

//Handles the actual navigation, not including position checking





pvec3f turnAround()
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

pvec3f attempt(pvec3f moveToAttempt)
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

//Sensor Start

//Shame on all of you for not making changes over the weekend.



void takeReads()
{
  public float theReads[6];
  for(int *i = 0; *i < ultrasonics.length; *i++)
  {
    *theReads[0] = *ultrasonics[*i].takeRead();
  }
  *reads = *theReads;
  return;
}

