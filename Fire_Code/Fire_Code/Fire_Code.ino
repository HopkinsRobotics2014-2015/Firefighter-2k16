#include <Servo.h>

float threshold;
float light;

Servo Han;


void setup()
{
  Han.attach(10);  
  lookForFLame();
}
void loop()
{
  
}







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




//This is a function that navigation can call to check one of the flame sensors


void extinguishFire(){
}
