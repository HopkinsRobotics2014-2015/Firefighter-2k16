#define North = 1;
#define South = 2;
#define East = 3;
#define West = 4;

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
  determineOrientation();
  go(1,2);
  Align();
  move (0, 100, -90);
move (0, 74, -90);
move (0, 72, 0);
//firefight
rotate (180);
move (0, 74, 90);
move (0, 72, -90);
move (0, 107, -90);
move (0, 74, 0);
//firefight
rotate (180);
move (0, 74, 90);
move (0, 46, -90);
move (0, 53, 0);
//firefight
move (0, 70, 90);
move (0, 198, 90);
move (0, 51, 90);
move (0, 50, 0);
//firefight
rotate (180);
move (0, 50, 90);
move (0, 72, 90);
}




void loop() {

}

void determineOrientation()
{
 int orientation;
 int[] reads = new int[4];
 readUltras;
 reads = UltraReadings;
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

