
int a = 9;
int b = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if(a > b){
    Serial.print("max = ");
    Serial.println(a);
    
  }else{
    Serial.print("max = ");
    Serial.println(b);
  }

  Serial.println("Bye....");

}

void loop() {
  // put your main code here, to run repeatedly:

}
