/*
 * LAB Name: Arduino Button Debouncing (Delay)
 * Author: Khaled Magdy
 * For More Info Visit: www.DeepBlueMbedded.com
*/

const int buttonPin = 7;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
int btnState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  btnState = digitalRead(buttonPin);
  if(btnState == HIGH)
  {
    delay(20);
    btnState = digitalRead(buttonPin);
    if(btnState == HIGH)
    {
      // Toggle The Output LED Pin
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
  }
}