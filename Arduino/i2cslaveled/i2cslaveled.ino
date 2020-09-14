#include<Wire.h>
#define SLAVE_ADDR 8
//#define ANSWERSIZE 5

bool btnState;
int num;
int led = 10;
//bool rd;  // recieve data
void setup() {
  // put your setup code here, to run once:
  Wire.begin(SLAVE_ADDR);
  // Function to run when data receive from master
  Wire.onReceive(receiveEvent);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("I2C Slave demonstration");
 
}

void receiveEvent(){
  // Read while data receive
  btnState = Wire.read();
}

void loop() {
  
  Serial.println(btnState);
  if (btnState == HIGH){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
