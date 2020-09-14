#include<Servo.h>

Servo servo;
int pos = 0;

int StateBTN ;
#define button 2

void setup() {
  // put your setup code here, to run once:
  servo.attach(9, 500, 2500);
  pinMode(button, INPUT);
  Serial.begin(9600);

  servo.writeMicroseconds(1500);
  
}

void loop() {
  // put your main code here, to run repeatedly:

//StateBTN = digitalRead(button);
//Serial.print("StateBTN = ");
//Serial.println(StateBTN);
//delay(100);


//if(StateBTN == HIGH){
//  servo.writeMicroseconds(1700);
//}
//
//if(StateBTN == LOW){
//  servo.writeMicroseconds(1500);
//  Serial.print("degree = ");
//  Serial.println(servo.read(), DEC);
//}

//servo.writeMicroseconds(1800);
//delay(2000);
//servo.write(-90);
//delay(1000);
//servo.write(0);
//delay(1000);
//servo.write(90);
//delay(1000);

servo.write(30);
delay(2000);
servo.write(-30);
delay(2000)


  
}
