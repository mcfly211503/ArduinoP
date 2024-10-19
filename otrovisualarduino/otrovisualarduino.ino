#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Arduino_JSON.h>
#include <ArduinoJson.h>

#define RX_PIN 10
#define TX_PIN 11
char a;
char b;

// Crea un objeto de la clase Softwar

#define I2C_ADDR    0x27

LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);

void setup() {
    Serial.begin(15600); // Inicia la comunicación serie a 15600 baudios
    lcd.begin(16, 2);   // Inicializar el display con 16 caracteres y 2 líneas
    lcd.setBacklightPin(3, POSITIVE);
    lcd.setBacklight(HIGH);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);

    lcd.setCursor(0, 0); 
    lcd.clear();                // Borra el contenido actual del display
        lcd.home();                  // Ir al inicio del display
       lcd.print("Diesel: No");
       lcd.setCursor(0, 1);
       lcd.print("AvGas: No");
    
}

void loop() {
    if (Serial.available() > 0) { // Si hay datos disponibles en el puerto serie
          String dato = Serial.readString(); // Lee el dato recibido del puerto serie
 char dato1 = dato.charAt(0);
 char dato2 = dato.charAt(1);
a=dato1;
b=dato2;

String x2;
String x1;

if(dato1=='a')
{
  digitalWrite(8, HIGH);
  x1="No";
}
else if (dato1=='b')
{
    digitalWrite(8, LOW);
    x1="Si";
}

if(dato2=='c')
{
  digitalWrite(7, HIGH);
  x2="No";
}
else if (dato2=='d')
{
    digitalWrite(7, LOW);
    x2="Si";
}

       lcd.setCursor(0, 0); 
    lcd.clear();                // Borra el contenido actual del display
        lcd.home();                  // Ir al inicio del display
       lcd.print("Diesel: ");
       lcd.print(x1);
       lcd.setCursor(0, 1);
       lcd.print("AvGas: ");
       lcd.print(x2);
     
        delay(10);
    }
}