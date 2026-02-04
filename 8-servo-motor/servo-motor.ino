#include <Servo.h>

Servo myservo; // create servo object to control a servo

// Used pins
byte redLight = 12;
byte yellowLight = 11;
byte greenLight = 10;
byte boomLightRed = 9;
byte boomLightGreen = 8;
byte motor = 7;
byte button = 2;

// Globals
const int min = 600;
const int max = 1500;
int pos = min; // variable to store the servo position with default value
int lightDelayMS = 1500;

volatile byte state = LOW;  // variable that will be updated in the ISR - for interrupt

void liftBoom() {
	while (pos < max)
	{
		myservo.writeMicroseconds(pos);
		pos += 2;
		delay(10);
	}

	updateBoomLights();

	delay(lightDelayMS * 2);
	
	state = LOW;
	updateBoomLights();

	while (pos > min)
	{
		myservo.writeMicroseconds(pos);
		pos -= 2;
		delay(10);
	}
}

// default state for traffic lights
void resetTrafficLights() {
	digitalWrite(redLight, HIGH);
	digitalWrite(yellowLight, LOW);
	digitalWrite(greenLight, LOW);
}

void runTrafficLights() {
	resetTrafficLights();
	
	delay(lightDelayMS * 2);
	digitalWrite(yellowLight, HIGH);
	
	delay(lightDelayMS);
	digitalWrite(redLight, LOW);
	digitalWrite(yellowLight, LOW);
	digitalWrite(greenLight, HIGH);
	
	delay(lightDelayMS * 2);
	digitalWrite(greenLight, LOW);
	digitalWrite(yellowLight, HIGH);
	
	delay(lightDelayMS);
	resetTrafficLights();
}

// Function to run when interrupt is triggered
// Needs to be small and fast, cannot write to pins directly
void setBoomLight() {
	state = HIGH;
}

// boom lights should always be opposite to each other
void updateBoomLights() {
	digitalWrite(boomLightRed, !state);
	digitalWrite(boomLightGreen, state);
}

void setup() {
	myservo.attach(motor); // attaches the servo on pin 9 to the servo object

	for(byte i = 8; i < 13; i++) {
		pinMode(i, OUTPUT);
	}

	pinMode(button, INPUT);

	resetTrafficLights();
	updateBoomLights();

	// Attach an interrupt to a specific pin, what function to run when interrupted, and what condition to look for
	attachInterrupt(digitalPinToInterrupt(button), setBoomLight, RISING);
	
	myservo.writeMicroseconds(pos);
}

void loop() {
	runTrafficLights();

	if (state == HIGH) {
		liftBoom();
	}
}