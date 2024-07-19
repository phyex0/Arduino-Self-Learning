int RED_LED = 6;
int YELLOW_RED = 9;
int DELAY_MS = 300;
int SERIAL_BAUND = 9600;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_RED, OUTPUT);
  Serial.begin(SERIAL_BAUND);
}

void loop() {
  // put your main code here, to run repeatedly:
  int randomVal = random(1, 13);
  
  Serial.print("The random value is: ");
  Serial.println(randomVal);

  if (randomVal < 6) {
    flashTheLed(YELLOW_RED, randomVal);
  } else if (randomVal >= 6 && randomVal <= 9) {
    flashTheLed(YELLOW_RED, randomVal);
    flashTheLed(RED_LED, randomVal);
  } else {
    flashTheLed(RED_LED, randomVal);
  }
}


void flashTheLed(int ledPin, int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPin, HIGH);
    delay(DELAY_MS);
    digitalWrite(ledPin, LOW);
    delay(DELAY_MS);
  }
  delay(DELAY_MS * 2);
}
