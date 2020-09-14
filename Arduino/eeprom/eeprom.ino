#include<EEPROM.h>
#define BUTTON 2
bool val;
int n = 0;
int State;
int previous;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
//  n = EEPROM.read(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int line=0;
  val = digitalRead(BUTTON);
  delay(100);
  
  if(val == HIGH && previous == LOW){
    State = !State;
    n++;
  }
  previous = val;
  
//  EEPROM.write(0, 80);
//  EEPROM.write(4, 254);
//  EEPROM.write(512, 124);
//    if(val != LOW){
//      EEPROM.write(1, n);
//    }
    
//    Serial.println("n = " + String(n));
//    Serial.print("eeprom = ");
//    Serial.println(EEPROM.read(1));
    
  for(int i=0; i<=512;i++){
    Serial.print(EEPROM.read(i));
    Serial.print(" ");
    if(line++ > 20){
      Serial.println();
      line = 0;
    }
  }
  while(1);
}
