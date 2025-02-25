/*
  ISABA - 2025
  German Bueno y Pol Pavo
  T12 - Encarna Garcia

*/

#define LED1_G 7
#define LED1_Y 6
#define LED1_R 5

#define LED2_G 8
#define LED2_Y 9
#define LED2_R 10

#define PULS 4

int estado_pulsador = 0;


void setup() {
  // put your setup code here, to run once:

  //Definimos los pines
  pinMode(LED1_G, OUTPUT);
  pinMode(LED1_Y, OUTPUT);
  pinMode(LED1_R, OUTPUT);
  pinMode(LED2_G, OUTPUT);
  pinMode(LED2_Y, OUTPUT);
  pinMode(LED2_R, OUTPUT);
  pinMode(PULS, INPUT_PULLUP);

  //Inicialmente pondremos el semaforo en rojo
  digitalWrite(LED1_R, HIGH);
  digitalWrite(LED2_G, HIGH);
}

void verdeArojo(int pinG, int pinY, int pinR){
  digitalWrite(pinG, LOW);
  digitalWrite(pinY, LOW);
  for(int i = 0; i < 5; ++i){
    digitalWrite(pinY, HIGH);
    delay(500);
    digitalWrite(pinY, LOW);
    delay(500);
    }
   digitalWrite(pinR, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  estado_pulsador = digitalRead(PULS);
  //Serial.println(estado_pulsador);
  if(!estado_pulsador){
    verdeArojo(LED2_G, LED2_Y, LED2_R);
    digitalWrite(LED1_R, LOW);
    digitalWrite(LED1_G, HIGH);
    delay(2000);
    verdeArojo(LED1_G, LED1_Y, LED1_R);
    digitalWrite(LED2_R, LOW);
    digitalWrite(LED2_G, HIGH);
   } else{
    digitalWrite(LED1_R, HIGH);
    digitalWrite(LED2_G, HIGH);
   }  
   delay(20);
}
