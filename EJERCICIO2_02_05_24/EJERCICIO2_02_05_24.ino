// etiquetas, son nombres que se declaran a los terminales
int pulsador=2; //Pin donde se encuentra el pulsador, entrada
int led=13; //Pin donde se encuentra el LED, salida
//------------------------------------
//Funcion principal
//------------------------------------
void setup() // Se ejecuta cada vez que el Arduino se inicia
{
pinMode(pulsador, INPUT); //Configurar el pulsador como una entrada
pinMode(3, INPUT);
pinMode(4, INPUT);
pinMode(led,OUTPUT); //Configurar el LED como una salida
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
}
//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() // Esta funcion se mantiene ejecutando
{ // cuando este energizado el Arduino
//Condicional para saber estado del pulsador
if (digitalRead(pulsador)==HIGH)
{
//Pulsador oprimido
digitalWrite(led,HIGH); //Enciende el LED
digitalWrite(11,LOW);
digitalWrite(12,LOW);
}
else
{
//Pulsador NO oprimido
digitalWrite(led,LOW); //Apaga el LED
}


if (digitalRead(3)==HIGH)
{
//Pulsador oprimido
digitalWrite(12,HIGH); 
digitalWrite(led,LOW); //Apaga el LED//Enciende el LED
digitalWrite(11,LOW);
}
else
{
//Pulsador NO oprimido
digitalWrite(12,LOW); //Apaga el LED
}

if (digitalRead(4)==HIGH)
{
//Pulsador oprimido
digitalWrite(11,HIGH); //Enc
digitalWrite(led,LOW); //Apaga el LEDiende el LED
digitalWrite(12,LOW);
}
else
{
//Pulsador NO oprimido
digitalWrite(11,LOW); //Apaga el LED
}

}