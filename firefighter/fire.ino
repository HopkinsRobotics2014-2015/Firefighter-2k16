int fireSensorFR = 1;
int fireSensorFL = 2;
int fireSensorL = 3;
int fireSensorB = 4;
int fireSensorR = 5;

int Sensors [4] = {fireSensorFR,fireSensorFL,firesensorL,fireSensorB,fireSensorR};
int Temps [4];

int fire = 0;



//Later on we may want to try a continuous search, but for
//now navigation will relinquish control to searchForFire()

//returns whether a fire was found
bool searchForFire(){
    for (int i = 0; i < 5; i++) {
      //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensors[i]);
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 //Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float Temps[i] = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset. CELCIUS
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print("sensor" sensors[i]);Serial.print(Temps[i]); Serial.println(" degrees C");
    }
if (Temps[i] > VALUE HERE) {
 return true;
 fire = Sensors[i];
 fireHere();
    }
 else() {
  return false;
 }
}

//records which sensor is true
void fireHere() {
  return fire;
}

//This is a function that navigation can call to check one of the flame sensors
bool flameSensorRead(int i) {
  int reading = analogRead(sensors[i]);
   float voltage = reading * 5.0;
 voltage /= 1024.0; 
 float Temps[i] = (voltage - 0.5) * 100 ;
 if (Temps[i] > VALUE HERE) {
 return true;
 fire = Sensors[i];
 fireHere();
    }
 else() {
  return false;
 }
}



void extinguishFire(){
}
