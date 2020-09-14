
#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define TRIG 5
#define ECHO 6
#define led 10

long duration;
int distance;
int count = 0;
int previous ;
int State = LOW;

void setup(){
Serial.begin(9600);
lcd.begin(16, 2);
 lcd.setCursor(0, 0);
 lcd.print("No. of customer");
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
pinMode(led, OUTPUT);

}

void readUltrasonic(){
  digitalWrite(TRIG, LOW);
delayMicroseconds(2);

digitalWrite(TRIG, HIGH);
delayMicroseconds(10);

digitalWrite(TRIG, LOW);

//distance = pulseIn(ECHO, HIGH)/58.2;
duration = pulseIn(ECHO, HIGH);
distance = duration * 0.034 / 2;
//previous = distance;

}
void loop(){
  
readUltrasonic();

//tone(8, 2000, 150);
//delay(100);
//tone(8, 1000, 50);

do{
  
  readUltrasonic();
  
  if(distance < 15 && previous >= 15){
    count = count + 1;
    digitalWrite(led, HIGH);
  }
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
  

  previous = distance;
}while(distance < 15);

    digitalWrite(led, LOW);
    
    lcd.setCursor(4,1);
  lcd.print(count);
    
//    Serial.print("Count: ");
//    Serial.println(count);
//    delay(200);



}
