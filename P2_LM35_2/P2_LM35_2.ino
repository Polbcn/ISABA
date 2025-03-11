/*
  ISABA - 2025
  German Bueno y Pol Pavo
  T12 - Encarna Garcia

*/
float temperatura;
int tempPin = 1;
int T = 0;
#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
float k = 0.048828125;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(tempPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperatura = analogRead(A1);
  //Serial.println(tempPin);
  temperatura = temperatura * k;
  Serial.println(temperatura);
  if(temperatura > 26){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }else if(temperatura > 24){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }else if(temperatura > 22){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }else if(temperatura > 20){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }else{
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
   }
  delay(200);
  
}
