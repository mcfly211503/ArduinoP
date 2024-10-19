#define ENA 6
#define ENB 7     // Pin PWM conectado al pin ENA del módulo L298N
#define IN1 8     // Pin digital conectado al pin IN1 del módulo L298N
#define IN2 9     // Pin digital conectado al pin IN2 del módulo L298N
#define IN3 10
#define IN4 11

int boton=0; //Pin donde se encuentra el pulsador, entrada 
int boton2=1; //Pin donde se encuentra el pulsador, entrada 
int boton3=2;
int boton4=3;

void setup() {
  pinMode(boton,INPUT); //Configurar el boton como una entrada 
  pinMode(boton2,INPUT); //Configurar el boton como una entrada 
  pinMode(boton3,INPUT);
  pinMode(boton4,INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Girar en una dirección al principio (lentamente)
  
}

void loop() {
  int estado = digitalRead(boton); 
  int estado2 = digitalRead(boton2); 
  int state= digitalRead(boton3);
  int state2=digitalRead(boton4);

  Serial.print("D0: ");
  Serial.print(estado);
  Serial.print(", D1: ");
  Serial.print(estado2);
  Serial.print(", D2: ");
  Serial.print(state);
  Serial.print(", D3: ");
  Serial.print(state2);
  Serial.println(" ");


if (estado == 0  && estado2 == 1) {
    // Ajustar la velocidad del motor hacia adelante
    double velocidad = -1; // Velocidad máxima hacia adelante (10 RPM)
    Serial.print("Velocidad hacia adelante: ");
    Serial.println(velocidad);
    motorForward(velocidad); // Función para mover el motor hacia adelante con la velocidad especificada

  } else if (estado2 == 0 && estado == 1) {
    // Ajustar la velocidad del motor hacia atrás
    double velocidad = -1; // Velocidad máxima hacia atrás (-10 RPM)
    Serial.print("Velocidad hacia atrás: ");
    Serial.println(velocidad);
    motorBackward(velocidad); // Función para mover el motor hacia atrás con la velocidad especificada
  } else {
    // Detener el motor si no se presiona ningún botón
    motorStop();
  }
  
  if (state == 0  && state2 == 1) {
    // Ajustar la velocidad del motor hacia adelante
    double velocidad = -1; // Velocidad máxima hacia adelante (10 RPM)
    Serial.print("Velocidad hacia adelante: ");
    Serial.println(velocidad);
    motor2Forward(velocidad); // Función para mover el motor hacia adelante con la velocidad especificada

  } else if (state2 == 0 && state == 1) {
    // Ajustar la velocidad del motor hacia atrás
    double velocidad = -1; // Velocidad máxima hacia atrás (-10 RPM)
    Serial.print("Velocidad hacia atrás: ");
    Serial.println(velocidad);
    motor2Backward(velocidad); // Función para mover el motor hacia atrás con la velocidad especificada
  } else {
    // Detener el motor si no se presiona ningún botón
    motor2Stop();
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



void motor2Forward(double speed) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed < 0 ? -speed * 255 : 0); // Convertir la velocidad de RPS a valor PWM
}

void motor2Backward(double speed) {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speed < 0 ? -speed * 255 : 0); // Convertir la velocidad de RPS a valor PWM
}

void motor2Stop() {
  analogWrite(ENB, 0); // Apagar el motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
