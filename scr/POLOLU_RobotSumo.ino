#include <ZumoBuzzer.h> // Libreria de sonido 
#include <ZumoMotors.h> // Libreria de motores
#include <Pushbutton.h> // Libreria de boton
#include <QTRSensors.h> //LIBRERIA DE SENSOR DE LINEA
#include <ZumoReflectanceSensorArray.h>// LIBRERIA DE SENSOR DE LINEA : CALIBRACION
 
#define LED 13 // LED en el pin 13
#define trigPin 2  // trig para sonido
#define echoPin 3  //echo para sonido

// this might need to be tuned for different lighting conditions, surfaces, etc.
#define QTR_THRESHOLD  1500 //  NEGRO - CALIBRACION SENSOR DE LINEA
  
// these might need to be tuned for different motor types
#define REVERSE_SPEED     200 // 0 is stopped, 400 is full speed
#define TURN_SPEED        200 // VELOCIDAD DE GIRO
#define FORWARD_SPEED     200 // VELOCIDAD DERECHO
#define REVERSE_DURATION  250 // ms
#define TURN_DURATION     400 // ms DURACION DE GIRO
 
ZumoBuzzer buzzer; //INVOCO LIBRERIA DE SONIDO
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
 
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS]; // VECTOR SENSOR DE LINEA
 
ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);


void waitForButtonAndCountDown() //CONTEO 
{
  digitalWrite(LED, HIGH);
  button.waitForButton();
  digitalWrite(LED, LOW);
   
  // play audible countdown
  for (int i = 0; i < 3; i++)
  {
    delay(1000);
    buzzer.playNote(NOTE_G(3), 200, 15);
  }
  delay(1000);
  buzzer.playNote(NOTE_G(4), 500, 15);  
  delay(1000);
  digitalWrite(LED, HIGH);
  button.waitForButton();
  digitalWrite(LED, LOW);
  delay(5000);
  }
 
void setup()
{
  // uncomment if necessary to correct motor directions
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, HIGH);
  waitForButtonAndCountDown();
}

void loop()
{
  // --------------------------Si presionamos el botón que inicie el conteo y sonido// --------------------------
  if (button.isPressed())
  {
    // if button is pressed, stop and wait for another press to go again
    motors.setSpeeds(0, 0);
    button.waitForRelease();
    waitForButtonAndCountDown();
  }
   // --------------------------// --------------------------// --------------------------// --------------------------

  sensors.read(sensor_values); // LEE TIERRA 
  // --------------------------Detectando los bordes de la plataforma// --------------------------
  if (sensor_values[0] < QTR_THRESHOLD || sensor_values[5] < QTR_THRESHOLD)
  {
    // if leftmost sensor detects line, reverse and turn to the right
    motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
    delay(REVERSE_DURATION);
    motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
    delay(TURN_DURATION);
    motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
  }
  
  // --------------------------// --------------------------// --------------------------// --------------------------
  else
  {
    // --------------------------lanzamiento de ondas, calculo de distancia y deteccion de enemigos// --------------------------
    
    long duration, distance;
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;  // FORMULA DISTANCIA
    delay(10);
    // --------------------------// --------------------------// --------------------------// --------------------------// --------------------------
    
   
    
    // --------------------------Si encontro algo en un rango de 30 cm entonces que siga adelante// --------------------------
    if(distance<=20){
      motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
      
  
    }
    else{
      // otherwise, go straight
      motors.setSpeeds(-FORWARD_SPEED, FORWARD_SPEED);  // MOVIMIENTO NORMAL DEL ROBOT SI NO ENCUENTRA NADA
      
    }
    

     
    
    // --------------------------// --------------------------// --------------------------// --------------------------
  }
}
