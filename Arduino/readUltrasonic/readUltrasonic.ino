 #define TRIG 5
#define ECHO 6
#define led 4

long duration;
int distance;
int previous ;
int State = LOW;

void setup(){
Serial.begin(9600);
pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
pinMode(led, OUTPUT);

}

bool readUltrasonic(){
  digitalWrite(TRIG, LOW);
delayMicroseconds(2);

digitalWrite(TRIG, HIGH);
delayMicroseconds(10);

digitalWrite(TRIG, LOW);

//distance = pulseIn(ECHO, HIGH)/58.2;
duration = pulseIn(ECHO, HIGH);
distance = duration * 0.034 / 2;

if( distance < 15){
  return HIGH;
}else{
  return LOW;
}

}

void loop(){
  
  readUltrasonic();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //delay(distance*10);
  delay(100);

//  digitalWrite(led, readUltrasonic());

 State = readUltrasonic();

 if(State == HIGH && previous == LOW){
    State = !State;
    digitalWrite(led, State);
 }

  previous = State;

}
