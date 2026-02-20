const char analog_input = A0;
float old_temp= 0;

int BIT = 10;
int ADC_Max = (1 << BIT) -1;
float Ref_voltage = 4950;   //unit is milli volt

float R1 = 1000;
float R2 = 10000;

float sensitivity = 10;

int temperature_difference = 1;

void setup () {
	pinMode(analog_input, INPUT);
	Serial.begin(9600);
}

void loop() {
	float raw_ADC = analogRead(analog_input);
	float Uout_Amp = (raw_ADC/ (float)ADC_Max) * Ref_voltage;  //unit is mV
	float Uout_sensor = (Uout_Amp * R1) / ( R1 + R2 );         //unit is mV
	float temperature = Uout_sensor / sensitivity;

	if(abs(old_temp - temperature) > temperature_difference){
		Serial.println(String("temperature ") + temperature);
		Serial.print("U out of sensor (mV): ");
		Serial.println(Uout_sensor, 2);
		Serial.print("U out of amplifier (mV): ");
		Serial.println(Uout_Amp, 2);
		Serial.println();
		old_temp = temperature;
	}
}