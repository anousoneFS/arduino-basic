
// left wheel
#define OUT1 6
#define OUT2 7
#define ENA 3

// right wheel
#define OUT3 8
#define OUT4 5
#define ENB 9


void setup() {
  // put your setup code here, to run once:
pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

void loop() {
  // put your main code here, to run repeatedly:
  moveForward();
}

void moveForward() {
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);

  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, HIGH);
}
