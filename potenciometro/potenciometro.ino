//------------------------------------ 
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x27

LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
void setup() // Se ejecuta cada vez que el Arduino se inicia 
{ 
Serial.begin(25100); //Inicia comunicación serial 
lcd.begin(16, 2); 
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);
} 
//------------------------------------ 
//Funcion ciclicla 
//------------------------------------ 
void loop() // Esta funcion se mantiene ejecutando 
{ // cuando este energizado el Arduino 
double valor_A5 = analogRead(A5); 
 double valor_A4 = analogRead(A4); 
    Serial.println(valor_A5); 
      lcd.home ();                  
       lcd.print("Distancia");
       lcd.setCursor ( 0, 1 );    
       lcd.print(valor_A5);
       lcd.print("cm       ");

delay(100); 
}
