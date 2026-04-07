//Definiciones de variables.
int Prueba = 13;   //definimos el valor del pin para el led de prueba.
int Rojo = 2;      //definimos el valor del pin para el led rojo.
int Amarillo = 3;  //definimos el valor del pin para el led amarillo.
int Verde = 4;     //definimos el valor del pin para el led verde.
int milisegundos = 1000; // definimos la cantidad de milisegundos (un segundo).

//Programa.

void setup() {
  pinMode(Prueba, OUTPUT);    //declaramos el pin prueba como salida.
  pinMode(Rojo, OUTPUT);     //declaramos el pin rojo como salida.
  pinMode(Amarillo, OUTPUT); //declaramos el pin amarillo como salida.
  pinMode(Verde, OUTPUT);    //declaramos el pin verde como salida.
}

void loop() {
  digitalWrite(Prueba,HIGH); //encendemos el led prueba.
  
  digitalWrite(Rojo,HIGH); //encendemos el led rojo.
  delay(milisegundos * 2); //esperamos 2 segundos.
  digitalWrite(Rojo,LOW);  //apagamos el led rojo.
  delay(milisegundos / 2); //esperamos medio segundo.
  
  digitalWrite(Amarillo,HIGH); //encendemos el led amarillo.
  delay(milisegundos * 2); //esperamos 2 segundos.
  digitalWrite(Amarillo,LOW);  //apagamos el led amarillo.
  delay(milisegundos / 2); //esperamos medio segundo.
  
  digitalWrite(Verde,HIGH);  //encendemos el led verde.
  delay(milisegundos * 2); //esperamos 2 segundos.
  digitalWrite(Verde,LOW);   //apagamos el led verde.
  delay(milisegundos / 2); //esperamos medio segundo.
}
