char booleanSwitch = 2;
char buttonOne = 3;
char buttonTwo = 4;
char led = 12;

char valueOne = 0;
char valueTwo = 0;
char ledValue = 0;

void setup()
{
	pinMode(led, OUTPUT);
	pinMode(booleanSwitch, INPUT);
	pinMode(buttonOne, INPUT);
	pinMode(buttonTwo, INPUT);
}

void loop()
{
	valueOne = digitalRead(buttonOne);
	valueTwo = digitalRead(buttonTwo);

	if (digitalRead(booleanSwitch)) {
		ledValue = valueOne && valueTwo;
	} else {
		ledValue = valueOne || valueTwo;
	}

	digitalWrite(led, ledValue);
}
