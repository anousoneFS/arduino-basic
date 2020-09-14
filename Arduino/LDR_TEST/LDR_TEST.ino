#define led 7
int sensorReading;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorReading = analogRead(0);
  if(sensorReading < 200){
    
    digitalWrite(led, HIGH);
    
  }else{
    digitalWrite(led, LOW);
  }

  Serial.println(sensorReading);
  delay(200);
  
}
