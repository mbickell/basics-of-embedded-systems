#include <Servo.h>

//Write a Arduino program (sketch) which moves the Servo device:
//
//first all the way to the right
//then all the way to the left
//then to the middle

//Do this in the loop() function so it repeats itself. Use delays so it's possible to see the servo move. The Servo is connected to Pin 9.

Servo myservo; // create servo object to control a servo

// Used pins
byte motor = 9;

// Globals
const int min = 0;					// Lowest value for servo
const int max = 180;				// Highest value for servo
const int mid = (max + min) /2;		// Automatically find the middle
int pos = mid; // variable to store the servo position with default value
	
// finalPos should be in range 0 - 180
void blah(int finalPos) {
	int moveDirection;

	// decide if the servo needs to move right or left
	if (pos < finalPos) {
		moveDirection = 1;
	} else {
		moveDirection = -1;
	}

	// keep moving the servo until it reaches the final position given
	while (pos != finalPos) {
		// increment or decrement pos based on the direction of travel for the servo
		pos += moveDirection;
		myservo.write(pos);
		// a small delay to show movement in the simulator
		delay(10);
	}
}

void setup() {
	myservo.attach(motor); // attaches the servo on pin 9 to the servo object
	myservo.write(pos);
}

void loop() {
	blah(min);
	delay(1000);  // delays added to show that servo stops at specific states
	blah(max);
	delay(1000);
	blah(mid);
	delay(1000);
}