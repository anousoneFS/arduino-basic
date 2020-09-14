

#define s1 A0
#define s2 A1

int StateS1;
int StateS2;
int S1;
int S2;

#define DIR1 2
#define PWM1 3
#define DIR2 4
#define PWM2 5

void setup()
{
  Serial.begin(57600);
 

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);

  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  analogWrite(PWM1, 100);
  analogWrite(PWM2, 100);

}

void loop()
{

FollowLine();
  
} 

void FollowLine(){
  
  S1 = analogRead(s1);
  S2 = analogRead(s2);
  
  StateS1 = map(S1, 1, 825, 1, 100);
  StateS2 = map(S2, 1, 825, 1, 100);

  if( StateS1 < 10){
    StateS1 = 1;
  }else{
    StateS1 = 0;
  }

  if( StateS2 < 10){
    StateS2 = 1;
  }else{
    StateS2 = 0;
  }
  
  Serial.print("State S1 and S2 = ");
  Serial.print(StateS1);
  Serial.print(" , ");
  Serial.println(StateS2);
    
  if(StateS1 == 0 && StateS2 == 1){
    TurnLeft();
    
  }else if(StateS1 == 1 && StateS2 == 0){
    TurnRight();
    
  }else if(StateS1 == 1 && StateS2 == 1){
    ForWard();
    
  }else{
    Stop();
  }
}

void ForWard(){
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);
  analogWrite(PWM1, 80);
  analogWrite(PWM2, 80);
}

void BackWard(){
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, LOW);
  analogWrite(PWM1, 80);
  analogWrite(PWM2, 80);
}

void TurnLeft(){
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);
  analogWrite(PWM1, 80);
  analogWrite(PWM2, 80);
}

void TurnRight(){
  digitalWrite(DIR1, LOW);
  digitalWrite(DIR2, HIGH);
  analogWrite(PWM1, 80);
  analogWrite(PWM2, 80);
}

void Stop(){
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
}
