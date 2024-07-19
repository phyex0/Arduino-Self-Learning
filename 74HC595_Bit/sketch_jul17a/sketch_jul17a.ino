// https://toptechboy.com/arduino-tutorial-42-understanding-how-to-use-a-serial-to-parallel-shift-register-74hc595/#google_vignette
int DATA = 12;
int LATCH = 11;
int CLOCK = 9;

byte LED = 0B0101010111;

int dt = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, LSBFIRST, LED);
  digitalWrite(LATCH, HIGH);

  delay(dt);
 
}
