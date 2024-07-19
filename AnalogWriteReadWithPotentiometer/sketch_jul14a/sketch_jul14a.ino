// https://support.arduino.cc/hc/en-us/articles/9350537961500-Use-PWM-output-with-Arduino PWM pins

int ANALOG_IN = A0;
int RED_LED_PIN = 10  //3, 5, 6, 9, 10, 11 These pins are PWM means Analog Signals can be between values. For the other pins only on off!;

  void
  setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(ANALOG_IN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Potansiometer values are between 0 - 1023
  int readValue = analogRead(ANALOG_IN);
  Serial.print("Read value is: ");
  Serial.println(readValue);

  // Led brigthness values are between 0 - 255
  int ledBrigthness = readValue * (255. / 1023.);
  Serial.print("Led brigthness is: ");
  Serial.println(ledBrigthness);
  Serial.println("");

  analogWrite(RED_LED_PIN, ledBrigthness);
}
