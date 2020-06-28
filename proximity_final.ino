#include <LiquidCrystal.h>
const int rs = 10, en = 5, d4 = 9, d5 = 2, d6 = 3, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
#define sensor 8
#define start 12
int delay1()
{
//unsigned int long k;
int i,j;
unsigned int count=0;
for(i=0;i<1000;i++)
{
for(j=0;j<1000;j++)
{
if(digitalRead(sensor))
{
count++;
while(digitalRead(sensor));
}
}
}
return count;
}
void setup()
{
pinMode(sensor, INPUT);
lcd.begin(16, 2);
lcd.print(" Tachometer");
delay(1000);
}
void loop()
{
unsigned int time=0,RPM=0;
lcd.setCursor(0,1);
time=delay1();
RPM=(time*12)/3;
lcd.clear();
lcd.print("RPM=");
lcd.print(RPM);
delay(1000);
}
