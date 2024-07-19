#include <IRremote.hpp>
#define IR_RECEIVE_PIN 11

int buzz = 2;
int led = 3;

byte readVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  pinMode(buzz, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print "old" raw data
    //IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    // IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    runComponenet(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume();  // Enable receiving of the next value
  }
}

void runComponenet(unsigned long hexVal) {

  if (hexVal == 0xF708FF00) {
  //LEFT
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
  } else if (hexVal == 0xA55AFF00) {
    //RIGHT
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
  }
}
