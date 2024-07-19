int LED_PIN_0 = 2;
int LED_PIN_1 = 3;
int LED_PIN_2 = 4;
int LED_PIN_3 = 5;
int DELAY_MS = 200;
int STARTER = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN_0, OUTPUT);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  runBinary(STARTER);
  STARTER++;
  STARTER = STARTER % 16;
}


void runBinary(int number) {
  digitalWrite(LED_PIN_0, number % 2);
  number /= 2;
  digitalWrite(LED_PIN_1, number % 2);
  number /= 2;
  digitalWrite(LED_PIN_2, number % 2);
  number /= 2;
  digitalWrite(LED_PIN_3, number % 2);
  delay(DELAY_MS);
}
