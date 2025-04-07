#include <SoftwareSerial.h>

#define txPin 11
#define rxPin 10
#define BUT1 8 
#define BUT2 9
SoftwareSerial bt(rxPin, txPin);
char InfoApp;


void setup() {
  // put your setup code here, to run once:
  bt.flush();
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  bt.begin(9600);
  Serial.begin(9600);
}

void loop() {

    if(digitalRead(BUT1) == HIGH){
      bt.println("1");
      Serial.println("1");
      delay(500);
      }
      if(digitalRead(BUT2) == HIGH){
      bt.println("2");
      Serial.println("2");
      delay(500);
      }

  
}
