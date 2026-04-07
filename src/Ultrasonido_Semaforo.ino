/*
  HC-SR04 conexiones:
  VCC al arduino 5v
  GND al arduino GND
  Echo al Arduino pin 11
  Trig al Arduino pin 12
*/

#define P_Echo 11


#define P_Trig 12

long Duracion, distancia;

void setup() {
  Serial.begin (9600);       // Inicializa el puerto seria a 9600 baudios
  pinMode(P_Echo, INPUT);     // Define el pin 11 como entrada (echo)
  pinMode(P_Trig, OUTPUT);    // Define el pin 12 como salida  (triger)
  pinMode(6, OUTPUT);        // Define el pin 6 como salida (LED ROJO)
  pinMode(4, OUTPUT);        // Define el pin 4 como salida (LED AZUL)
  pinMode(2, OUTPUT);        // Define el pin 2 como salida (LED BLANCO)
}

void loop() {

  digitalWrite(P_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(P_Trig, HIGH);   // Genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(P_Trig, LOW);

  Duracion = pulseIn(P_Echo, HIGH);
  distancia = (Duracion / 2) / 29;          // Calcula la distancia en centimetros

  if (distancia >= 500 || distancia <= 0) { // Si la distancia es mayor a 500cm o menor a 0cm
    Serial.println("---");                  // No mide nada
  }
  else {
    Serial.print(distancia);           // Envia el valor de la distancia por el puerto serial
    Serial.println("cm");              // Se coloca a la distancia los centimetros "cm"
    digitalWrite(2, LOW);              // En bajo todos los LED
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
  }

  if (distancia >= 1 && distancia < 5) {
    digitalWrite(6, HIGH);                  // En alto el pin 6 si la distancia es menor a 5cm
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
  }
  else{
    if (distancia >= 1 && distancia < 15) {
    digitalWrite(4, HIGH);                  // En alto el pin 4 si la distancia es menor a 15cm
    digitalWrite(2, HIGH);
    }
    else{
      if (distancia >= 1 && distancia < 30) {
        digitalWrite(2, HIGH);                  // En alto el pin 2 si la distancia es menor a 30cm
      }   
    }
  }
  delay(400);                                // Espera 400ms para que se logre ver la distancia en la consola
}

