int U1 = 1;
int U2 = 2;
int U3 = 3;
int U4 = 4;
int leftMotor = 5;
int rightMotor = 6;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  mouse_init();
}

void loop() {
  determineOrientation();
}

void determineOrientation()
{
  
}

// change the hard coded distances to subtract using the checkponts
// figure out how to communicate with the mouse
// write out all the instructions for the robot
// Confirm location with ultrasonics

