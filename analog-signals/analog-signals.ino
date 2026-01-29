
/*	This is a default program--
	Use File->Load Prog to load a different program
*/

// Constants
const float V_REF = 5.0;     // Analog reference voltage (e.g., 5V or 3.3V)
const float R_BITS = 10.0;   // ADC resolution (bits)
const float ADC_STEPS = (1 << int(R_BITS)) - 1; // Number of steps (2^R_BITS - 1)

void setup()
{
	Serial.begin(9600); // Initialize serial communication
	Serial.println(ADC_STEPS);
	pinMode(A0, INPUT);
}

void loop()
{
	int rawValue = analogRead(A0); // Read the analog input
	float voltage = (rawValue / ADC_STEPS) * V_REF; // Convert to voltage
	// 11 1111 1111 - 1023
	// 10 0000 0000 - 0512

	Serial.println(rawValue);
	Serial.print("Voltage: ");
	Serial.print(voltage, 3); // Print voltage with 3 decimal places
	Serial.println(" V");
	delay(200); // Small delay to avoid flooding the serial monitor

}
