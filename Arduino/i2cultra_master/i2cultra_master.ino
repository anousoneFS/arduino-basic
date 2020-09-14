// include arduino wire library for i2c
#include<Wire.h>

// define slave i2c address
#define SLAVE_ADDR 9

// define counter to count bytes in response
int bcount;

// define array for return data
byte distance[2];

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

byte readI2C(int address){
  //define a variable to hold byte of data
  byte bval;
  long entry = millis();
  // read one byte at a time
  Wire.requestFrom(address, 1);
  //Wait 100 ms for data to stabilize
  while(Wire.available() == 0 && (millis() - entry) < 100){
    Serial.println("Waiting");
  }
  // Place data into byte
  if(millis() - entry < 100) bval = Wire.read();

  return bval;
}

void loop() {
 
  while(readI2C(SLAVE_ADDR) < 255){
    // Until first byte has been received print a waiting message
    Serial.println("first byte Waiting");
  }
  for(bcount = 0; bcount < 2; bcount++){
    distance[bcount] = readI2C(SLAVE_ADDR);
  }
  for(int i = 0; i<2; i++){
    Serial.print(distance[i]);
    Serial.print("\t");
  }
  Serial.println();
  delay(500);

}
