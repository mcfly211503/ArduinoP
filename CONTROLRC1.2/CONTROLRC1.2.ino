#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#define xy A0
#define outx D8
#define outy D0

int datosx, datosy;
String X, Y;

struct MyData{
  int datox;
  int datoy;
};

MyData data;

const uint64_t pipeOut = 0xE8E8F0F0E1LL;
RF24 radio(D1,D2); //NRF24L01 (CE, CSN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(outx, OUTPUT);
  pinMode(outy, OUTPUT);

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);

  radio.openWritingPipe(pipeOut);
  resetData();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outx, HIGH);
  data.datox = mapJoystickValues(analogRead(xy), 0, 525, 1023, true);
  digitalWrite(outx, LOW);
  delay(10);
  digitalWrite(outy, HIGH);
  data.datoy = mapJoystickValues(analogRead(xy), 0, 525, 1023, true);
  digitalWrite(outy, LOW);
  delay(10);

  radio.write(&data, sizeof(MyData));
  X = String (data.datox);
  Y = String (data.datoy);
  Serial.println(X + "," + Y);
}

int mapJoystickValues(int val, int lower, int middle, int upper, bool reverse){
  val = constrain(val, lower, upper);
  if(val < middle){
    val = map(val, lower, middle, 0, 128);
  }else{
    val = map(val, middle, upper, 128, 255);
  }
  return (reverse ? 255 - val: val);
}

void resetData(){
  data.datox = 127;
  data.datoy = 127;
}
