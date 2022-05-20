#include "DHT.h"
#define DHTPIN 10
#define DHTTYPE DHT11

int temp,humid;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
 Serial.begin(9600); // put your setup code here, to run once:
Serial.println("Ready");
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    int gas1 = (analogRead(A0)+10.23)/10.23;
    int gas2 = (analogRead(A1)+10.23)/10.23;
    int ldr = 100 - (analogRead(A5)/10.23);
    humid = dht.readHumidity();
    temp = dht.readTemperature();
Serial.print('$');
Serial.print(gas1);
Serial.print('G');
Serial.print(gas2);
Serial.print('L');
Serial.print(ldr);
Serial.print('T');
Serial.print(temp);
Serial.print('H');
Serial.print(humid);
Serial.println('#');
delay(100);
}
