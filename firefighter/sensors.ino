//Shame on all of you for not making changes over the weekend.

class ultrasonic
{
  int pin;
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
  return theRead; //in
  }
}

