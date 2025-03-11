
#include "DHT.h" 
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
Serial.begin(9600); 
dht.begin();
}
void loop() {
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 

//Serial.print("Humedad: ");
Serial.print(h);
Serial.print(" %  ");
//Serial.print("Temperatura: ");
Serial.print(t);
Serial.println (" oC");
delay(2000); 
}
