#include <DHT.h>
#include <DHT_U.h>
#define TYPE DHT11

int dataPin = 2;
DHT dht(dataPin, TYPE);

float humidty;
float tempC;
float tempF;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
 

}

void loop() {
  // put your main code here, to run repeatedly:
  humidty = dht.readHumidity();
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);

  Serial.print("Humidity is: ");
  Serial.print(humidty);

  Serial.print(" TempC is: ");
  Serial.print(tempC);

   Serial.print(" TempF is: ");
  Serial.println(tempF);

  delay(1000);
}
