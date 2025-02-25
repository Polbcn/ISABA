/*
  ISABA - 2025
  German Bueno y Pol Pavo
  T12 - Encarna Garcia

*/
#define BRILLO 11  // Pin que fija el brillo del display, conectado al ánodo común
#define SUMA 8     // Pin conectado al pulsador de suma
#define RESET 9    // Pin conectado al pulsador de resta

#define V_MAX 99         // Valor máximo del contador
#define INTENSIDAD 80   //Intensidad del display


//Pins de conexión a los segmentos (cátodos)
#define  segA  0
#define  segB  1
#define  segC  2
#define  segD  3
#define  segE  4
#define  segF  5
#define  segG  6


#define  segA2  10
#define  segB2  14
#define  segC2  15
#define  segD2  16
#define  segE2  17
#define  segF2  18
#define  segG2  19

// Vector con los segmentos que representan los números decimales (0-9)
byte segments[10] = {
// bgfedcba  <--- segmentos
  B00111111, // Número 0
  B00000110, // Número 1
  B01011011, // Número 2
  B01001111, // Número 3
  B01100110, // Número 4
  B01101101, // Número 5
  B01111101, // Número 6
  B00000111, // Número 7
  B01111111, // Número 8
  B01101111  // Número 9
};

void setup(){
  
  pinMode(SUMA, INPUT_PULLUP);       // Se define el pulsador de suma como entrada
  pinMode(RESET, INPUT_PULLUP);      // Se define el pulsador de resta como entrada
  //digitalWrite(RESET, HIGH);      
  //digitalWrite(SUMA, HIGH);
  
// Se definen los pines de conexión de los segmentos como salidas
  //Display1
  pinMode(segA,OUTPUT);
  pinMode(segB,OUTPUT);
  pinMode(segC,OUTPUT);
  pinMode(segD,OUTPUT);
  pinMode(segE,OUTPUT);
  pinMode(segF,OUTPUT);
  pinMode(segG,OUTPUT);
  //Display2
  pinMode(segA2,OUTPUT);
  pinMode(segB2,OUTPUT);
  pinMode(segC2,OUTPUT);
  pinMode(segD2,OUTPUT);
  pinMode(segE2,OUTPUT);
  pinMode(segF2,OUTPUT);
  pinMode(segG2,OUTPUT);
  pinMode(BRILLO,OUTPUT);
  
  analogWrite(BRILLO,255*INTENSIDAD/100);   // Fijamos el brillo del display 
  
}

int INICIAL = 0;                    // El contador inicialmente estará a cero

//================================================================
void loop(){
  Display(INICIAL);


  if(digitalRead(RESET)==0)
  {
   INICIAL = 0;
  }
  if(digitalRead(SUMA)==0)
  {
    if(INICIAL != V_MAX){
      INICIAL++;
      delay(500);
    }else{
      INICIAL = 0;
    }
  }
  
}

/*-------------------------------------------------------------------
Relacionamos los segmentos con los números
--------------------------------------------------------------------*/
void Display(int number){
  byte segs =  ~segments[number%10];        //"~" se usa para el ánodo común

  digitalWrite(segA, bitRead(segs, 0) );
  digitalWrite(segB, bitRead(segs, 1) );
  digitalWrite(segC, bitRead(segs, 2) );
  digitalWrite(segD, bitRead(segs, 3) );
  digitalWrite(segE, bitRead(segs, 4) );
  digitalWrite(segF, bitRead(segs, 5) );
  digitalWrite(segG, bitRead(segs, 6) );
  
  segs =  ~segments[number/10];
  digitalWrite(segA2, bitRead(segs, 0) );
  digitalWrite(segB2, bitRead(segs, 1) );
  digitalWrite(segC2, bitRead(segs, 2) );
  digitalWrite(segD2, bitRead(segs, 3) );
  digitalWrite(segE2, bitRead(segs, 4) );
  digitalWrite(segF2, bitRead(segs, 5) );
  digitalWrite(segG2, bitRead(segs, 6) );
}
