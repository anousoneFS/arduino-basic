
int a = 5;
int b = 10;
int c = 12;
int d = 20;
int e = 11;
int Max;

int num = 12972;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Max = a;

//  if(b > Max){
//    Max = b;
//  }if(c > Max){
//    Max = c;
//  }if(d > Max){
//    Max = d;
//  }if(e > Max){
//    Max = e;
//  }
  
  
//  if(b > Max){
//    Max = b;
//  }else if(c > Max){
//    Max = c;
//  }else if(d > Max){
//    Max = d;
//  }else if(e > Max){
//    Max = e;
//  }

  if(num % 10 == 0){
    Serial.println("end num = 0");
  }else if(num % 10 == 1){
   Serial.println("end num = 1");
  }else if(num % 10 == 2){
    Serial.println("end num = 2");
  }else if(num % 10 == 3){
   Serial.println("end num = 3");
  }else if(num % 10 == 4){
    Serial.println("end num = 4");
  }else if(num % 10 == 5){
    Serial.println("end num = 5");
  }else if(num % 10 == 6){
    Serial.println("end num = 6");
  }else if(num % 10 == 7){
    Serial.println("end num = 7");
  }else if(num % 10 == 8){
    Serial.println("end num = 8");
  }else if(num % 10 == 9){
    Serial.println("end num = 9");
  }

//    Serial.print("end num = ");
//    Serial.println(num % 10);
  

//  Serial.print("Max = ");
//  Serial.println(Max);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
