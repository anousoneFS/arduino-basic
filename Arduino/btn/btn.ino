bool btn = 1;

void setup() {
  // put your setup code here, to run once:
 pinMode(4, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn = digitalRead(4);
  Serial.println(btn);
}
