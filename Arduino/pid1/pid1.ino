
#define DIR1 2
#define PWM1 3
#define DIR2 4
#define PWM2 5

int sensorsValue[5] ; // do not use 0 index
int lineV = 0;
int groundV = 0;
int meanV = 500;
int N = 5;
int motorSpeed;
int baseSpeed = 100;
int rightSpeed,leftSpeed;
int maxSpeed = 100;
int sum_error = 0;

// PID
int error = 0;
int pre_error = 0;
int Kp = 25;
int Kd = 0;
int Ki = 0;

bool B(int n){  
  if(n < meanV){ // is black
      return true;
  }else{
      return false;
  } 
}

bool W(int n){  
    if(n >= meanV){ // is white
      return true;
  }else{
      return false;
  } 
}

void motor(int m, int Speed){
  
  if(m == 1 && Speed > 0){
    digitalWrite(DIR1, HIGH);
    analogWrite(PWM1, Speed);
    
  }else if(m == 2 && Speed > 0){
    digitalWrite(DIR2, HIGH);
    analogWrite(PWM2, Speed);
    
  }else if(m == 1 && Speed < 0){
    digitalWrite(DIR1, LOW);
    analogWrite(PWM1, -Speed);
    
  }else{
    digitalWrite(DIR1, LOW);
    analogWrite(PWM2, -Speed);
  }
  
}


void FollowLine(){
    
    for(int i=0;i<N;i++){
        sensorsValue[i] = analogRead(i);
    }
   
    if( W(sensorsValue[0]) && W(sensorsValue[1]) && W(sensorsValue[2]) && W(sensorsValue[3]) && B(sensorsValue[4]) ){ 
        error = 4;
    }else if( W(sensorsValue[0]) && W(sensorsValue[1]) && W(sensorsValue[2]) && B(sensorsValue[3]) && B(sensorsValue[4]) ){
      error = 3;
    }else if( W(sensorsValue[0]) && W(sensorsValue[1]) && W(sensorsValue[2]) && B(sensorsValue[3]) && W(sensorsValue[4]) ){
      error = 2;
    }else if( W(sensorsValue[0]) && W(sensorsValue[1]) && B(sensorsValue[2]) && B(sensorsValue[3]) && W(sensorsValue[4]) ){
      error = 1;
    }else if( W(sensorsValue[0]) && W(sensorsValue[1]) && B(sensorsValue[2]) && W(sensorsValue[3]) && W(sensorsValue[4]) ){
      error = 0;
    }else if( W(sensorsValue[0]) && B(sensorsValue[1]) && B(sensorsValue[2]) && W(sensorsValue[3]) && W(sensorsValue[4]) ){
      error = -1;
    }else if( W(sensorsValue[0]) && B(sensorsValue[1]) && W(sensorsValue[2]) && W(sensorsValue[3]) && W(sensorsValue[4]) ){
      error = -2;
    }else if( B(sensorsValue[0]) && B(sensorsValue[1]) && W(sensorsValue[2]) && W(sensorsValue[3]) && W(sensorsValue[4]) ){
      error = -3;
    }else if( B(sensorsValue[0]) && W(sensorsValue[1]) && W(sensorsValue[2]) && W(sensorsValue[3]) && W(sensorsValue[4]) ){
        error = -4;
    }
    /// check WWWWW
    else if( W(sensorsValue[0]) && W(sensorsValue[1]) && W(sensorsValue[2]) && W(sensorsValue[3]) && W(sensorsValue[4]) ){
        error = pre_error;
    }


   
   motorSpeed = Kp*error + Kd*(error - pre_error) + Ki*(sum_error);
   leftSpeed = baseSpeed + motorSpeed;
   rightSpeed = baseSpeed - motorSpeed;
   
   if(leftSpeed > maxSpeed) leftSpeed = maxSpeed;
   if(rightSpeed > maxSpeed) rightSpeed = maxSpeed;

   if(leftSpeed < -maxSpeed) leftSpeed = -maxSpeed;
   if(rightSpeed < -maxSpeed) rightSpeed = -maxSpeed;
   
   motor(1,leftSpeed);
   motor(2,rightSpeed);
   delay(33);  
   
   pre_error = error;
   sum_error += error;
   
   
//   lcd("e=%d pe=%d|Ls=%d RS=%d|kp=%d kd=%d", error,pre_error, leftSpeed, rightSpeed ,Kp*error, Kd*(error - pre_error) );

          
}

void setup()  
{
     Serial.begin(57600);
     pinMode(DIR1, OUTPUT);
     pinMode(PWM1, OUTPUT);
     pinMode(DIR2, OUTPUT);
     pinMode(PWM2, OUTPUT);
}
void loop()
{
  
   FollowLine();
}
