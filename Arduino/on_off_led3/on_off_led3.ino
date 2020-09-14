#define button 7
#define led 2
bool StateBTN = 0;
bool previous = 0;
bool State = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  StateBTN = digitalRead(button);
  if(StateBTN == HIGH && previous == LOW){
    State = !State;  
    digitalWrite(led, State);
  }

  previous = StateBTN;
}
