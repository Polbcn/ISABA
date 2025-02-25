float temperatura;
int tempPin = 1;
int T = 0;
#define LED 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperatura = analogRead(tempPin);
  temperatura = temperatura * 0.48828125;
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.println(" ºC");
  
  T = -10*(temperatura-5)+1000;
  if(temperatura < 15) T = 1000;
  Serial.println(T);
  digitalWrite(LED, HIGH);
  delay(T/2);
  digitalWrite(LED, LOW);
  delay(T/2);
  
  
  //delay(1000);
  
}
