//https://toptechboy.com/arduino-tutorial-48-connecting-and-using-an-lcd-display/

#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int num1 = 0;
int num2 = 0;
int result = 0;

String text1 = "";
String s1 = "Enter first number";
String s2 = "Enter second number";
String s3 = "Enter operator (+ - * /)";
String s4 = "Your output is:";



void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print(s1);

  while (!Serial.available())
    ;
  num1 = Serial.parseInt();

  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s2);

  while (!Serial.available())
    ;
  num2 = Serial.parseInt();

  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s3);

  while (!Serial.available())
    ;
  text1 = Serial.readString();

  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(s4);

  lcd.setCursor(0, 1);
  lcd.print(num1);
  lcd.print(text1);
  lcd.print(num2);
  lcd.print("=");

  if (text1 == "+") {
    result = num1 + num2;
  } else if (text1 == "-") {
    result = num1 - num2;
  } else if (text1 == "*") {
    result = num1 * num2;
  } else {
    result = num1 / num2;
  }


  lcd.print(result);
  delay(10000);
  lcd.clear();
}
