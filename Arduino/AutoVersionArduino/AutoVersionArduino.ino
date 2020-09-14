
#define MOTOR_A_DIR 2
#define MOTOR_B_DIR 3
#define MOTOR_C_DIR 4
#define MOTOR_D_DIR 5

#define MOTOR_A_PWM 6
#define MOTOR_B_PWM 7
#define MOTOR_C_PWM 8
#define MOTOR_D_PWM 9

void setup(){
  Serial.begin(9600);
  pinMode(MOTOR_A_DIR, OUTPUT);
  pinMode(MOTOR_B_DIR, OUTPUT);
  pinMode(MOTOR_C_DIR, OUTPUT);
  pinMode(MOTOR_D_DIR, OUTPUT);

  pinMode(MOTOR_A_PWM, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);
  pinMode(MOTOR_C_PWM, OUTPUT);
  pinMode(MOTOR_D_PWM, OUTPUT);
  
}

void loop(){
  
  MoveForward();
  delay(2000);
  AllMotorStop();
  delay(1000);
  
  MoveBackward();
  delay(2000);
  AllMotorStop();
  delay(1000);

  TurnLeft();
  delay(2000);
  AllMotorStop();
  delay(1000);

  TurnRight();
  delay(2000);
  AllMotorStop();
  delay(1000);
}

void MoveForward(){
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, LOW);
  analogWrite(MOTOR_A_PWM, 180);
  analogWrite(MOTOR_B_PWM, 180);
}
void MoveBackward(){
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  analogWrite(MOTOR_A_PWM, 180);
  analogWrite(MOTOR_B_PWM, 180);
}

void TurnLeft(){
  digitalWrite(MOTOR_C_DIR, HIGH);
  digitalWrite(MOTOR_D_DIR, HIGH);
  analogWrite(MOTOR_C_PWM, 180);
  analogWrite(MOTOR_D_PWM, 180);
}

void TurnRight(){
  digitalWrite(MOTOR_C_DIR, LOW);
  digitalWrite(MOTOR_D_DIR, LOW);
  analogWrite(MOTOR_C_PWM, 180);
  analogWrite(MOTOR_D_PWM, 180);
}

void RotateLeft(){
  digitalWrite(MOTOR_A_DIR, LOW);
  digitalWrite(MOTOR_B_DIR, LOW);
  digitalWrite(MOTOR_C_DIR, LOW);
  digitalWrite(MOTOR_D_DIR, LOW);
}

void RotateRight(){
  digitalWrite(MOTOR_A_DIR, HIGH);
  digitalWrite(MOTOR_B_DIR, HIGH);
  digitalWrite(MOTOR_C_DIR, HIGH);
  digitalWrite(MOTOR_D_DIR, HIGH);
}

void AllMotorStop(){
  analogWrite(MOTOR_A_PWM, 0);
  analogWrite(MOTOR_B_PWM, 0);
  analogWrite(MOTOR_C_PWM, 0);
  analogWrite(MOTOR_D_PWM, 0);
}
