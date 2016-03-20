//I KNOW HOW TO FIX IT
class motor
{
  int pin;
  int fullFs;
  int fullSs;
  int fullRs;
  motor()
  {
    return;
  }
  void fullF()
  {
    pinMode(pin, OUTPUT);
    analogWrite(this -> pin,this -> fullFs);
  }
  void fullS()
  {
    pinMode(pin, OUTPUT);
    analogWrite(this -> pin,this -> fullSs);
  }
  void fullR()
  {
    pinMode(pin, OUTPUT);
    analogWrite(this->pin,this  -> fullRs);
  }
};
// put your setup code here, to run once:
#define North = 1;
#define South = 2;
#define East = 3;
#define West = 4;
int CW = 0;
int CCW = 1;

pvec3f currentOrientation;
motor[] motors = new motor[2];

ultrasonic[] ultrasonics;

int U1 = 1;
int U2 = 2;
int U3 = 3;
int U4 = 4;
int leftMotor = 5;
int rightMotor = 6;

void declareMotor(int i)
{
  //motor[] motors = motors;
  switch (i)
  {
    case (0):
    motors[i] = new motor();
    motors[i].pin = 1;
    motors[i].fullFs = 225;
    motors[i].fullSs = 189;
    motors[i].fullRs = 157;
    CW = i-1;
    break;
    
    case (1):
    motors[i] = new motor();
    motors[i].fullFs = 240;
    motors[i].fullSs = 191;
    motors[i].fullRs = 130;
    motors[i].pin = 2;
    CCW = i-1;
    break;
  }
}

void declareUltrasonics()
{
  ultrasonics[] = new ultrasonic[6]
  for(int i = 0; i < 6; i++)
  {
    ultrasonics[i] = new ultrasonic();
    ultrasonics[i].pin = i+1;
  }
}



void fullF()
{
  motors[CW].fullR();
  motors[CCW].fullF();
}
void fullS()
{
  motors[CW].fullS();
  motors[CCW].fulls();
}
void fullR();
{
  motors[CW].fullF();
  motors[CCW].fullR();
}
void fullCCW()
{
  motors[CW].fullF();
  motors[CCW].fullF();
}
void fullCW()
{
  motors[CW].fullR();
  motors[CCW].fullR();
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
  
  currentOrientation = new pvec3f();
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
 float[] reads = new float[ultrasonics.length];
 reads = takeReads();
 if(abs(10-reads[South]) < 2 && abs(10-reads[East]) < 2)
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

}




