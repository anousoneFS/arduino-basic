#include<Wire.h>
#define SLAVE_ADDR 10

int bcount = 0;
byte bval;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(requestEvent);
  
  Serial.begin(9600);
}

void requestEvent(){
  bval = 255;
  Wire.write(bval);
  
  bcount++;
  if (bcount > 5){
    bcount = 0;
  }
  
}
void loop() {
  // put your main code here, to run repeatedly:

}
