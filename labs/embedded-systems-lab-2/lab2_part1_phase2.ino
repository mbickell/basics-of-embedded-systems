const char analog_input = A0;
float old_input_voltage= 0;

int BIT = 10;
int ADC_Max = (1 << BIT) -1;
float Ref_voltage = 5.05;
float coefficient = 10;

void setup () {
	pinMode(analog_input, INPUT);
	Serial.begin(9600);
}c:\Users\e2501254\Downloads\part2_phase4.ino

void loop() {
	float raw_ADC = analogRead(analog_input);
	float R4_voltage = (raw_ADC/ (float)ADC_Max) * Ref_voltage;
	float input_voltage = coefficient * R4_voltage;

	if(abs(input_voltage - old_input_voltage) > 0.1){
		Serial.println(String("ADC: ") + raw_ADC);
		Serial.print("R4 voltage: ");
		Serial.println(R4_voltage, 2);
		Serial.print("input voltage: ");
		Serial.println(input_voltage, 2);
		Serial.println();

		old_input_voltage = input_voltage;
	}
}