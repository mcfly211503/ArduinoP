// Definición de pines
const int pinAdelante = 7;
const int pinAtras = 6;

void setup() {
  // Configurar los pines como salida
  pinMode(pinAdelante, OUTPUT);
  pinMode(pinAtras, OUTPUT);
}

void loop() {
  // Girar hacia adelante durante 2 segundos
  girarAdelante();
  delay(2000);
  
  // Girar hacia atrás durante 2 segundos
  girarAtras();
  delay(2000);
}

void girarAdelante() {
  digitalWrite(pinAdelante, HIGH);
  digitalWrite(pinAtras, LOW);
}

void girarAtras() {
  digitalWrite(pinAdelante, LOW);
  digitalWrite(pinAtras, HIGH);
}
