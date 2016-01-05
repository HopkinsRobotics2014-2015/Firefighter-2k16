//Need to define this. This is the variable that is multiplied by the distance to get the time the robot needs to move the specified distance
float Speed;


//Returns the distance moved
float Move(float dist, bool backwards = false) {
  if (backwards) {
    pinMode(motorPin, OUTPUT);
    analogWrite(motorPin, 119);
    delay(dist * Speed);
    analogWrite(motorPin, 191);
  }
  else {
    pinMode(motorPin, OUTPUT);
    analogWrite(motorPin, 240);
    delay(dist * Speed);
    analogWrite(motorPin, 191);
  }
}


//Returns the number of radians turned
//WHY DOES IT HAVE TO RETURN THE RADIANS TURNED? IT IS TOLD HOW MANY RADIANS IT SHOULD TURN.
//angle is in radians, since radians make arc length easier
//DO WE WANT THESE TO HAVE SET VALUES AS SHOWN BELOW OR DO WE WANT TO USE MICE TO DETECT WHEN WE TURN 90 DEGREES EXACTLY
float Turn(float angle) {
  float Time;
  if (angle > 0) {
    pinMode(motorPin2,OUTPUT);
    analogWrite(motorPin2,240);
    delay (angle * Time);
    analogWrite(motorPin2,119);
  }
  else {
    pinMode(motorPin2,OUTPUT);
    analogWrite(motorPin2,119);
    delay(angle*Time);
    analogWrite(motorPin2,119);
  }
}


//TODO: make sure other files get these definitions
#define DIR_NORTH 0
#define DIR_SOUTH 1
#define DIR_WEST  2
#define DIR_EAST  3

//Follows wall until the front sensor can't see the wall anymore
//returns the distance traveled
//ARE WE GOING TO RELY ON A DOUBLE MOUSE CONFIG OR ULTRASONICS TO MOVE?
float WallFollow(int wallSide) {
}
