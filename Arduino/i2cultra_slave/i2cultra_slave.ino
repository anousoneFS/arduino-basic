#include <NewPing.h>
#include <Wire.h>

// define slave i2c address
#define SLAVE_ADDR 9

// sensor 0
#define TRIGGER_PIN_0 8
#define ECHO_PIN_0 8
// sensor 1
#define TRIGGER_PIN_1 9
#define ECHO_PIN_1 9
// Maximum Distance is 260 cm
#define MAX_DISTANCE 260
// create objects for ultrasonic sensors
NewPing sensor0(TRIGGER_PIN_0, ECHO_PIN_0, MAX_DISTANCE);
NewPing sensor1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);

// variables to represent distances
float distance0, distance1;

// define return data array, one element per sensor
int distance[2];
// define counter to count bytes in response
int bcount = 0;

void setup() {
  // initiallize i2c communications as slave
  Wire.begin(SLAVE_ADDR);
  // Function to run when data requested from master
  Wire.onRequest(requestEvent);
  
  // Serial monitor for testing
  Serial.begin(9600);
}

void requestEvent(){
  // define a byte to hold data
  byte bval;

  // Cycle through data
  // First reponse is always 255 to mark beginning
  switch(bcount){
    case 0:
      bval = 255;
      break;
    case 1:
      bval = distance[0];
      break;
    case 2:
      bval = distance[1];
      break;
    
  }

  // Send.response back to Master
  Wire.write(bval);

  // Increment byte counter
  bcount = bcount + 1;
  if (bcount > 2) bcount = 0;
  
}

void readDistance(){
  
  distance[0] = sensor0.ping_cm();
  if(distance[0] > 254){
    distance[0] = 254;
  }
  delay(20);

  distance[1] = sensor1.ping_cm();
  if(distance[1] > 254){
    distance[1] = 254;
  }
  delay(20);

}

void loop() {
  // Refresh readings every half second
  readDistance();
  delay(500);
  

}
