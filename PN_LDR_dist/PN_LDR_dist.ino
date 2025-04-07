#include <SoftwareSerial.h>

#define txPin 11
#define rxPin 10
#define LDR A7 
#define trigger 5
#define echo 6
SoftwareSerial bt(rxPin, txPin);
char InfoApp;


void setup() {
  // put your setup code here, to run once:
  bt.flush();
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  bt.begin(9600);
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
   pinMode(echo, INPUT);
}

void loop() {
    int distancia = ping(trigger, echo);
    int valor = analogRead(LDR);
    Serial.println(valor);
    Serial.println(distancia);
    if(distancia < 50){
      bt.println("1");
      Serial.println("1");
      delay(500);
      }
      if(valor < 200){
      bt.println("2");
      Serial.println("2");
      delay(500);
      }

  
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
