#define button 7

int num = 0;
int pin = 0;
int countLED = 5;
bool btnState = LOW;
bool State = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= countLED+1; i++){
    pinMode(i, OUTPUT); 
  }
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  btnState = digitalRead(button);
 
  while(btnState == LOW){
    while(btnState == LOW){
       btnState = digitalRead(button);
    }  
   
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
