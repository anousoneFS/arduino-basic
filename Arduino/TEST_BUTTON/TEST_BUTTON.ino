
#define button 7
int State = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  State = digitalRead(button);

  Serial.println(State);
  delay(200);
  
}
