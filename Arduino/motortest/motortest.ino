void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);
//  analogWrite(6, 150);
  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(8, HIGH);
digitalWrite(5, LOW);
delay(1500);
digitalWrite(8, LOW);
digitalWrite(5, HIGH);
delay(1500);
}
