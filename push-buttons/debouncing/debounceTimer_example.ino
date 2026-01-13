const int buttonPin = 7;  
const int ledPin = 13; 

int ledState = HIGH;         // the current state of the output pin
int buttonState=LOW;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

/*
for a discussion about the millis() function returning zero at some point
https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
heading "What if I really need to compare timestamps?". The first few lines are enough.
*/

int getLedState() {
	// read the state of the switch into a local variable:
	int reading = digitalRead(buttonPin);

	// If the switch changed, due to noise or pressing:
	if (reading != lastButtonState) {
		// reset the debouncing timer
		lastDebounceTime = millis();  //store the start time of debouncing delay
	}

	if ((millis() - lastDebounceTime) > debounceDelay) {
		//if enough time has passed, check if the button is still in a changed state. If so, we assume the 
		//button is used normally, not just bouncing
		if (reading != buttonState) { 
			//buttonState is a global variable, it retains its value.
			buttonState = reading;

			// only toggle the LED if the new button state is HIGH
			if (buttonState == HIGH) {
				ledState = !ledState;  
			}
		}
	}

	lastButtonState = reading; //store the current state of the button

	return ledState;
}

void setup() {
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);
	// set initial LED state
	digitalWrite(ledPin, ledState);
}

void loop() {
	digitalWrite(ledPin, getLedState());  

}//loop