//Need to define this. This is the variable that is multiplied by the distance to get the time the robot needs to move the specified distance
float Speed;


//Returns the distance moved
float Move(float dist) {
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
//angle is in radians, since radians make arc length easier
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
float WallFollow(int wallSide) {
}
