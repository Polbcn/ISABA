int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int data;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    data = Serial.read();
    if(data == '1'){
       digitalWrite(LED1, HIGH);
     }
    if(data == '2'){
      digitalWrite(LED2, HIGH);
      }
    if(data == '3'){
      digitalWrite(LED3, HIGH);
      }
    if(data == '0'){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      } 
   }
}
