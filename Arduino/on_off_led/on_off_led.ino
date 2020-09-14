#define led 4
#define button 5
int StateB;
int previous;
int StateL = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  StateB = digitalRead(button);
  if(StateB == HIGH && previous == LOW){
    StateL = !StateL;
    digitalWrite(led, StateL);
  }

  previous = StateB;

}
