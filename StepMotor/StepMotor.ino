#include <Stepper.h>
int FULL_TOUR = 2048;
int SPEED = 10;

int IN_1 = 8;
int IN_2 = 9;
int IN_3 = 10;
int IN_4 = 11;
int Buton = 3;
int ButonVal = 0;

Stepper stepper(FULL_TOUR, IN_1, IN_3, IN_2, IN_4); //IDK WHY IN THIS ORDER?

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setSpeed(SPEED);
  pinMode(Buton, INPUT);
  digitalWrite(Buton, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  ButonVal = digitalRead(Buton);
  Serial.println(ButonVal);

  if (!ButonVal) {
    FULL_TOUR *= -1;
  }
  stepper.step(FULL_TOUR);
}
