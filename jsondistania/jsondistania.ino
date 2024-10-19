#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino_JSON.h>

#define I2C_ADDR    0x27

#define trigPin 13
#define echoPin 12

#define trig2Pin 11
#define echo2Pin 10


#define led2 2
#define led1 1
#define buzzer 3

// Variables globales
int counter = 0;
int counter2 = 0;

LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);


void setup() {
Serial.begin(9600);
    lcd.begin(16, 2); 
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);

  
}

void loop() {
  
  double duracion;
  double distancia;
  double duracion2;
  double distancia2;

//aqui vamos a calcular distancia con el primer sensor
    digitalWrite(trigPin, LOW);        
    delayMicroseconds(2);              
    digitalWrite(trigPin, HIGH);       
    delayMicroseconds(10);             
    digitalWrite(trigPin, LOW);        

    duracion = pulseIn(echoPin, HIGH);
    distancia = duracion / 2 / 29.1;

//aqui vamos a calcular distancia con el segundo sensor
    digitalWrite(trig2Pin, LOW);        
    delayMicroseconds(2);              
    digitalWrite(trig2Pin, HIGH);       
    delayMicroseconds(10);             
    digitalWrite(trig2Pin, LOW);        

    duracion2 = pulseIn(echo2Pin, HIGH);
    distancia2 = duracion2 / 2 / 29.1;




    Serial.print(9.4-distancia);
    Serial.print(",");
    Serial.println(0);
    
       lcd.home ();                  
       lcd.print("Altura");
       lcd.setCursor ( 0, 1 );    
       lcd.print(9.4-distancia);
       lcd.print("cm       ");

lcd.print("");
delayMicroseconds(2);

    delay(100);
}