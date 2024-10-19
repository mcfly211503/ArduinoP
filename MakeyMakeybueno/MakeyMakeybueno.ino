
#include <Keyboard.h>
void setup() {
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  Keyboard.begin();
  double a= analogRead(A5);
  double b=analogRead(A4);
  double c= analogRead(A3);
  double d= analogRead(A2);
  double e= analogRead(A1);
  double f= analogRead(A0);

  if (a>460) { Keyboard.press('w'); }
 else { Keyboard.release('w'); }

  if (b>318) { Keyboard.press('s');}
 else {  Keyboard.release('s');}

  if (f>330) { Keyboard.press('d');}
 else { Keyboard.release('d'); }

  if (c>477) { Keyboard.press('a');}
 else { Keyboard.release('a'); }

  if (e>475) { Keyboard.press('l');}
 else {  Keyboard.release('l');}

  if (d>303) { Keyboard.press(32);}
 else { Keyboard.release(32); }


 Serial.println("     A5     |     A4     |     A3     |     A2     |     A1     |     A0     |");
  Serial.print("   ");
  Serial.print(a);
  Serial.print("   |   ");
  Serial.print(b);
  Serial.print("   |   ");
  Serial.print(c);
  Serial.print("   |   ");
  Serial.print(d);
  Serial.print("   |   ");
  Serial.print(e);
  Serial.print("   |   ");
  Serial.print(f);
  Serial.println("   |");
  delay(100);
}
