
/*	This is a default program--
	Use File->Load Prog to load a different program
*/

byte count = 0x00;
byte bitMask = 0x01;

byte getBitAtLocation(byte count, byte location) {
	return (count >> (location - 1)) & bitMask;
}

void updateDisplay(byte count) {
	for (byte i = 0; i < 4; i++) {
		digitalWrite(i + 8, LOW);
		digitalWrite(i + 8, getBitAtLocation(count, i + 1));
	}
}

void setup()
{
	pinMode(12, OUTPUT);
	digitalWrite(12, LOW);

	for(int i = 0; i < 4; i++) {
		pinMode(i + 8, OUTPUT);
	}

	count=0;
}

void loop()
{
	count = count == 0x0F ? 0 : count + 1;

	updateDisplay(count);

	delay(1000);
}
