#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27 // <
#define BACKLIGHT_PIN 3


LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

void setup()
{
//lcd.begin (16,2); // <
lcd.begin (20,4); // <

// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

lcd.setCursor(3,1); // ไปทตัวอักษรที่ 3 แถวที่ 2
lcd.print("Welcome ALL To"); 

lcd.setCursor(5,2); // ไปที่ตัวอักษรที่ 5 แถวที่ 3
lcd.print("ArduinoAll");

}

void loop()
{

}
