int LED_PIN = 3;
int BUTTON_PIN_L = 12;
int BUTTON_PIN_R = 11;
int brigthess = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN_L, INPUT);
  pinMode(BUTTON_PIN_R, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (!digitalRead(BUTTON_PIN_L) && brigthess < 255) {
    brigthess++;
  }

  if (!digitalRead(BUTTON_PIN_R) && brigthess > 0) {
    brigthess--;
  }

  delay(50);

  analogWrite(LED_PIN, brigthess);
}
