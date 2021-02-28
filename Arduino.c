#include <LiquidCrystal.h>

const int rs=12,en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd( rs, en, d4, d5, d6, d7);
const int sensorPin = 0; 
const int led = 9; 
const int Bz = 8;


void setup()
{
  lcd.begin(16,2);
  pinMode(led, OUTPUT);
  pinMode(Bz, OUTPUT);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(GetTemp());
  lcd.print(" C");
  
  delay(1000);
  lcd.clear();
  
  
  lcd.setCursor(0,1);
  lcd.print("By INPT");
  
  if(GetTemp()>38)
  {
    digitalWrite(led,HIGH);
    AllarmS(1000);
    
  }
  else
  {
    digitalWrite(led,LOW);
  }  
  
}




float GetTemp()
{
 int reading = analogRead(sensorPin);
 float voltage = reading * 5.0;
 voltage /=1024.0;
 return ( voltage - 0.5)*100;
}

void AllarmS(int dlTime)
{
  tone(Bz,500);
  delay(dlTime);
  noTone(Bz);
  
}
