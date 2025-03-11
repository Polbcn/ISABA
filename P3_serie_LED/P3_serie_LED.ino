int LED = 13;
int data;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    data = Serial.read();
    if(data == '1'){
       digitalWrite(LED, HIGH);
     }
    if(data == '0'){
      digitalWrite(LED, LOW);
      } 
   }
}
