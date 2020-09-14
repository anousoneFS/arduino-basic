#include <NewPing.h>
// sensor 0
#define TRIGGER_PIN_0 8
#define ECHO_PIN_0 8
// sensor 1
#define TRIGGER_PIN_1 9
#define ECHO_PIN_1 9
// Maximum Distance is 400 cm
#define MAX_DISTANCE 400
// create objects for ultrasonic sensors
NewPing sensor0(TRIGGER_PIN_0, ECHO_PIN_0, MAX_DISTANCE);
NewPing sensor1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);

// variables to represent distances
float distance0, distance1;

void setup() {
  // Serial monitor for testing
  Serial.begin(9600);
}

void loop() {
  // Read sensors in CM
  // sensor 0
  distance0 = sensor0.ping_cm();
  delay(20);

  // sensor 1
  distance1 = sensor1.ping_cm();
  delay(20);

  // send results to Serial monitor
  // sensor 0
  Serial.print("Distance 0 = ");
  if(distance0 >= 400 || distance0 <= 2){
    Serial.println("Out of range");
  }else{
    Serial.print(distance0);
    Serial.println(" cm");
    delay(500);
  }

  // Sensor 1
  Serial.print("Distance 1 = ");
  if(distance1 >= 400 || distance1 <= 2){
    Serial.println("Out of range");
  }else{
    Serial.print(distance1);
    Serial.println(" cm");
    delay(500);
  }
  

}
