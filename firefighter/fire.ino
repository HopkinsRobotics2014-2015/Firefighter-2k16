int fireSensorFR = 1;
int fireSensorFL = 2;
int fireSensorL = 3;
int fireSensorB = 4;
int fireSensorR = 5;

int Sensors [4] = {fireSensorFR,fireSensorFL,firesensorL,fireSensorB,fireSensorR};

bool Fire[4];
for (int i = 0; i < 5; i++) {
  Fire[i] = false;
}


//Later on we may want to try a continuous search, but for
//now navigation will relinquish control to searchForFire()

//returns whether a fire was found
bool searchForFire(){
  while (fireFound == false) {
    for (int i = 0; i < 5; i++) {
      //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensors[i]);
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 //Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print("sensor" sensors[i]);Serial.print(temperatureC); Serial.println(" degrees C");
if (temperatureC > VALUE HERE) {
 Fire[i] = true;
    }
}
}

void extinguishFire(){
}
