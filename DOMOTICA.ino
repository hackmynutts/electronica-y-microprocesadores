//LIBRERIAS DE PROYECTO
#include <LiquidCrystal.h>

//variables de pin 
int pinLM35= 0; //A0 porque tiene que estar en un analogico
int enableBridge1 = 2; //salida de brigdeH 
int MotorForward1 = 3; //digitales
int MotorReverse1 = 5; //digitales
int pinLCD1 = 7; // DIGITAL
int pinLCD2 = 8;
int pinLCD3 = 9;
int pinLCD4 = 10;
int pinLCD5 = 11;
int pinLCD6 = 12;

LiquidCrystal lcd(7,8,9,10,11,12); //creamos un obj de tipi LiquidCrystal para asi asignarles los pines
float tempC;
int Power = 255; //Motor velocity between 0 and 255

//fin/
void setup() {
Serial.begin(9600);
analogReference(DEFAULT);
pinMode(pinLM35, INPUT);//ENTRADA DEL SENSOR DE TEMPERATURA
pinMode(MotorForward1,OUTPUT); //salida
pinMode(MotorReverse1,OUTPUT); //salida
pinMode(enableBridge1,INPUT); //input
lcd.begin(16,2); //iniciamos la pantalla y le indicamos el tamaño (#columnas, #lineas )
}

void loop() {
//analogRead leemos el sensor, valores entre 0 a 1023
tempC= analogRead(pinLM35);
int temperatura;
temperatura= ((tempC * 5 / 1024) / 0.01);
Serial.print(temperatura);
lcd.setCursor(0,0); //la linea donde queremos escribir
lcd.print(temperatura);
lcd.print("° Celcios."); //imprimimos en la pantalla
Serial.print("\n");
delay(2000);
digitalWrite(enableBridge1,HIGH); // Activo puenteH
  // movimiento hacia adelantre
  analogWrite(MotorReverse1,0);
  analogWrite(MotorForward1,Power);
  delay(2000);
  // movimiento atras
  analogWrite(MotorForward1,0);
  analogWrite(MotorReverse1,Power);
  delay(3000);
  //Arrête le moteur pendant 1 seconde
  analogWrite(MotorForward1,0);
  analogWrite(MotorReverse1,0);
  digitalWrite(enableBridge1,LOW);
  delay(1000);
}