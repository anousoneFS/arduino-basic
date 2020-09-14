#define button_mode 3
#define led_2 4
#define led_3 5
#define sensor 6
#define sensor_2 7
#define button_1 8
#define led_1 9

void setup() {
  // put your setup code here, to run once:
pinMode(button_mode, INPUT);
pinMode(led_1, OUTPUT);
pinMode(led_2, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(button_mode));
  delay(200);

}
