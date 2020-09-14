#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
int dl = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int i = 2; i <= 6; i++){
    digitalWrite(i, HIGH);
    delay(dl);
    digitalWrite(i, LOW);
    delay(dl);
  }

  for(int i = 5;i >= 3; i--){
    digitalWrite(i, HIGH);
    delay(dl);
    digitalWrite(i, LOW);
    delay(dl);
  }
  
}
