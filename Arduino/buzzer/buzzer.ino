
#define R_1 3
#define R_2 4
#define L_1 5
#define L_2 6
int dl = 1000;

void setup() {
  // put your setup code here, to run once:
pinMode(R_1, OUTPUT);
pinMode(R_2, OUTPUT);
pinMode(L_1, OUTPUT);
pinMode(L_2, OUTPUT);

}

void forward(){
  digitalWrite(R_1, HIGH);    // forward
digitalWrite(R_2, LOW);

digitalWrite(L_1, HIGH);
digitalWrite(L_2, LOW);     
}

void back(){
  digitalWrite(R_1, LOW);    // forward
digitalWrite(R_2, HIGH);

digitalWrite(L_1, LOW);
digitalWrite(L_2, HIGH);     
}
void Stop(){
  digitalWrite(R_1, LOW);    // forward
digitalWrite(R_2, LOW);

digitalWrite(L_1, LOW);
digitalWrite(L_2, LOW);     
}
void loop() {
  
Stop();
delay(400);
forward();
delay(dl);
Stop();
delay(400);
back();
delay(dl);


}
