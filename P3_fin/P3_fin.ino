
#include "DHT.h" 
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 
const int EchoPin = 5;                      
const int TriggerPin = 6;
void setup() {
Serial.begin(9600); 
pinMode(TriggerPin, OUTPUT);
pinMode(EchoPin, INPUT);
dht.begin();
}
void loop() {
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 
float llum = analogRead(A1);
float dist = ping(TriggerPin, EchoPin);

//Serial.print("Humedad: ");
Serial.print(h);
Serial.print(" ");
//Serial.print("Temperatura: ");
Serial.print(t);
Serial.print (" ");
if(llum < 1000){
  Serial.print(" ");}
else if(llum < 100){
  Serial.print("  ");}
else if(llum < 10){
  Serial.print("   ");}
Serial.print(llum);
if(llum < 1000){
  Serial.print(" ");}
else if(llum < 100){
  Serial.print("  ");}
else if(llum < 10){
  Serial.print("   ");}
Serial.print (" ");
Serial.println(dist);
delay(2000); 
}

int ping(int TriggerPin, int EchoPin) {
   long duration, distancia;    // Datos tipo long para evitar tener comas flotantes.
   
   digitalWrite(TriggerPin, LOW);    // Ponemos el terminal Trigger a nivel bajo durante 4 us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //Generamos un pulso de alta frecuencia durante 10us (Trigger)
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  // La instrucción pulseIn mide el tiempo que el pulso está en nivel alto en ms.  
   distancia= duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distancia;
}
