int pulsador = 2; // Pin donde se encuentra el pulsador, entrada
int ledRojo = 13; // Pin donde se encuentra el LED rojo, salida
int ledVerde = 12; // Pin donde se encuentra el LED verde, salida

void setup() {
  pinMode(pulsador, INPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  if (digitalRead(pulsador) == HIGH && digitalRead(3) == HIGH) {
    digitalWrite(ledRojo, LOW); // Apaga el LED rojo
    digitalWrite(ledVerde, HIGH); // Enciende el LED verde
  } 
  else if (digitalRead(4)==HIGH)
  {
    digitalWrite(ledRojo, LOW); // Apaga el LED rojo
    digitalWrite(ledVerde, HIGH); // Enciende el LED verde
  }
  else {
    digitalWrite(ledRojo, HIGH); // Enciende el LED rojo
    digitalWrite(ledVerde, LOW); // Apaga el LED verde
  }
}
