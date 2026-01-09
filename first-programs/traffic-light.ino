
/*	This is a default program--
	Use File->Load Prog to load a different program
*/
#define RED_LIGHT 2
#define YELLOW_LIGHT 3
#define GREEN_LIGHT 4

#define DELAY 1000

void setup()
{
	pinMode(RED_LIGHT, OUTPUT);
	pinMode(YELLOW_LIGHT, OUTPUT);
	pinMode(GREEN_LIGHT, OUTPUT);

	for(int i = 2; i < 5; i++) {
		digitalWrite(i, LOW);
	}
}

void loop()
{
	digitalWrite(RED_LIGHT, HIGH);
	delay(DELAY * 2);
	digitalWrite(YELLOW_LIGHT, HIGH);
	delay(DELAY);
	digitalWrite(RED_LIGHT, LOW);
	digitalWrite(YELLOW_LIGHT, LOW);
	digitalWrite(GREEN_LIGHT, HIGH);
	delay(DELAY * 2);
	digitalWrite(YELLOW_LIGHT, HIGH);
	digitalWrite(GREEN_LIGHT, LOW);
	delay(DELAY);
	digitalWrite(YELLOW_LIGHT, LOW);
}
