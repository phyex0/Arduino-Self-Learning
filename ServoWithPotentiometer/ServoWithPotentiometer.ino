#include <Servo.h>
int SERVO_PIN = 9;
int SERVO_ANGLE = 0;
int POTANTIOMETER = A4;
int POTANTIOMETER_VAL = 0;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  pinMode(POTANTIOMETER, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  POTANTIOMETER_VAL = analogRead(POTANTIOMETER);
  SERVO_ANGLE = POTANTIOMETER_VAL * (180. / 1023.);
  servo.write(SERVO_ANGLE);

  Serial.print("Servo Angle is: ");
  Serial.println(SERVO_ANGLE);
  delay(50);
}
