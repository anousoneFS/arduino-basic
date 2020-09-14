
#define button 7
#define led 8
#define led2 9
int State = 0;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
 State = digitalRead(button);
 
 if(State == HIGH){
    Serial.println("---> result is    1");
    digitalWrite(led , HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led2 , HIGH);
    delay(200);
    digitalWrite(led2, LOW);
    delay(200);
    
    
    
 }
 
 else{
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    Serial.println("---> result is   0");
    delay(300);
 }
 
}
