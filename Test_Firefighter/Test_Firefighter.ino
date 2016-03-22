#include <TheLibrary.h>
#include <Servo.h>
//I KNOW HOW TO FIX IT







// put your setup code here, to run once:
int North = 0;
int South = 5;
int East = 1;
int West = 3;
int LeftBack = 4;
int RightBack = 2;
int CW = 1;
int CCW = 0;
int flamePin = 0;
float Temps[1];
pvec3f currentOrientation;

motor motors[2];
long reads[6];
ultrasonic ultrasonics[6];
checkpoint checkpoints[17];

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
    motors[0].pin = 11;
    motors[0].fullFs = 243;
    motors[0].fullSs = 191;
    motors[0].fullRs = 140;
    CW = 0;
    break;
    
    case (1):
    motors[1] = *r;
    motors[1].fullFs = 243;
    motors[1].fullSs = 191;
    motors[1].fullRs = 140;
    motors[1].pin = 12;
    CCW = 1;
    break;
    default:
    break;
  }
}

void declareUltrasonics()
{

  for(int i = 0; i < 6; i++)
  {
    ultrasonic *r = new ultrasonic();
    ultrasonics[i] = *r;
    pinMode(ultrasonics[i].pinT, OUTPUT);
    pinMode(ultrasonics[i].pinE, INPUT);
  }
  //Front
  ultrasonics[0].pinE = 14;
  ultrasonics[0].pinT = 15;
  pinMode(ultrasonics[0].pinT,OUTPUT);
  pinMode(ultrasonics[0].pinE, INPUT);
  //Right F
  ultrasonics[1].pinE = 7;
  ultrasonics[1].pinT = 6;
  pinMode(ultrasonics[1].pinT,OUTPUT);
  pinMode(ultrasonics[1].pinT,INPUT);
  //Right B
  ultrasonics[2].pinE = 4;
  ultrasonics[2].pinT = 3;
  pinMode(ultrasonics[2].pinE, INPUT);
  pinMode(ultrasonics[2].pinT, OUTPUT);
  //Left F
  ultrasonics[3].pinE = 18;
  ultrasonics[3].pinT = 19;
  pinMode(ultrasonics[3].pinE, INPUT);
  pinMode(ultrasonics[3].pinT, OUTPUT);
  //Left B
  ultrasonics[4].pinE = 16;
  ultrasonics[4].pinT = 17;
  pinMode(ultrasonics[4].pinE,INPUT);
  pinMode(ultrasonics[4].pinT,OUTPUT);
  //Back
  ultrasonics[5].pinE = 20;
  ultrasonics[5].pinT = 21;
  pinMode(ultrasonics[5].pinE,INPUT);
  pinMode(ultrasonics[5].pinT,OUTPUT);
}


float takeRead(char r)
{
 if( r = 'N'){
    pinMode(ultrasonics[North].pinT,OUTPUT);
    pinMode(ultrasonics[North].pinE,INPUT);
    float pie = ultrasonics[North].takeRead();
    return pie;
    }
    if(r = 'S')
    {
    pinMode(ultrasonics[North].pinT,OUTPUT);
    pinMode(ultrasonics[North].pinE,INPUT);
    float noVegiePlease = ultrasonics[South].takeRead();
    return noVegiePlease = ultrasonics[South].takeRead();
    }
    if(r ='E'){
    pinMode(ultrasonics[East].pinT,OUTPUT);
    pinMode(ultrasonics[East].pinE,INPUT);
        pinMode(ultrasonics[RightBack].pinT,OUTPUT);
    pinMode(ultrasonics[RightBack].pinE,INPUT);
    float chives = ultrasonics[East].takeRead();
    chives += ultrasonics[RightBack].takeRead();
    chives = .5*chives;
    return chives;
    }
    if(r = 'W'){
    pinMode(ultrasonics[West].pinT,OUTPUT);
    pinMode(ultrasonics[West].pinE,INPUT);
    pinMode(ultrasonics[LeftBack].pinT,OUTPUT);
    pinMode(ultrasonics[LeftBack].pinE,INPUT);
    float radishes = ultrasonics[West].takeRead();
    radishes += ultrasonics[LeftBack].takeRead();
    radishes = radishes/2.0;
    return radishes;
    }
}

void fullF()
{
  analogWrite(motors[CW].pin, motors[CW].fullFs);
  analogWrite(motors[CCW].pin, motors[CCW].fullRs);  
}
void fullS()
{
  motors[CW].fullS();
  motors[CCW].fullS();
}
void fullR()
{
  motors[CCW].fullF();
  motors[CW].fullR();
}
void fullCW()
{
  motors[CW].fullF();
  motors[CCW].fullF();
}
void fullCCW()
{
  motors[CW].fullR();
  motors[CCW].fullR();
}

void setup() {







//This accounts for the 30 centimeters that the robot is. I am accounting for it as +40 cm
  checkpoints[0] = new checkpoint (23, 47);
  checkpoints[1] = new checkpoint (23, 114);
  checkpoints[2] = new checkpoint (32, 221);
  checkpoints[3] = new checkpoint (99, 23);
  checkpoints[4] = new checkpoint (99, 114);
  checkpoints[5] = new checkpoint (99, 128);
  checkpoints[6] = new checkpoint (99, 221);
  checkpoints[7] = new checkpoint (166,221);
  checkpoints[8] = new checkpoint (173,23);
  checkpoints[9] = new checkpoint (173,90);
  checkpoints[10] = new checkpoint (221,23);
  checkpoints[11] = new checkpoint (221,128);
  checkpoints[12] = new checkpoint (221,195);
  
  
/*
  checkpoints[1] = new checkpoint (23, 114);
  checkpoints[2] = new checkpoint (23, 166);
  checkpoints[3] = new checkpoint (23, 221);
    checkpoints[4] = new checkpoint (99, 23);
  checkpoints[5] = new checkpoint (99, 114);
//  checkpoints[6] = new checkpoint (99, 175);
  checkpoints[6] = new checkpoint (99, 221);
//  checkpoints[7] = new checkpoint (143, 73);
//  checkpoints[8] = new checkpoint (143, 114);
  checkpoints[7] = new checkpoint (150, 175);//(150,17);
  checkpoints[10] = new checkpoint (150, 221);//(150,22);
  checkpoints[11] = new checkpoint (173, 23);//(169,23);
  checkpoints[12] = new checkpoint (173, 73);//(169,73);
  checkpoints[13] = new checkpoint (220, 23);//(220,23);
  checkpoints[14] = new checkpoint (220, 114);//(220,11);
  checkpoints[15] = new checkpoint (220, 222);//(220,22);
*/

  //visualize();
  
  // put your setup code here, to run once:
  Serial.begin(9600);


  declareMotor(0);
  declareMotor(1);
  declareUltrasonics();
  currentOrientation.x = 99;
  currentOrientation.y = 23;
  currentOrientation.angle = PI;

  determineOrientation();


 
  //runTheMaze();
  Serial.println(ultrasonics[0].takeRead());
  Serial.println(ultrasonics[South].myRead);
  delay(10000);
  drive(5);
  Serial.println(ultrasonics[North].myRead);
}















void runTheMaze()
{
  Move (0, 100, -PI/2.0);
  Move (0, 74, -PI/2.0);
  Move (0, 72, 0);
//firefight
  rotate (PI);
  Move (0, 74, PI/2.0);
  Move (0, 72, -PI/2.0);
  Move (0, 107, -PI/2.0);
  Move (0, 74, 0);
//firefight
  rotate (180);
  Move (0, 74, PI/2.0);
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
  //delay(2000);
  //Align();
  //Serial.println(ultrasonics[0].takeRead());
  
  /*
  takeReads();
  Serial.println("Begin");
  delay(1000);
  Serial.print("NORTH  ");
  Serial.println(ultrasonics[North].takeRead());
  delay(1000);
  Serial.print("East   ");
  Serial.println(ultrasonics[East].myRead);
  delay(1000);
  Serial.print("RightBack   ");
  Serial.println(ultrasonics[RightBack].myRead);
  delay(1000);
  Serial.print("South    ");
  Serial.println(ultrasonics[South].myRead);
  delay(1000);
  Serial.print("LeftBack    ");
  Serial.println(ultrasonics[LeftBack].myRead);
  delay(1000);
  Serial.print("West   ");
  Serial.println(ultrasonics[West].myRead);
  */

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
 //setNeighbors(orientation); 
}




// Checkpoints Start
int distanceToAlign = 25;

void Move(float x,float y,float z)
{
  pvec3f *pie = new pvec3f();
  float rotation;
  pie->setX(x-currentOrientation.x);
  pie->setY(y-currentOrientation.y);
  pie->setAngle(z);
  if(pie->getX() != 0){
  rotation = atan(pie->getY() / pie->getX());
  }
  else if(pie->getY() > 0)
  {
    rotation = PI/2.0;
  }
  else{
    rotation = -PI/2.0;
  }
  rotation -= currentOrientation.angle;
  rotate(rotation);
  float distance = pie->getX() * pie->getX() + pie->getY()* pie->getY();
  distance = sqrt(distance);
  drive(distance);
  rotation = -(currentOrientation.angle - pie->angle);
  rotate(rotation);
  //callibrate(pie);
  return;
}

const float timeScaleFactor = 1500;

float rotate(float angle)
{

  fullS();
  takeReads();
  if(angle > 0) {
	  motors[CCW].fullF();
	  motors[CW].fullR();
  }
  else {
	  motors[CCW].fullR();
	  motors[CW].fullF();
  }
  delay(angle * timeScaleFactor);
  fullS();
  return angle;
}

  void rightpivotback (int value)
{
  readultra(4);
  while (readback>value)
  {
    readultra(4);
    analogWrite(rightmotor,hsf);
    analogWrite(leftmotor,hsf);
  }
  FullS();
  alignleft();
}
void leftpivotback (int value)
{
  takeReads();
  ultrasoinics[East].takeRead();
  while (reads[South] > value){
    ultrasonics[South].takeRead;
    
  }
}

  




void Align () {
  //take ultrasonic readings for all ultrasonics
  takeReads();
  if(ultrasonics[West].myRead < ultrasonics[East].myRead)
  {
    if(ultrasonics[West].myRead < ultrasonics[LeftBack].myRead)
    {
      fullCW();
      while(ultrasonics[West].myRead < ultrasonics[LeftBack].myRead)
      {
        fullS();
        takeReads();
        fullCW();
        delay(1);
      }
      fullS();
      
    }
    else
    {
      fullCCW();
      while(ultrasonics[West].myRead > ultrasonics[LeftBack].myRead)
      {
        fullS();
        takeReads();
        delay(1);
        fullCCW();
      }
      fullS();
    }
  }
  else
  {
     if(ultrasonics[East].myRead < ultrasonics[RightBack].myRead)
     {
     fullCW();
     while(ultrasonics[East].myRead < ultrasonics[RightBack].myRead)
     {
       fullS();
       takeReads();
       fullCW();
       delay(1);
     }
     fullS();
      
    }
    else
    {
      fullCCW();
      while(ultrasonics[East].myRead > ultrasonics[RightBack].myRead)
      {
        fullS();
        takeReads();
        delay(1);
        fullCCW();
      }
      fullS();
    }
  }
 
  takeReads();
}



float threshold;
float light;

Servo Han;


void lookForFLame()
{
  float reads[6];
  float lowestRead;
  int lowestReading;
  delay(3000);
  lowestRead = 100000000;
  
  for(int i = 40 ; i < 100 ; i+=10)
  {
    int p = (i-40)/10.0;
    Han.write(i);
    delay(3000);
    reads[p] = takeFireRead();
    if(reads[p] < lowestRead)
    {
      lowestRead = reads[p];
      lowestReading = p;
    }
  }
    
  if( lowestRead < threshold )
  {
    putItOut();
    return;
  }

  
  if( lowestRead < light)
  {
    moveOnFlame(lowestRead, lowestReading);
  }

  if(lowestRead > light){
    return;
  }

}



void moveOnFlame(float lowestRead, int lowestReading)
{    
  delay(3000);
  Han.write(65);
  if((lowestReading*10 + 40) >65);{
    analogWrite(12, 221);
    wait(lowestRead);
    analogWrite(12, 191);
  }
  if( (lowestReading*10 + 40) <=65){
    analogWrite(11, 221);
    wait(lowestRead);
    analogWrite(11,191);
  }
  
}
  




void wait(float lowestRead)
{
  while(takeFireRead() > lowestRead){
    delayMicroseconds(1);
  }
}
//Firefighter Start
int firePin = A0;
int fanPin = 9;


void putItOut()
{
  digitalWrite(9, HIGH);
}
//Later on we may want to try a continuous search, but for
//now navigation will relinquish control to searchForFire()

//returns whether a fire was found
bool fireFight()
{
  
  //Take reading
  delay(500);
}

float takeFireRead()
{
  float reading = analogRead(A0);
}







//Returns the distance moved
float drive(float dist) {
  char primary = 'N';
  fullS();
  takeReads();
  if(ultrasonics[North].myRead < ultrasonics[South].myRead)
  {
    primary = 'N';
  }
  else
  {
    primary = 'S';
  }
  Serial.println(primary);
  float startRead = takeRead(primary);
  Serial.println(startRead);
  fullF();
  float current;
  float last;
  current = startRead;
  float apple = current - startRead;
  Serial.println(apple);
  while(abs(apple) < dist)
  {
   float sum;
   for(int i = 0; i < 10; i++)
   {
    sum+= takeRead(primary);
   }
   current =sum/10.0;
   delay(10);
   Serial.println(current);
   Serial.println(abs(current-startRead));
   Serial.println(primary);
   apple = current - startRead;
  }

   fullS();
  
  currentOrientation.y += sin(currentOrientation.angle)*dist;
  currentOrientation.x += cos(currentOrientation.angle)*dist;
  return dist;
}


//Returns the number of radians turned
//angle is in radians, since radians make arc length easier
/*
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
    analogWrite(motors[CW].pin, motors[CW].fullFs);
    while(subtractY(mouse.mouse_Read() , initialRead)< angle/mouse.radius)
    {
      delay(1);
    }
    analogWrite(motors[CW].pin, motors[CW].fullSs);
  }
}

void subtractY(char hex, char idk)
{
  //We have to get the mouse hooked up to do readings
}
*/



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
  float apple = rotate(PI);
  if (apple < PI)
  {
    drive(-1.5);
    float kiwi = rotate(PI);
    if(kiwi < PI)
    {
    rotate(-kiwi);
    drive(-5);
    float peach = rotate(PI);
    drive(-5);
    rotate(-apple);
    }
    else
    {
      drive(-1.5);
      rotate(-(apple));
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
  int fireSensor[5];
  fireSensor[0] = 0;
  fireSensor[1] = 0;
  fireSensor[2] = PI / 2;
  fireSensor[3] = PI;
  fireSensor[4] = -PI / 2;
  if (searchForFire()) {
    int Sensor = fireHere();
    for (int i = 1; i < 6; i++) {
      if (fireSensor[i] == Sensor) {
        float Sensor = fireSensor[i];
      }
    }
    //HERE IS WHERE WE ROTATE THE ROBOT TO THE FLAME. NEED TO FIGURE OUT IF WE ARE DOING THIS WITH TWO MICE, ULTRASONICS, OR PRE-DETERMINED ROTATION VALUES
    rotate(-Sensor);
  }
  sprayAndPray();
}

//This function has the robot slowly approach the flame while blowing the fan.

void sprayAndPray() {
  while (flameSensorRead(0)) {
    //IM OFFLINE RN BUT FIND FAN COMMAND. RUN FAN AT MAX
    pinMode(flamePin, OUTPUT);
    analogWrite(flamePin, 210);
  }
  analogWrite(flamePin, 191);
  returnHome();
}

//This will direct the robot back to the start after the flame has been put out
void returnHome() {

}

//Sensor Start

//Shame on all of you for not making changes over the weekend.



void takeReads()
{
  long theReads[6];
  for(int i = 0; i < 6; i++)
  {
    pinMode(ultrasonics[i].pinT, OUTPUT);
    pinMode(ultrasonics[i].pinE,INPUT);
    theReads[i] = ultrasonics[i].takeRead();
    ultrasonics[i].myRead = theReads[i];
    delay(25);
  }
  *reads = *theReads;
}

