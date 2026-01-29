#include <Servo.h>

Servo myservo; // create servo object to control a servo
// twelve servo objects can be created on most boards
const int min = 600;
const int max = 2400;
const int mid = (max + min) / 2;
int pos = mid; // variable to store the servo position

void setup() {
	myservo.attach(9); // attaches the servo on pin 9 to the servo object
}

void loop() {
	// for (pos = min; pos <= max; pos += 1) { // goes from 0 degrees to 180 degrees
	// // in steps of 1 degree
	// myservo.writeMicroseconds(pos); // tell servo to go to position in variable 'pos'
	// delay(15); // waits 15ms for the servo to reach the position
	// }

	// for (pos = max; pos >= min; pos -= 1) { // goes from 180 degrees to 0 degrees
	// myservo.writeMicroseconds(pos); // tell servo to go to position in variable 'pos'
	// delay(15); // waits 15ms for the servo to reach the position
	// }

	while (pos > min)
	{
		myservo.writeMicroseconds(pos);
		pos--;
		delay(10);
	}

	while (pos < max)
	{
		myservo.writeMicroseconds(pos);
		pos++;
		delay(10);
	}

}