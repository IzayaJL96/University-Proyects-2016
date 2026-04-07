//Declaramos librerias a usar.

#include <Ultrasonido.h>

//Declaramos las variables generales.

const int Motor_IN1 = 2;
const int Motor_IN2 = 3;

const int Direccion_IN3 = 4;
const int Direccion_IN4 = 5;

Ultrasonido SensorFrontal=Ultrasonido(6,7); //(Trigger,Echo)
int D_F=0;
Ultrasonido SensorTrasero=Ultrasonido(9,8);
int D_T=0;
Ultrasonido SensorDerecha=Ultrasonido(10,12);
int D_D=0;
Ultrasonido SensorIzquierda=Ultrasonido(11,19);
int D_I=0;

int Seguidor_Frontal = 15;
int Seguidor_Trasero = 17;

void setup() {

//Iniciar la comunicacion en serie.
  Serial.begin(9600);

//Motor y Direccion.
//Se configuran como puertos de salida.
  pinMode (Motor_IN1, OUTPUT);
  pinMode (Motor_IN2, OUTPUT);
  
  pinMode (Direccion_IN3, OUTPUT);
  pinMode (Direccion_IN4, OUTPUT);
  
}

void loop() {

// Seguidor de linea.
  float SeguidorFrontal, SeguidorTrasero, ValorFrontal, ValorTrasero;
  ValorFrontal=analogRead(Seguidor_Frontal);
  ValorTrasero=analogRead(Seguidor_Trasero);
  SeguidorFrontal = ValorFrontal*500/1024;
  SeguidorTrasero = ValorTrasero*500/1024;
  
//Acciones a ejecutar el robot.
//Acciones a ejecutar deteccion de seguidor.
  if (SeguidorFrontal<=480){
    Reversa();
    delay (100);
  }
  
  if (SeguidorTrasero<=480){
    Adelante();
    delay (100);
  }
  
//Acciones a ejecutar deteccion de los sensores.

D_F = SensorFrontal.Distancia();

if (D_F > 0 && D_F < 20){
   Serial.println("FRONTAL:"); 
   Serial.println(D_F);
   Adelante();
} else {
  Detenerse();  
  }

D_T = SensorTrasero.Distancia();

if (D_T > 0 && D_T < 20){
   Serial.println("TRASERO:"); 
   Serial.println(D_T);
   Reversa();
} else {
  Detenerse(); 
  }

D_D = SensorDerecha.Distancia();

if (D_D > 0 && D_D < 15){
   Serial.println("DERECHO:"); 
   Serial.println(D_D);
   Reversa();
} else {
  Detenerse();
  }

D_I = SensorIzquierda.Distancia();

if (D_I > 0 && D_I < 15){
   Serial.println("IZQUIERDO:"); 
   Serial.println(D_I);  
   Reversa();
} else {
  Detenerse();
  }  
}

//Acciones De Motor y Direccion.
  void Adelante(){
    digitalWrite(Motor_IN1, LOW);
    digitalWrite(Motor_IN2, HIGH);  
  }

  void Reversa(){
    digitalWrite(Motor_IN1, HIGH);
    digitalWrite(Motor_IN2, LOW);
  }

  void Derecha(){
    digitalWrite(Direccion_IN3, LOW);
    digitalWrite(Direccion_IN4, HIGH);
    digitalWrite(Motor_IN1, LOW);
    digitalWrite(Motor_IN2, HIGH);
  }

  void Izquierda(){
    digitalWrite(Direccion_IN3, HIGH);
    digitalWrite(Direccion_IN4, LOW);
    digitalWrite(Motor_IN1, LOW);
    digitalWrite(Motor_IN2, HIGH);
  }

  void Detenerse(){
    digitalWrite(Motor_IN1, LOW);
    digitalWrite(Motor_IN2, LOW);
    digitalWrite(Direccion_IN3, LOW);
    digitalWrite(Direccion_IN4, LOW);
  }
