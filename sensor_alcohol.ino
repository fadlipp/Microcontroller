//Simulasi Input Digital Arduino: Input Sensor Alkohol dan Output LED serta LCDAssignment
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int MQ=3;
int GREEN_LED=5;
int BLUE_LED=4;

void setup() {
  // put your setup code here, to run once:
pinMode(MQ, INPUT_PULLUP);
pinMode(GREEN_LED, OUTPUT);
pinMode(BLUE_LED, OUTPUT);
lcd.begin(20,4);
lcd.setCursor(0,0);
lcd.print("SYSTEM PENDETEKSI");
lcd.setCursor(0,1);
lcd.print("ALKOHOL");
lcd.setCursor(0,2);
lcd.print("TELEKOMUNIKASI PNJ");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
int MQ_READ = digitalRead(MQ);
if (MQ_READ == LOW)
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("ALCOHOL DETECTED");
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  delay(20);
}
else
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("ALCOHOL NOT DETECTED");
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(20);
  }
}
