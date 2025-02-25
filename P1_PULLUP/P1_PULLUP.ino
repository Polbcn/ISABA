/*
  ISABA - 2025
  German Bueno y Pol Pavo
  T12 - Encarna Garcia

*/

#define PULS 4

int LED_pins[] = {7, 6, 5, 8, 9, 10, 11, 12};
int longitud = 8;
int dt = 500;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < longitud; ++i){
      pinMode(LED_pins[i], OUTPUT);
  }
  pinMode(PULS, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(PULS)){
    dt = 250;
  }else{
    dt = 500;
  }
  for(int i = 0; i < longitud; ++i){
      digitalWrite(LED_pins[i], HIGH);
    }
    delay(dt);
    for(int i = 0; i < longitud; ++i){
      digitalWrite(LED_pins[i], LOW);
    }
    delay(dt);
}
