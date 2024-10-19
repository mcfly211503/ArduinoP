#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27

#define trigPin 13
#define echoPin 12
#define led2 2
#define led1 1
#define buzzer 3

// Variables globales
int counter = 0;
int counter2 = 0;

LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
void setup() {

    
    // Configuración de la pantalla LCD
    lcd.begin(16, 2); 
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);

  
}

void loop() {
    long duracion, distancia;
    digitalWrite(trigPin, LOW);        
    delayMicroseconds(2);              
    digitalWrite(trigPin, HIGH);       
    delayMicroseconds(10);             
    digitalWrite(trigPin, LOW);        
    duracion = pulseIn(echoPin, HIGH);
    distancia = duracion / 2 / 29.1;
    
    Serial.println(String(distancia) + " cm.");
    
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);

    if (distancia < 30 && distancia > 15) {
        digitalWrite(led2, LOW);
        counter++;
        delay(500);
    }

    if (counter > 0 && counter % 6 == 0) {
        counter2++;
        for (int i = 0; i < 3; i++) { 
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(100);
        }
        delay(3000);
    }

    Serial.print("Hay: docenas ");
    Serial.println(counter2);

    // Actualización de la pantalla LCD
       lcd.home ();                   // go home
       lcd.print("Distancia");
       lcd.setCursor ( 0, 1 );        // go to the 2nd line
       lcd.print(distancia);

    Serial.print("Hay: manzanas ");
    Serial.println(counter);

    delay(10);
}
