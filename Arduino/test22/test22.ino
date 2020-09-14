#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display

LiquidCrystal_I2C lcd(0x27, 20, 4);

int num1 = 5, num2 = 2, num3 = 3, num4 = 4;

void setup(){
    lcd.begin();      
}
void loop(){
    lcd.setCursor(0, 0);
  lcd.print("NUM1 = ");
  lcd.setCursor(0, 1);
  lcd.print("NUM2 = ");
  lcd.setCursor(0, 2);
  lcd.print("NUM3 = ");
  lcd.setCursor(0, 3);
  lcd.print("NUM4 = ");

  lcd.setCursor(7, 0);
  lcd.print(num1);
  lcd.setCursor(7, 1);
  lcd.print(num2);
  lcd.setCursor(7, 2);
  lcd.print(num3);
  lcd.setCursor(7, 3);
  lcd.print(num4);
  
  lcd.setCursor(10, 3);
  lcd.print("freestyle");
}
//พิมพ์ข้อความ...
