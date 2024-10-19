#include <Keypad.h>
#define ENA 3     // Pin PWM conectado al pin ENA del módulo L298N
#define IN1 8     // Pin digital conectado al pin IN1 del módulo L298N
#define IN2 9     // Pin digital conectado al pin IN2 del módulo L298N
#define POT_PIN A5 // Pin analógico conectado al potenciómetro
int boton=0; //Pin donde se encuentra el pulsador, entrada 
int boton2=12; //Pin donde se encuentra el pulsador, entrada 

void setup() {
  pinMode(boton,INPUT); //Configurar el boton como una entrada 
  pinMode(boton2,INPUT); //Configurar el boton como una entrada 
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Girar en una dirección al principio (lentamente)
  
}

void loop() {
  int valorPot = analogRead(POT_PIN);
  int estado = digitalRead(boton); 
  int estado2 = digitalRead(boton2); 
  Serial.print("D2: ");
   Serial.print(estado);
    Serial.print(", D1: ");
     Serial.print(estado2);
    Serial.println(" ");


if (estado == 0  && estado2 == 1) {
    // Ajustar la velocidad del motor hacia adelante
    double velocidad = -0.5; // Velocidad máxima hacia adelante (10 RPM)
    Serial.print("Velocidad hacia adelante: ");
    Serial.println(velocidad);
    motorForward(velocidad); // Función para mover el motor hacia adelante con la velocidad especificada

  } else if (estado2 == 0 && estado == 1) {
    // Ajustar la velocidad del motor hacia atrás
    double velocidad = -0.5; // Velocidad máxima hacia atrás (-10 RPM)
    Serial.print("Velocidad hacia atrás: ");
    Serial.println(velocidad);
    motorBackward(velocidad); // Función para mover el motor hacia atrás con la velocidad especificada
  } else {
    // Detener el motor si no se presiona ningún botón
    motorStop();
  }
  
  delay(100);
}




 void motorForward(double speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed < 0 ? -speed * 255 : 0); // Convertir la velocidad de RPS a valor PWM
}

void motorBackward(double speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed < 0 ? -speed * 255 : 0); // Convertir la velocidad de RPS a valor PWM
}

void motorStop() {
  analogWrite(ENA, 0); // Apagar el motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
