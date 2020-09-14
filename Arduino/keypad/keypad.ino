//#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

String num = "0";
const byte ROWS = 4; 
const byte COLS = 4; 

int led = 10;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {5,4,3,2}; 
byte colPins[COLS] = {9,8,7,6}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);

   lcd.begin();
   lcd.backlight();
}
void loop(){
  char customKey = customKeypad.getKey();
  lcd.clear();
  lcd.print("number: ");
  lcd.setCursor (7,0); 
  lcd.print(num);
   
  if (customKey){
    num += customKey;
    Serial.println(customKey);
    tone(led, 1000); // Send 1KHz sound signal...
    delay(80);        // ...for 1 sec
    noTone(led);     // Stop sound...

  }

  delay(100);
  
}
