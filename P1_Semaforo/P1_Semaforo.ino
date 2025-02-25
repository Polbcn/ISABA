/*
  ISABA - 2025
  German Bueno y Pol Pavo
  T12 - Encarna Garcia

*/

#define LED_G 7
#define LED_Y 6
#define LED_R 5
#define PULS 2

int estado_pulsador = 0;


void setup() {
  // put your setup code here, to run once:

  //Definimos los pines
  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(PULS, INPUT_PULLUP);

  //Inicialmente pondremos el semaforo en rojo
  digitalWrite(LED_R, HIGH);
}

void parpadeo_amarillo(){
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  for(int i = 0; i < 5; ++i){
    digitalWrite(LED_Y, HIGH);
    delay(500);
    digitalWrite(LED_Y, LOW);
    delay(500);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  estado_pulsador = digitalRead(PULS);
  //Serial.println(estado_pulsador);
  if(!estado_pulsador){
    delay(1000);
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    delay(5000);
    digitalWrite(LED_G, LOW);
    parpadeo_amarillo();
    digitalWrite(LED_R, HIGH);
    delay(1000);
   } else{
    digitalWrite(LED_R, HIGH);
    }  
  delay(20);
}
