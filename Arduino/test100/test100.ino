#define button 7
#define led1 6
#define led2 5
bool StateBTN = 0;
bool previous = 0;
bool State = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  StateBTN = digitalRead(button);
  
  if(StateBTN == 1 && previous == 0){
    State = !State;  
    if(State == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }else{
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      
    }
    
  }

  
  previous = StateBTN;
  
}
