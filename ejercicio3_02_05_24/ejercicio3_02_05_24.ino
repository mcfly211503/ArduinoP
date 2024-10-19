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
{ 


  if(digitalRead(4)==HIGH)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }


  if(digitalRead(3)==HIGH)
  {
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }


  if(digitalRead(2)==HIGH)
  {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

}