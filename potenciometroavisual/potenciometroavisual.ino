#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#define RX_PIN 10
#define TX_PIN 11

// Crea un objeto de la clase SoftwareSerial para el segundo puerto serial
SoftwareSerial Serial2(RX_PIN, TX_PIN);


#define I2C_ADDR    0x27

LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);

void setup() {
    Serial.begin(9200); // Inicia la comunicación serie a 9600 baudios
    lcd.begin(16, 2);   // Inicializar el display con 16 caracteres 2 líneas
    lcd.setBacklightPin(3, POSITIVE);
    lcd.setBacklight(HIGH);

}

void loop() {
    double a=analogRead(A5)/200;
        lcd.clear();                // Borra el contenido actual del display
        lcd.home();                  // Ir al inicio del display
       lcd.print("Distancia");           // Imprimir "Hola" en la primera línea
       lcd.setCursor(0, 1);                // Ir al inicio del display
        lcd.print(a);
        
        Serial.println(a);  
        delay(10);  
}
