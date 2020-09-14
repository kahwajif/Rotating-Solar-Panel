#include <Stepper.h>

const int stepsPerRevolution = 100;  // change this to fit the number of steps per revolution for your motor

int extraCount = 0;
int relay = 4;      // Relay connected to Digital Input 13

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  
  pinMode(relay, OUTPUT);       //sets relay pin as output
}

void loop() {

  while (extraCount < 100) { 
    // step one revolution  in one direction (CW):
    myStepper.step(1);  // Moves one step per loop CW
  delay(50);
  digitalWrite(relay,LOW);
    delay(500);
    extraCount++;       // Counts till the while loop ends
    delay(5000);     // Delays input for 1/100th of 11 hours (this way it'll move 100 steps till it ends)
    digitalWrite(relay, HIGH);
    delay(500);     
  }
  
  extraCount = 0;  // Resets count for the while loops

  while (extraCount < 100) { 
    // step one revolution in the other direction (CCW):
    myStepper.step(-1); // -1 so it moves a step backwards, or CCW
    extraCount++;       // Counts till the while loop condition is met
    delay(50);          // Delays input for 50 MS until it steps back 100 times, then it will finish loop
  }
  digitalWrite(relay,LOW);
  delay(500);
  extraCount = 0;  // Resets count for the while loops
  delay(10000); // Delays input for 13 hours (in MS)
  digitalWrite(relay, HIGH);
  delay(500);
}
