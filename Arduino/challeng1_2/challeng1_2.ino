#define button 7

int num = 0;
int n = 0;
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

void led_off(){
  for (int i = n + 1; i <= countLED + 2; i++){
      digitalWrite(i, LOW);
    }
    
    for (int i = n - 1; i >= 2; i--){
      digitalWrite(i, LOW);
    }
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

    n = (num % (countLED + 1)) + 1;
    
    if(n != 0){
      digitalWrite(n, HIGH);
    }else{
      digitalWrite(n, LOW);
    }
    led_off();  
 }
}
