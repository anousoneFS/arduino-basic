
#define button 7

int StateBTN = LOW;
int num;
int Previous;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  StateBTN = digitalRead(button);

  if(StateBTN == HIGH && Previous == LOW){
    num ++;
    Serial.print("CountPress = ");
    Serial.println(num);
  }

  Previous = StateBTN;

  if(num == 5){
    digitalWrite(led1, HIGH);
  delay(dl);
  digitalWrite(led1, LOW);
  delay(dl);
  
  digitalWrite(led2, HIGH);
  delay(dl);
  digitalWrite(led2, LOW);
  delay(dl);
  
  digitalWrite(led3, HIGH);
  delay(dl);
  digitalWrite(led3, LOW);
  delay(dl);
  
  digitalWrite(led4, HIGH);
  delay(dl);
  digitalWrite(led4, LOW);
  delay(dl);
  
  digitalWrite(led5, HIGH);
  delay(dl);
  digitalWrite(led5, LOW);
  delay(dl);

  digitalWrite(led4, HIGH);
  delay(dl);
  digitalWrite(led4, LOW);
  delay(dl);
  
  digitalWrite(led3, HIGH);
  delay(dl);
  digitalWrite(led3, LOW);
  delay(dl);
  
  digitalWrite(led2, HIGH);
  delay(dl);
  digitalWrite(led2, LOW);
  delay(dl);
  
  }

}
