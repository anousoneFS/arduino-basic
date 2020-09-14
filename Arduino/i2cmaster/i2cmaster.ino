// include Arduino Wire for i2c
#include<Wire.h>
//Define Slave i2c Address
#define SLAVE_ADDR 8
// Define Slave answer size
#define ANSWERSIZE 20

char b;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5);
  Serial.println("Write data from Slave");

  // Write charactre from the Slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(0);
  Wire.endTransmission();

  Serial.println("Receive Data");

  //Read response from Slave
  // Read back 5 characters
  Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);

  // Add characters to String
  String response = "";
  while(Wire.available()){
    b = Wire.read();
    response += b;
  }

  // print to Serial Monitor
  Serial.println(response);
  delay(100);
}
