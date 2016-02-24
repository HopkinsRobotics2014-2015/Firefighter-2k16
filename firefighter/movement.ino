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
    //I'm going to propose a change here that we could use to see how far we have gone rather than rely on "Speed"
    /*
     *  doWhile(float distanceRead < dist)
     *  {
     *    distanceRead = mouse.mouse_Read();
     *    distanceRead = checkDistance(distanceDeterminingSensor) - distanceDeterminingSensor.initialDistance;
     *  }
     */
    analogWrite(motorPin, 191);
  }
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
