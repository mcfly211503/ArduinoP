//------------------------------------ 
int boton=2; //Pin donde se encuentra el pulsador, entrada 
//------------------------------------ 
//Funcion principal 
//------------------------------------ 
void setup() // Se ejecuta cada vez que el Arduino se inicia 
{ 
//Configuración 
pinMode(boton,INPUT); //Configurar el boton como una entrada
pinMode(13,INPUT);
pinMode(12,INPUT); 
pinMode(11,INPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
Serial.begin(9600); //Inicia comunicación serial 
} 
//------------------------------------ 
//Funcion ciclicla 
//------------------------------------ 
void loop() // Esta funcion se mantiene ejecutando 
{ // cuando este energizado el Arduino 
//Guardar en una variable entera el valor del boton 0 ó 1 }

int estado = digitalRead(boton); 
//Condicional para saber estado del pulsador 
if (estado==0) 
{ 
// Pulsado 
Serial.println("Pulsado"); //Imprime en la consola serial
digitalWrite(4, LOW); 
digitalWrite(3, LOW); 
digitalWrite(0, LOW); 
} // "Pulsado" 
else 
{ 
// No esta pulsado 
Serial.println("NO Pulsado"); //Imprime en la consola serial 
digitalWrite(4, HIGH); 
digitalWrite(3, HIGH);
digitalWrite(0, HIGH);
} // "NO Pulsado" 
delay(100);

int estado2 = digitalRead(12); 
//Condicional para saber estado del pulsador 
if (estado2==0) 
{ 
// Pulsado 
Serial.println("Pulsado"); //Imprime en la consola serial
digitalWrite(6, LOW); 
digitalWrite(0, LOW); 
digitalWrite(7, LOW); 
digitalWrite(3, LOW); 
digitalWrite(1, LOW); 
} // "Pulsado" 
else 
{ 
// No esta pulsado 
Serial.println("NO Pulsado"); //Imprime en la consola serial 
digitalWrite(6, HIGH); 
digitalWrite(0, HIGH);
digitalWrite(7, HIGH);
digitalWrite(3, HIGH);
digitalWrite(1, HIGH);
} // "NO Pulsado" 


int estado3 = digitalRead(11); 
//Condicional para saber estado del pulsador 
if (estado3==0) 
{ 
// Pulsado 
Serial.println("Pulsado"); //Imprime en la consola serial
digitalWrite(6, LOW); 
digitalWrite(0, LOW); 
digitalWrite(7, LOW); 
digitalWrite(4, LOW); 
digitalWrite(1, LOW); 
} // "Pulsado" 
else 
{ 
// No esta pulsado 
Serial.println("NO Pulsado"); //Imprime en la consola serial 
digitalWrite(6, HIGH); 
digitalWrite(0, HIGH);
digitalWrite(7, HIGH);
digitalWrite(4, HIGH);
digitalWrite(1, HIGH);
} // "NO Pulsado" 


int estado4 = digitalRead(13); 
//Condicional para saber estado del pulsador 
if (estado4==0) 
{ 
// Pulsado 
Serial.println("Pulsado"); //Imprime en la consola serial
digitalWrite(6, LOW); 
digitalWrite(7, LOW); 
digitalWrite(4, LOW); 
digitalWrite(1, LOW); 
digitalWrite(5, LOW); 
digitalWrite(3, LOW); 
} // "Pulsado" 
else 
{ 
// No esta pulsado 
Serial.println("NO Pulsado"); //Imprime en la consola serial 
digitalWrite(6, HIGH); 
digitalWrite(7, HIGH);
digitalWrite(4, HIGH);
digitalWrite(1, HIGH);
digitalWrite(3, HIGH);
digitalWrite(5, HIGH);
} // "NO Pulsado" 

}
