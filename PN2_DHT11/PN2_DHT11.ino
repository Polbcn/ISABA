#include <SoftwareSerial.h>

#define txPin 11
#define rxPin 10

SoftwareSerial bt(rxPin, txPin);
char InfoApp;
#include "DHT.h" 
#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  Serial.begin(9600); 
  dht.begin();
  bt.flush();
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  bt.begin(9600);
}
void loop() {
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 
  String a = String(h)+" %    | " +String(t)+" ºC";
  bt.println(a);
  //Serial.print("Humedad: ");
  Serial.print(t);
  //Serial.print(" %  ");
  Serial.print(" ");
  Serial.print(h);
  Serial.println (" oC");
  delay(2000); 
}
