//Declaramos las variables generales.

const int Motor1_IN1 = 2;
const int Motor1_IN2 = 3;

const int Motor2_IN3 = 4;
const int Motor2_IN4 = 5;


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
//Acciones a ejecutar el robot.

  Adelante();
  delay (10000);
  
  Derecha();
  delay(3000);

  Adelante();
  delay (10000);

  Izquierda();
  delay(3000);

  Reversa();
  delay(10000);

  Detenerse();

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
