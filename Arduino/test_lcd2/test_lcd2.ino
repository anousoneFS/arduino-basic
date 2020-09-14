#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

int show;

void setup()
{
  lcd.begin (20,4); 

lcd.setBacklight(255);

lcd.print("Welcome ALL To"); 


} // setup()


void loop()
{
  
} 
