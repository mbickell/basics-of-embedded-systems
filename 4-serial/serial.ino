int count = 0;

String colourMatcher(String colourInput) {
	String match;

	switch(colourInput) {
		case "red":
			match = "yellow";
			break;
		case "yellow":
			match = "green";
			break;
		case "green":
			match = "red";
			break;
		default:
			match = "not accepted";
	}

	return match;
}

void setup()
{
	Serial.begin(9600);
	Serial.setTimeout(500);
}

void loop()
{
	Serial.println("Enter data:");
	while (Serial.available() == 0) {	}     //wait for data available
	String input = Serial.readString();  //read until timeout
	input.trim(); 	// remove any \r \n whitespace at the end of the String
	Serial.println(colourMatcher(input));

	count++;
}