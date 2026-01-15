typedef struct {
	int ledState;
	int state;
	int previousState;
	unsigned long lastDebounceTime;
	int buttonPin;
	int ledPin;
}buttonState;

unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

buttonState buttons[6] = {
	{HIGH, LOW, LOW, 0, 2, 8},
	{HIGH, LOW, LOW, 0, 3, 9},
	{HIGH, LOW, LOW, 0, 4, 10},
	{HIGH, LOW, LOW, 0, 5, 11},
	{HIGH, LOW, LOW, 0, 6, 12},
	{HIGH, LOW, LOW, 0, 7, 13}
};	

/*
for a discussion about the millis() function returning zero at some point
https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
heading "What if I really need to compare timestamps?". The first few lines are enough.
*/

void setup() {
	for(int i = 0; i < 6; i++) {
		pinMode(buttons[i].buttonPin, INPUT);
		pinMode(buttons[i].ledPin, OUTPUT);
		digitalWrite(buttons[i].ledPin, buttons[i].ledState);
	}
	// set initial LED state
}

int getLedState(buttonState *button) {
	// read the state of the switch into a local variable:
	int reading = digitalRead(button->buttonPin);

	// If the switch changed, due to noise or pressing:
	if (reading != button->previousState) {
		// reset the debouncing timer
		button->lastDebounceTime = millis();  //store the start time of debouncing delay
	}

	if ((millis() - button->lastDebounceTime) > debounceDelay) {
		//if enough time has passed, check if the button is still in a changed state. If so, we assume the 
		//button is used normally, not just bouncing
		if (reading != button->state) { 
			button->state = reading;

			// only toggle the LED if the new button state is HIGH
			if (button->state == HIGH) {
				button->ledState = !button->ledState;  
			}
		}
	}

	button->previousState = reading; //store the current state of the button

	return button->ledState;
}

void loop() {
	for(int i = 0; i < 6; i++) {
		digitalWrite(buttons[i].ledPin, getLedState(&buttons[i])); 
	}

}