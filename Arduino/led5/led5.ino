#define led1 7
#define led2 8
#define led3 9
#define led4 10
#define led5 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  delay(100);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led4, HIGH);
  delay(100);
  digitalWrite(led4, LOW);
  delay(100);
  digitalWrite(led5, HIGH);
  delay(100);
  digitalWrite(led5, LOW);

  delay(100);
  digitalWrite(led4, HIGH);
  delay(100);
  digitalWrite(led4, LOW);
  delay(100);
  digitalWrite(led3, HIGH);
  delay(100);
  digitalWrite(led3, LOW);
  delay(100);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  delay(100);
  

  

}
