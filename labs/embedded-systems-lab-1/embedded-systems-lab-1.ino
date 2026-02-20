// **************
// Question 10:
byte pinA = 5;
byte pinB = 6;
byte pinC = 7;
byte pinD = 8;

byte led1 = 3;
byte led2 = 4;

byte previousS1State = LOW;
byte previousS2State = LOW;
byte previousS3State = LOW;
byte previousS4State = LOW;
// **************


void setup() {
  // put your setup code here, to run once:
  // ************
  // Questions 7 & 8:
  // pinMode(2, OUTPUT);
  // ************

  // **************
  // Question 9:
  //  pinMode(LED_BUILTIN, OUTPUT);
  //  pinMode(5, INPUT);
  // **************

  // **************
  // Question 10:
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(pinD, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  // **************
}

void loop() {
  // put your main code here, to run repeatedly:
  // ************
  // Question 7:
  // digitalWrite(2, HIGH);
  // delayMicroseconds(500);
  // digitalWrite(2, LOW);
  // delayMicroseconds(500);
  // *************

  // *************
  // Question 8:
  // digitalWrite(2, HIGH);
  // delayMicroseconds(500);
  // digitalWrite(2, LOW);
  // delayMicroseconds(500);
  // **************

  // **************
  // Question 9:
  //  byte pin5 = digitalRead(5);
  //  digitalWrite(LED_BUILTIN, !pin5);
  // **************

  // **************
  // Question 10:
  byte s1 = !digitalRead(pinA);
  byte s2 = !digitalRead(pinB);
  byte s3 = !digitalRead(pinC);
  byte s4 = !digitalRead(pinD);

  if (
    s1 != previousS1State || s2 != previousS2State || s3 != previousS3State || s4 != previousS4State) {

    previousS1State = s1;
    previousS2State = s2;
    previousS3State = s3;
    previousS4State = s4;


    Serial.print("S1 ");
    if (s1 == HIGH) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }

    Serial.print("S2 ");
    if (s2 == HIGH) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }

    Serial.print("S3 ");
    if (s3 == HIGH) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }

    Serial.print("S4 ");
    if (s4 == HIGH) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }

    Serial.println();
  }

  byte conditionY1 = (s1 && s2) || (s3 && s4);
  byte conditionY2 = (s1 || s2) && (s3 || s4);

  digitalWrite(led1, conditionY1);
  digitalWrite(led2, conditionY2);

  if (Serial.available() != 0) {

    String mystring = Serial.readString();
    mystring.trim();
    byte number = mystring.toInt();

    if (number == 1) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else if (number == 2) {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  // **************
}
