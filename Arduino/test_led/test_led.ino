
//#define 7

const int led1 = 2;
#define led2 3

int led3 = 4;
int led4 = 5;
int led5 = 6;

void setup() {
  // put your setup code here, to run once:

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  for (int i = 2; i < 7; i++) {
    
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
    
  }

  for (int i = 5; i > 1 ; i--) {
    
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
    
  }
  
//  digitalWrite(led1, HIGH);
//  delay(100);
//  digitalWrite(led1, LOW);
//  delay(100);
//  
//  digitalWrite(led2, HIGH);
//  delay(100);
//  digitalWrite(led2, LOW);
//  delay(100);
//  
//  digitalWrite(led3, HIGH);
//  delay(100);
//  digitalWrite(led3, LOW);
//  delay(100);
//  
//  digitalWrite(led4, HIGH);
//  delay(100);
//  digitalWrite(led4, LOW);
//  delay(100);
//  
//  digitalWrite(led5, HIGH);
//  delay(100);
//  digitalWrite(led5, LOW);
//  delay(100);
//
//  ///////////
//
//  digitalWrite(led4, HIGH);
//  delay(100);
//  digitalWrite(led4, LOW);
//  delay(100);
//  
//  digitalWrite(led3, HIGH);
//  delay(100);
//  digitalWrite(led3, LOW);
//  delay(100);
//  
//  digitalWrite(led2, HIGH);
//  delay(100);
//  digitalWrite(led2, LOW);
//  delay(100);
  
  

}
