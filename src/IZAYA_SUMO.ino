//Declaramos librerias a usar.

#include <Ultrasonido.h>

//Declaramos las variables generales.

const int Motor1_IN1 = 2; //Motor Izquierdo
const int Motor1_IN2 = 3;

const int Motor2_IN3 = 4;//Motor Derecho
const int Motor2_IN4 = 5;

Ultrasonido SensorFrontal=Ultrasonido(6,7); //(Trigger,Echo) Ultrasonido
int D_F=0;

int Seguidor_Frontal = 15; //Seguidor de linea en pines analogicos.

void setup() {
  
//Iniciar la comunicacion en serie.
  Serial.begin(9600);

//Motor y Direccion.
//Se configuran como puertos de salida.
  pinMode (Motor1_IN1, OUTPUT);
  pinMode (Motor1_IN2, OUTPUT);
  
  pinMode (Motor2_IN3, OUTPUT);
  pinMode (Motor2_IN4, OUTPUT);
  
}

void loop() {
  
// Seguidor de linea.
  float SeguidorFrontal, ValorFrontal;
  ValorFrontal=analogRead(Seguidor_Frontal);
  SeguidorFrontal = ValorFrontal*500/1024;

//Acciones a ejecutar deteccion de seguidor.
  if (SeguidorFrontal<=480){
    Reversa();
    delay (100);
  }

//Acciones a ejecutar el robot.
D_F = SensorFrontal.Distancia();

if (D_F > 0 && D_F < 20){
   Serial.println("FRONTAL:"); 
   Serial.println(D_F);
   Adelante();
} else {
  Detenerse();  
  }
  
}

 void Detenerse(){
    digitalWrite(Motor1_IN1, LOW);
    digitalWrite(Motor1_IN2, LOW);
    digitalWrite(Motor2_IN3, LOW);
    digitalWrite(Motor2_IN4, LOW);
  }

 void Adelante(){
    digitalWrite(Motor1_IN1, LOW);
    digitalWrite(Motor1_IN2, HIGH);
    digitalWrite(Motor2_IN3, LOW);
    digitalWrite(Motor2_IN4, HIGH);
  }
  
void Reversa(){
    digitalWrite(Motor1_IN1, HIGH);
    digitalWrite(Motor1_IN2, LOW);
    digitalWrite(Motor2_IN3, HIGH);
    digitalWrite(Motor2_IN4, LOW);
  }

void Derecha(){
    digitalWrite(Motor1_IN1, LOW);
    digitalWrite(Motor1_IN2, HIGH);
    digitalWrite(Motor2_IN3, HIGH);
    digitalWrite(Motor2_IN4, LOW);
  }

void Izquierda(){
    digitalWrite(Motor1_IN1, HIGH);
    digitalWrite(Motor1_IN2, LOW);
    digitalWrite(Motor2_IN3, LOW);
    digitalWrite(Motor2_IN4, HIGH);
  }
