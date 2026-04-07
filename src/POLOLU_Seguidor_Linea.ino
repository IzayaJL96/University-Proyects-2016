//librerias
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoMotors.h>
#include <ZumoBuzzer.h>
#include <Pushbutton.h>

// invocacion de librerias
ZumoBuzzer buzzer;
ZumoReflectanceSensorArray reflectanceSensors;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);
//variable que sera utilizada luego
int lastError = 0;

// Velocidad maxima del motor
const int MAX_SPEED = 400;


void setup()// se repite una sola vez
{
  // reproduce sonido inicio
  buzzer.play(">g32>>c32");

  // inicializa el modulo del sensor
  reflectanceSensors.init();

  // espera que presionemos el boton
  button.waitForButton();

  // el led encendido indica que esta preparado para la calibracion
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

 //Espera 1 segundo para empezar la calibracion
  delay(1000);
  
  for(int i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      motors.setSpeeds(-200, 200);
    else
      motors.setSpeeds(200, -200);
    reflectanceSensors.calibrate();

    
    delay(20);
  }
  // pone motor detenido
  motors.setSpeeds(0,0);

  // apaga el led y reproduce el sonido
  digitalWrite(13, LOW);
  buzzer.play(">g32>>c32");

  // espera que presionemos el boton
  button.waitForButton();

  // Reproduce musica del final
  buzzer.play("L16 cdegreg4");
  while(buzzer.isPlaying());
}

void loop() // se repite siempre
{
  unsigned int sensors[6]; // Vector de 6 posicion 

  int position = reflectanceSensors.readLine(sensors); // Creamos variable posicion que guardara lo que lea el sensor

  
  // el error es que tan lejos esta nuestro robot de la linea del centro, que corresponde a la posicion 2500
  int error = position - 2500; // Creamos variable error que sera igual a la posicion 


  // Estamos usando una constante proporcial de 1/4 y una constante derivativa de 6
   // Calcula el término derivativo (cambio) de la posición
  int speedDifference = error / 4 + 6 * (error - lastError);
  
// Recordando la última posición
  lastError = error;

  //determina si el robot va dando la curva a la derecha o izquierda
  int m1Speed = MAX_SPEED + speedDifference;
  int m2Speed = MAX_SPEED - speedDifference;

  // Si velocidad diferencial es mayor a la posible tanto positiva como negativa,
  // asignar la máxima permitida
  if (m1Speed < 0)
    m1Speed = 0;
  if (m2Speed < 0)
    m2Speed = 0;
  if (m1Speed > MAX_SPEED)
    m1Speed = MAX_SPEED;
  if (m2Speed > MAX_SPEED)
    m2Speed = MAX_SPEED;
    
// Asignar velocidad calculada en el poder diferencial de los motores
  motors.setSpeeds(m1Speed, m2Speed);
}
