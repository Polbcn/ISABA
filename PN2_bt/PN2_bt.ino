#include <SoftwareSerial.h>

#define txPin 11
#define rxPin 10

SoftwareSerial bt(rxPin, txPin);
char InfoApp;
int LED = 2;
int LED1 = 3;
int LED2 = 4;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  bt.flush();
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  bt.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(bt.available()){
    // put your main code here, to run repeatedly:
    InfoApp = bt.read();
    Serial.println(InfoApp);
    if(InfoApp == '2'){
      digitalWrite(LED, LOW);
    }else if(InfoApp == '1'){
      digitalWrite(LED, HIGH);
    }
    if(InfoApp == '3'){
      digitalWrite(LED1, HIGH);
    }else if(InfoApp == '4'){
      digitalWrite(LED1, LOW);
    }
    if(InfoApp == '5'){
      digitalWrite(LED2, HIGH);
    }else if(InfoApp == '6'){
      digitalWrite(LED2, LOW);
    }
  }
  
}
