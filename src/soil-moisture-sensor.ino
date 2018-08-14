//#include "I2CSoilMoistureSensor.h"
//#include "Particle.h"

/*
 * Project soil-moisture-sensor
 * Description:
 * Author:
 * Date:
 */

int val = 0; // value for storing moisture value
int soilPin = A0; // Declare a variable for the soil moisture sensor
int soilPower = D0; // Variable for Soil moisture Power

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);

  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  digitalWrite(soilPower, HIGH);//turn D7 "On"
  delay(10);//wait 10 milliseconds
  val = analogRead(soilPin);//Read the SIG value form sensor
  digitalWrite(soilPower, LOW);//turn D7 "Off"

  Serial.println("Soil moisture ");
  Serial.println(val);

  delay(1000);
}
