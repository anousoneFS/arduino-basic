// include Arduino Wire for i2c
#include<Wire.h>
//Define Slave i2c Address
#define SLAVE_ADDR 8
// Define Slave answer size
//#define ANSWERSIZE 5

bool StateBTN = LOW;
bool previous;
bool State;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  StateBTN = digitalRead(3);
  
  if(StateBTN == 1 && previous == 0){
    State = !State;  
  }

  previous = StateBTN;
  
  // Write charactre from the Slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(State);
  Wire.endTransmission();

}
