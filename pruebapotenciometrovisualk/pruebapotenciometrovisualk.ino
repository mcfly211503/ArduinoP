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

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(trig2Pin, OUTPUT);
  pinMode(echo2Pin, INPUT);
}

void loop() {
  long duration1, duration2;
  double distance1, distance2;

  // Medición de la distancia para el primer sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration1 = pulseIn(echoPin, HIGH);
  distance1 = duration1 * 0.034 / 2;
double serial1;
  if (28.5-distance1<0)
  {
serial1=0;
  }
  else
  {
    serial1=-distance1+28.5;
  }

  digitalWrite(trig2Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2Pin, LOW);
  duration2 = pulseIn(echo2Pin, HIGH);
  distance2 = duration2 * 0.034 / 2;
double serial2;
if (28.5-distance2<0)
  {
serial2=0;
  }
  else
  {
    serial2=-distance2+28.5;
  }
  JSONVar myObject;
  myObject["serial1"] = serial1;
  myObject["serial2"] = serial2;

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
  lcd.print(serial2);
  lcd.print(" cm");

  delay(100); // Espera antes de la siguiente lectura
}
