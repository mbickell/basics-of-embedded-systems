char buttonOne = 2;
char buttonTwo = 3;
char led = 12;

char valueOne = 0;
char valueTwo = 0;
char ledValue = 0;

void setup()
{
	pinMode(led, OUTPUT);
	pinMode(buttonOne, INPUT);
	pinMode(buttonTwo, INPUT);
}

void loop()
{
	valueOne = digitalRead(buttonOne);
	valueTwo = digitalRead(buttonTwo);

	ledValue = valueOne || valueTwo;
	// ledValue = valueOne && valueTwo;

	digitalWrite(led, ledValue);
}
