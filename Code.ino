#include <LiquidCrystal.h>
int ledred=3;
int ledgreen=2;
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
int buzzer=13;
int sensor=A0;
//MOTOR1 PINS
int ena = 5;
int in1 = 6;
int in2 = 4;
int Sinput = A1;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
float adcValue=0, val=0, mgL=0;
void setup() {
// put your setup code here, to run once:
pinMode(Sinput, INPUT);
pinMode(sensor,INPUT);
pinMode(buzzer,OUTPUT);
lcd.begin(16,2);
pinMode(ena, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
analogWrite(ena, 255);
pinMode(ledred,OUTPUT);
pinMode(ledgreen,OUTPUT);
}
void loop() {
// put your main code here, to run repeatedly:
adcValue=0;
for(int i=0;i<20;i++){
adcValue+=analogRead(sensor);
delay(10);70
}
val=(adcValue/20)*(5.0/1024.0);
mgL=0.67*val;
lcd.setCursor(0,0);
lcd.print("BAC: ");
lcd.print(mgL,3);
lcd.print("mg/L");
lcd.setCursor(0, 1);
if(mgL>0.8 && digitalRead(Sinput)==HIGH )
{
lcd.print(" DRUNK! ");
digitalWrite(buzzer,HIGH);
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(ledred,HIGH);
digitalWrite(ledgreen,LOW);
delay(200);
}
else if(mgL>0.8 && digitalRead(Sinput)==LOW)
{
delay (2000);digitalWrite(buzzer,HIGH);
lcd.print(" Drunk&Sleepy ");
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(ledred,HIGH);
digitalWrite(ledgreen,LOW);
//delay(100);
}
else if(mgL<0.8 && digitalRead(Sinput)==LOW)
{
delay (2000);digitalWrite(buzzer,HIGH);
lcd.print(" SLEEPY! ");
delay(100);
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(ledred,HIGH);
digitalWrite(ledgreen,LOW);
}
else {
lcd.print(" NORMAL! ");
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(ledred,LOW);
digitalWrite(ledgreen,HIGH);digitalWrite(buzzer, LOW);
}
