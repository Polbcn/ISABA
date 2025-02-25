 /*
  DISPLAY 7-SEGMENTOS
  Programa que simula un contador, con dos pulsadores. Un pulsador suma unidades, y el otro resta.
  El programa fija el valor máximo del contador. 

  BCN Genuino Team - 1 Abril 2016  */

#define BRILLO 11  // Pin que fija el brillo del display, conectado al ánodo común
#define SUMA 8     // Pin conectado al pulsador de suma
#define RESTA 9    // Pin conectado al pulsador de resta

#define V_MAX 9         // Valor máximo del contador
#define INTENSIDAD 80   //Intensidad del display


//Pins de conexión a los segmentos (cátodos)
#define  segA  0
#define  segB  1
#define  segC  2
#define  segD  3
#define  segE  4
#define  segF  5
#define  segG  6

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
  
  pinMode(SUMA, INPUT);       // Se define el pulsador de suma como entrada
  pinMode(RESTA, INPUT);      // Se define el pulsador de resta como entrada
  digitalWrite(RESTA, HIGH);      
  digitalWrite(SUMA, HIGH);
  
// Se definen los pines de conexión de los segmentos como salidas
  pinMode(segA,OUTPUT);
  pinMode(segB,OUTPUT);
  pinMode(segC,OUTPUT);
  pinMode(segD,OUTPUT);
  pinMode(segE,OUTPUT);
  pinMode(segF,OUTPUT);
  pinMode(segG,OUTPUT);
  pinMode(BRILLO,OUTPUT);
  
  analogWrite(BRILLO,255*INTENSIDAD/100);   // Fijamos el brillo del display 
  
}

int  INICIAL= 0;                    // El contador inicialmente estará a cero

//================================================================
void loop(){
  Display(INICIAL);


  if(digitalRead(RESTA)==0)
  {
   if(INICIAL != 0){
     INICIAL--;
     delay(500);
    }
  }
  if(digitalRead(SUMA)==0)
  {
    if(INICIAL != V_MAX){
      INICIAL++;
      delay(500);
    }
  }
}

/*-------------------------------------------------------------------
Relacionamos los segmentos con los números
--------------------------------------------------------------------*/
void Display(int number){
  byte segs =  ~segments[number];        //"~" se usa para el ánodo común

  digitalWrite(segA, bitRead(segs, 0) );
  digitalWrite(segB, bitRead(segs, 1) );
  digitalWrite(segC, bitRead(segs, 2) );
  digitalWrite(segD, bitRead(segs, 3) );
  digitalWrite(segE, bitRead(segs, 4) );
  digitalWrite(segF, bitRead(segs, 5) );
  digitalWrite(segG, bitRead(segs, 6) );
}
