//Shame on all of you for not making changes over the weekend.

public class ultrasonic
{
  int pin;
  float myRead;
  float takeRead()
  {
  digitalWrite(this.pin, LOW);
  delay(2);
  digitalWrite(this.pin, HIGH);
  delay(5);
  digitalWrite(this.pin, LOW);
  pinMode (this.pin, INPUT);
  digitalWrite(this.pin, HIGH);
  float theRead;
  theRead = pulseIn(this.pin, HIGH) / 58.138;
  digitalWrite(this.pin, LOW);
  myRead = theRead;
  return theRead; //in
  }
}

float[] takeReads()
{
  float[] theReads = new float[ultrasonics.length];
  for(int i = 0; i < ultrasonics.length; i++)
  {
    theReads[0] = ultrasonics[i].takeRead();
  }
  return theReads;
}

