#define LIGHT 36
#define BUTTON1 16
#define BUZZER 13

int light;
bool valbtn1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LIGHT, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  light = analogRead(LIGHT);
  valbtn1 = digitalRead(BUTTON1);
  Serial.println("light = " + String(light));
  Serial.println("valbtn1 = " + String(valbtn1));
    
}
