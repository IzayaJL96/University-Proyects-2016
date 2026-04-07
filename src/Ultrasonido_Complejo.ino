/*
HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 6 
  Trig al Arduino pin 7
 */

#define P_Echo 11
#define P_Trig 12

long Duracion, distancia;   
 
void setup() {                
  Serial.begin (9600);       // Inicializa el puerto seria a 9600 baudios
  pinMode(P_Echo, INPUT);     // Define el pin 6 como entrada (echo)
  pinMode(P_Trig, OUTPUT);    // Define el pin 7 como salida  (triger)
  }
  
void loop() {
  
  digitalWrite(P_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(P_Trig, HIGH);   // Genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(P_Trig, LOW);
  
  Duracion = pulseIn(P_Echo, HIGH);
  distancia = (Duracion/2) / 29;            // Calcula la distancia en centimetros
  
  if (distancia >= 500 || distancia <= 0){  // Si la distancia es mayor a 500cm o menor a 0cm 
    Serial.println("---");                  // No mide nada
  }
  else {
    Serial.print(distancia);           // Envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // Se coloca a la distancia los centimetros "cm"
  }
}
