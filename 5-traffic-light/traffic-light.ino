char redLight =  2;
char yellowLight =  3;
char greenLight =  4;
char pcRedLight = 5;
char pcGreenLight = 6;
char pedestrainCrossingButton = 8;

int delay = 1000;
int pedestrainCrossingDelay = 10000;

char isButtonPushed = 0;

void checkPedestrainCrossing() {
	isButtonPushed = digitalRead(pedestrainCrossingButton);

	if (isButtonPushed) {
		digitalWrite(pcRedLight, LOW);
		digitalWrite(pcGreenLight, HIGH);
		delay(pedestrainCrossingDelay);
		digitalWrite(pcGreenLight, LOW);
		digitalWrite(pcRedLight, HIGH);
	}
}

// Allow user to enter a custom delay before the start of the program
void handleDelayInput() {
	Serial.println("Enter delay in ms,");
	Serial.println("or press enter to accept default delays:");
	String input = Serial.readString();  //read until timeout
	input.trim(); 	// remove any \r \n whitespace at the end of the String
	Serial.println(input);

	if(input.toInt()) {
		delay = input.toInt();
	}

	String output = "Delay set to ";
	output.concat(delay);
	output.concat("ms");
	Serial.print(output);
}

void setup()
{
	pinMode(redLight, OUTPUT);
	pinMode(yellowLight, OUTPUT);
	pinMode(greenLight, OUTPUT);
	pinMode(pcRedLight, OUTPUT);
	pinMode(pcGreenLight, OUTPUT);

	pinMode(pedestrainCrossingButton, INPUT);

	for(int i = 2; i < 7; i++) {
		digitalWrite(i, LOW);
	}

	Serial.begin(9600);
	Serial.setTimeout(5000);

	handleDelayInput();
}

void loop()
{
	digitalWrite(redLight, HIGH);
	checkPedestrainCrossing();
	delay(delay * 2);
	digitalWrite(yellowLight, HIGH);
	delay(delay);
	digitalWrite(redLight, LOW);
	digitalWrite(yellowLight, LOW);
	digitalWrite(greenLight, HIGH);
	delay(delay * 2);
	digitalWrite(yellowLight, HIGH);
	digitalWrite(greenLight, LOW);
	delay(delay);
	digitalWrite(yellowLight, LOW);
}
