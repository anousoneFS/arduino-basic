int led_01 = 8;
int led_02 = 9;
volatile int toggle = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_01, OUTPUT);
  pinMode(led_02, OUTPUT);
  attachInterrupt(0, toggle_isr, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_01, HIGH);
  delay(100);
  digitalWrite(led_01, LOW);
  delay(100);
}

void toggle_isr(){
  toggle = !toggle;
  digitalWrite(led_02, toggle);
}
