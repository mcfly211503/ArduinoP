const int botonPin = 3; // Definir el pin del botón

void setup() {
  Serial.begin(9600); // Inicializar la comunicación serial a 9600 baudios
  pinMode(botonPin, INPUT); // Configurar el pin del botón como entrada
}

void loop() {
  if (digitalRead(botonPin) == HIGH) { // Verificar si se presionó el botón
    Serial.println("a"); // Enviar la letra "a" por la consola serie
    delay(1000); // Esperar 500 milisegundos para evitar múltiples envíos con un solo botón
  } else if (digitalRead(botonPin) == LOW) {
    Serial.println("b"); // Enviar la letra "b" por la consola serie
    delay(1000);
  }
}

