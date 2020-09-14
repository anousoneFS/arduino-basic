#include <LiquidCrystal.h> 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ledPin = 13;
int pirPin = 10; 
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int counter = 0;
int currentState = 0;
int previousState = 0;

void setup() {
pinMode(ledPin, OUTPUT); // declare LED as output
pinMode(pirPin, INPUT); // declare sensor as input
 lcd.begin(16, 2);
 lcd.setCursor(0, 0);
 lcd.print("No. of customer");
 Serial.begin(9600);
}

void loop(){
  
val = digitalRead(pirPin); // read PIR sensor input value

if(val == HIGH && previousState == LOW){
  counter = counter + 1;
  lcd.setCursor(4,1);
  lcd.print(counter);
}

digitalWrite(ledPin, val);
 previousState = val;
 
}
