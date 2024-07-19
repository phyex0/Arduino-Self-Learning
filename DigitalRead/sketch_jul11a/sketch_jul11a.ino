int readPin = A2;
int value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(readPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(readPin);
  Serial.println("Read Voltage is: " + (value * 5.0 / 1023.0));
  delay(100);
}
