//Guidence how does the L293D DC Motor driver runs https://wiki-content.arduino.cc/documents/datasheets/H-bridge_motor_driver.PDF
/*
          1 EN1   -||-  16  v+
          2 IN1   -||-  15  IN4
          3 OUT1  -||-  14  OUT4
          4 0V    -||-  13  0V
          5 0V    -||-  12  0V
          6 OUT2  -||-  11  OUT3
          7 IN2   -||-  10  IN3
          8 VS    -||-  9   EN2

      1 => Controls speed. Analog Write
      2, 7 => Directions. 2 High 7 Low one direction. 2 Low 7 Hight to Other direction
      3,6 => Connects to Motor
      4,5 => Ground
      8 => Positive Voltage 
*/

int speedPin = 5;   //PWM EN1
int dir1 = 4;       //IN1
int dir2 = 3;       //IN2
int speed = 100;    // Between 0 - 255



void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  analogWrite(speedPin, speed);
}
