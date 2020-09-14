#define led 2
#define button 3
#define led2 4
int StateButton = LOW, StateLed = LOW, previous = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  StateButton = digitalRead(button);
  delay(100);

  if (StateButton == HIGH && previous == LOW){
    
//    digitalWrite(led, StateLed);

    if(StateLed){
      
      do{
    
    digitalWrite(led , HIGH);
    delay(100);
    
    digitalWrite(led, LOW);
    delay(100);
    
    digitalWrite(led2 , HIGH);
    delay(100);
    
    digitalWrite(led2, LOW);
    StateButton = digitalRead(button);
    delay(100); 
    
    previous = StateButton;  
    
      }while(StateButton != HIGH && previous != HIGH);
    
    }else{

      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      
    }
    
    StateLed = !StateLed;
    
  }
  
  previous = StateButton;
}
