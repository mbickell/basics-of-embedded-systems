// Analogue slider gives a 10 bit value from 0-1023
// In order to convert this into a voltage in the code we need to perform some bit manipulation

// Constants
const float V_REF = 5.0;     // Analog reference voltage (e.g., 5V or 3.3V)
const float R_BITS = 10.0;   // ADC resolution (bits)

// ADC - (analog digital conversion)
// Take 1 bit, shift left by the number of bits (R_bits) that the slider provides (10)
// minus 1 at the end
// start 					00000000001 - 1
// after shift 		10000000000 - 1024
// minus 1				01111111111 - 1023 (max value from slider)
const float ADC_STEPS = (1 << int(R_BITS)) - 1; // Number of steps (2^R_BITS - 1)

void setup()
{
	Serial.begin(9600); // Initialize serial communication
	Serial.println(ADC_STEPS);
	pinMode(A0, INPUT);
	pinMode(2, OUTPUT);
}

void loop()
{
	int rawValue = analogRead(A0); // Read the analog input
	float voltage = (rawValue / ADC_STEPS) * V_REF; // Convert to voltage

	// rawValue		-	0-1023
	// ADC_STEPS	-	1023
	// V_REF 			-	5
	// if rawValue = 540 - (540/1023) * 5 = 2,639

	Serial.println(rawValue);
	Serial.println(ADC_STEPS);
	Serial.print("Voltage: ");
	Serial.print(voltage, 3); // Print voltage with 3 decimal places
	Serial.println(" V");
	delay(200); // Small delay to avoid flooding the serial monitor

	if(voltage == 5.0) {
		digitalWrite(2, HIGH);
	} else {
		digitalWrite(2, LOW);
	}

}
