#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino_JSON.h>
#include <SoftwareSerial.h>

#define trigPin 13
#define echoPin 12

#define trig2Pin 11
#define echo2Pin 10

#define I2C_ADDR 0x27

LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
pinMode(A4, INPUT);
pinMode(A5, INPUT);
}

void loop() {
  double x=analogRead(A5);
  double serial1=x/100;
  double y=analogRead(A4);
double serial2=y/100;
  JSONVar myObject;
  myObject["serial1"] = serial1;
  myObject["serial2"] = 0;

  // Convertir el objeto JSON a una cadena
  String jsonString = JSON.stringify(myObject);

  // Imprime la cadena JSON en el puerto serie
  Serial.println(jsonString);

  // Imprimir en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Distancia 1: ");
  lcd.print(serial1);
  lcd.print(" cm");

  lcd.setCursor(0, 1);
  lcd.print("Distancia 2: ");
  lcd.print(0);
  lcd.print(" cm");

  delay(100); // Espera antes de la siguiente lectura
}