/*
  ISABA - 2025
  German Bueno y Pol Pavo
  T12 - Encarna Garcia

*/

int LED_pins[] = {7, 6, 5, 8, 9, 10, 11, 12};
int longitud = 8;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < longitud; ++i){
      pinMode(LED_pins[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < longitud; ++i){
      digitalWrite(LED_pins[i], HIGH);
      if(i != 0){
        digitalWrite(LED_pins[i-1], LOW);
      }
      delay(100);
  }
  for(int i = longitud-2; i >= 0; --i){
      digitalWrite(LED_pins[i], HIGH);
       digitalWrite(LED_pins[i+1], LOW);
      delay(100);
  }
}
