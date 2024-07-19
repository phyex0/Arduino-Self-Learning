int trigger = 4;
int echo = 3;
int pingTravelTime;

int buzz = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  delayMicroseconds(10);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  pingTravelTime = pulseIn(echo, HIGH);
  delay(25);
  Serial.println(pingTravelTime);


  if (pingTravelTime < 200) {
    digitalWrite(buzz, HIGH);
  } else if (pingTravelTime < 400) {
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
  } else if (pingTravelTime < 800) {
    digitalWrite(buzz, HIGH);
    delay(200);
    digitalWrite(buzz, LOW);
    delay(200);
  } else if (pingTravelTime < 1000) {
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    delay(500);
  } else{
    digitalWrite(buzz, LOW);
  }
}