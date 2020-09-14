#include<Wire.h>
#define SLAVE_ADDR 10

String response = "";
byte bval;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

byte readFromSlave(){
  Wire.requestFrom(SLAVE_ADDR, 6);
  if(Wire.available() != 0){
    Serial.print("."); 
  }
  Serial.println("");
  bval = Wire.read();
  Serial.println(bval);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
Serial.print("data From Slave = ");
Serial.println(readFromSlave());
}
