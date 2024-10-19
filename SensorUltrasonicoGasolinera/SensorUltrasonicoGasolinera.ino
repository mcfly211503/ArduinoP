void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT); // trig
  pinMode(13, INPUT);  // echo
}

void loop() {
 double duracion;
  double distancia;

  // Generar el pulso de trigger
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);

  // Leer la duración del pulso de echo
  duracion = pulseIn(13, HIGH);

  // Calcular la distancia
  distancia = duracion * 0.034 / 2;


  Serial.println(distancia);

  // Esperar un poco antes de la próxima medición
  delay(100);
}

