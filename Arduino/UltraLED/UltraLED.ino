//#define button 8
#define TRIG 9
#define ECHO 10

int buzzer=11;

int num = 0;
int pin;
int countLED = 6;
bool StateBTN = LOW;
bool State = 0;

int distance;
int duration;

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= countLED+1; i++){
    pinMode(i, OUTPUT); 
  }
//  pinMode(button, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
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

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
delay(100);

if( distance < 20){
  return HIGH;
}else{
  return LOW;
}

}

void loop() {
  // put your main code here, to run repeatedly:
  StateBTN = readUltrasonic();
 
  while(StateBTN == LOW){
    while(StateBTN == LOW){
       StateBTN = readUltrasonic();
    }  

    analogWrite(buzzer,100);
    delay(400);
    analogWrite(buzzer,0);
    delay(400);
    
    num++;
    Serial.print("num = ");
    Serial.println(num);

    pin = (num % (countLED + 1)) + 1; // pin = [2,3,4,5,6,1]
    Serial.println(pin);
    
    if(pin == 2){
      digitalWrite(pin, HIGH);
    }else if(pin != 1){
      digitalWrite(pin, HIGH);
      digitalWrite(pin-1, LOW); 
    }else{
      digitalWrite(pin+countLED, LOW);
    }
 }
}
