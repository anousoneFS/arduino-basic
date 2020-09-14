#include<Servo.h>
Servo myServo;
Servo myServo2;

#define button 3
int dataX;
int dataY;
int StateBTN ;
int initial_position1;
int initial_position2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(button, INPUT);
  
  myServo.attach(2);
  myServo2.attach(5);
  
  myServo.write(initial_position1);
  
  myServo2.write(initial_position2);
  delay(15);
//  myServo.write(0);
//  delay(15);
//  myServo.write(180);
//  delay(15);
//  myServo.write(90);
//  delay(15);
}

void loop() {
  // put your main code here, to run repeatedly:
  dataX = analogRead(A0);
  dataY = analogRead(A1);
  
  StateBTN = digitalRead(button);
  dataX = map(dataX, 0, 1023, 0, 180);  
  dataY = map(dataY, 0, 1023, 0, 180);  
  
  Serial.print("press button , DataX and DataY : ");
  Serial.print(StateBTN);
  Serial.print(" , ");
  Serial.print(dataX);
  Serial.print(" , ");
  Serial.println(dataY);
  
  myServo.write(dataX);

  myServo2.write(dataY);
  delay(15);
//  myServo.write(90);
//  delay(600);

}
