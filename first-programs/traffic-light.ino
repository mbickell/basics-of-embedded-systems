
/*	This is a default program--
	Use File->Load Prog to load a different program
*/

void setup()
{
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
}

void loop()
{
	digitalWrite(2, HIGH);
	delay(2000);
	digitalWrite(3, HIGH);
	delay(1000);
	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	digitalWrite(4, HIGH);
	delay(2000);
	digitalWrite(3, HIGH);
	digitalWrite(4, LOW);
	delay(1000);
	digitalWrite(2, HIGH);	
	digitalWrite(3, LOW);
}
