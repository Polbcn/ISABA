#include <SoftwareSerial.h>

#define txPin 11
#define rxPin 10
#define echo 8 
#define trigger 9
#define LDR A7
SoftwareSerial bt(rxPin, txPin);
char InfoApp;


void setup() {
  // put your setup code here, to run once:
  bt.flush();
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(LDR, INPUT);
  bt.begin(9600);
  Serial.begin(9600);
}

void loop() {
    int distancia = ping(trigger, echo);
    if(analogRead(LDR) < 200){
      bt.println("1");
      Serial.println("1");
      delay(500);
      }
      if(distancia < 50){
      bt.println("2");
      Serial.println("2");
      delay(500);
      }

  
}
