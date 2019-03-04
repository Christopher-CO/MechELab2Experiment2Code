#include <AFMotor.h>

/*
  Analog input, analog output, serial output

  Reads two analog input pins.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to analog pin 0.
    side pins of the potentiometer go to +5V and ground
  - photo resistor goes to analog pin 1. connected in series with 10k resistor to +5V and ground.
*/


// These constants won't change. They're used to give names to the pins used:
const int potentiometer = 0;  // Analog input pin that the potentiometer is attached to
const int photoResistor = 1; // Analog input pin that photo resistor

int motorAngle = 0;        // value read from the pot
int lightIntensity = 0;        // value read from photo Resistor
AF_Stepper stepperMotor(500, 2);
AF_DCMotor dcMotor(2);



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // set motor speed
  stepperMotor.setSpeed(10);  // 10 rpm  
  
  dcMotor.setSpeed(500);
  dcMotor.run(RELEASE);
}

void loop() {
  // read the analog in value:
  lightIntensity = analogRead(photoResistor);
  motorAngle = analogRead(potentiometer);

  // print the results to the Serial Monitor:
  Serial.print("Potentiometer = ");
  Serial.print(motorAngle);
  Serial.print("\t photoResistor = ");
  Serial.println(lightIntensity);
  delay(500);
 
  // turn stepper motor
  Serial.println("Single coil steps");
  stepperMotor.step(100, FORWARD, SINGLE); 
  stepperMotor.step(100, BACKWARD, SINGLE); 

  // dc motor run
  dcMotor.run(FORWARD);
  delay(1000);
  dcMotor.run(RELEASE);
}
