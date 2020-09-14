#define TRIG 5 
#define ECHO 6
#define led 7

long duration;
int distance;
int count = 0;
int previous ;
int State = LOW;  

void setup() {
  // put your setup code here, to run once:
     
     Serial.begin(9600);
     pinMode(TRIG, OUTPUT);
     pinMode(ECHO, INPUT);
     pinMode(led,  OUTPUT);
}

bool readUltrasonic() {
  digitalWrite(TRIG, LOW);
 delayMicroseconds(2);

 digitalWrite(TRIG, HIGH);
 delayMicroseconds(10);

 digitalWrite(TRIG,LOW);


duration = pulseIn (ECHO, HIGH);
distance = duration * 0.034 / 2;
if(distance < 15){

 return HIGH;
}else{
  return LOW;
}

}


void loop() {
  // put your main code here, to run repeatedly:
  
  readUltrasonic();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);

  digitalWrite(led,readUltrasonic());
}
