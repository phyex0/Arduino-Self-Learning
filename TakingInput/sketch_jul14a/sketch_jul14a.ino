int RED_LED = 10;
int INITIAL_VAL = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  ledValueByUser();
  analogWrite(RED_LED, INITIAL_VAL);
  delay(100);
}

void ledValueByUser() {
  Serial.println("Enter a value between 0 - 255");
  while (!Serial.available());
  
  INITIAL_VAL = Serial.parseInt() % 256;
  Serial.print("Your value is : ");
  Serial.println(INITIAL_VAL);
}
