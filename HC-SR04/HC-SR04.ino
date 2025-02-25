/***********************************************************************************************
 PROGRAMACIÓN SENSOR DE DISTANCIA HC-SR04

Encarna Garcia                  Enero 2019
 **********************************************************************************************/

const int EchoPin = 5;                      
const int TriggerPin = 6;
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 7
#define LED5 8

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
   pinMode(LED5, OUTPUT);
}
 
void loop() {
   int distancia = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(distancia);
   if(distancia < 20){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
   }else if(distancia < 25){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
   }else if(distancia < 30){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
   }
   else if(distancia < 35){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
   }
   else if(distancia < 25){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
   }else{
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    }
   delay(1000);
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
