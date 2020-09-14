String answer = "Hello anousone";
#define ANSWERSIZE 20

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
byte response[ANSWERSIZE];
  // Format answer as array
  for(byte i = 0; i < ANSWERSIZE; i++){
    response[i] = (byte)answer.charAt(i);
//    Serial.println(response[i]);
  }
  Serial.println(response[]);
//  delay(2000);

}

void requestEvent(){
  // Setup byte Variable in the correct size
  byte response[ANSWERSIZE];
  // Format answer as array
  for(byte i = 0; i < ANSWERSIZE; i++){
    response[i] = (byte)answer.charAt(i);
  }

  // Send response back to master
//  Wire.write(response, sizeof(response));
//  Serial.println("request Event");
  
}


void loop() {
  // put your main code here, to run repeatedly:

//Serial.print("String = ");
//Serial.println();
}
