// Definir los pines
const int IN1 = 8;
const int IN2 = 9;

void setup() {
  // Configurar los pines como salidas
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  // Mover el motor hacia adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000); // Mover por 2 segundos

  // Detener el motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000); // Esperar 1 segundo

  // Mover el motor hacia atrás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000); // Mover por 2 segundos

  // Detener el motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000); // Esperar 1 segundo
}

