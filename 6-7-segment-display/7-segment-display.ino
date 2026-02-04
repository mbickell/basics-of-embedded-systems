// This program shows the use of a 7-segment display
// The count is managed by an 8 bit binary number as the 7 segment display requires
// 4 pins in order to display a number, therefore it's easier to use 4 bits to manage the
// high and low states of the pins

byte count = 0x00; 		// 00000000
byte bitMask = 0x01;	// 00000001

byte getBitAtLocation(byte count, byte location) {
	// Shift the byte right by x number of spaces
	// bitwise and (&) the final bit in order to read it 
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
	// if count is 15, reset it to 0, otherwise increment by 1
	count = count == 0x0F ? 0 : count + 1;

	updateDisplay(count);

	delay(1000);
}
