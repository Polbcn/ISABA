/*
  ISABA - 2025
  German Bueno y Pol Pavo
  T12 - Encarna Garcia

*/

#define LED_R 5
#define LED_G 7

#define PULS 4

int estadoPulsador = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(PULS, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoPulsador = digitalRead(PULS);
  digitalWrite(LED_R, estadoPulsador);
  digitalWrite(LED_G, !estadoPulsador);
}
