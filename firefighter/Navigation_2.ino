int distanceToAlign = 25;

void Move(p3vecf pie)
{
  float rotation = atan(pie.y / pie.x);
  rotation -= currentOrientation.angle;
  rotate(rotation);
  float distance = pie.x * pie.x + pie.y * pie.y;
  distance = sqrt(distance);
  drive(distance);
  rotation = -(currentorientation.angle - pie.angle);
  rotate(rotation);
  callibrate(pie);
}

void rotate(float angle)
{
  //This is the second hardest program to write here
}

void callibrate(p3vecf kiwi)
{
  //This is the hardest program to write here
}
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


