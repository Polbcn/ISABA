#define LED 3
#define PULS 4
#define POTE A1
float valor = 0;
int estado_pulsador = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(POTE, INPUT);
  pinMode(PULS, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PULS) == 0){
    if(estado_pulsador == 0){
      estado_pulsador = 1;
    }else{
      estado_pulsador = 0;
    }
    delay(500);
  }
  valor = estado_pulsador*map(analogRead(POTE), 0, 1023, 0, 255);
  Serial.println(valor);
  analogWrite(LED, valor);
  delay(20);
}
