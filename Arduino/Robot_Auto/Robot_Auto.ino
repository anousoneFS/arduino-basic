//CEIT_Robot_2018 In Loas

int count_sensor = 0;// Count Line 
int last_state_sensor = 0; //Check State before Count Line
    
//set PIN data of line direction sensor
#define  SENSOR_T1 22
#define  SENSOR_T2 23
#define  SENSOR_T3 24
#define  SENSOR_T4 25
#define  SENSOR_T5 26
#define  SENSOR_T6 6
#define  SENSOR_T7 7 

//save to read the reperent from line sensor
int data_sensor_1 = 0;
int data_sensor_2 = 0;
int data_sensor_3 = 0;
int data_sensor_4 = 0;
int data_sensor_5 = 0;
int data_sensor_6 = 0;
int data_sensor_7 = 0;

// set PIN motor and power rolling
#define DIR1 12
#define DIR2 10
#define PWM1 11
#define PWM2 9

// in line speed 
int pwm_l = 90;
int pwm_r = 90;

// turn in line speed 
int pwmTurn_l = 45;
int pwmTurn_r = 45;

// uturn zone speed 
int pwmUturn_l = 60;
int pwmUturn_r = 60;

// states of the robot
#define START 0
#define WAIT 1
#define GO 2
#define DROP_IN 3
#define DROP_OUT 4
#define BACK 5

// colors
#define GREEN 1
#define RED 0
#define BLUE 2

// initial state
int state = GO;
// initla box color
int color = GREEN;
// initial count for checkpoint count
int count = 0;

// IR Box detect
#define BOX_IR 27

// slider
#define PWM_SLDR 4
#define SLDR 5

// Switch
#define SLDR_SW_TOP 52
#define SLDR_SW_BTM 51

// Color Sensor
#define COLOR_S0 47
#define COLOR_S1 48
#define COLOR_S2 49
#define COLOR_S3 50
#define COLOR_SENSOR 53

void setup() {
  Serial.begin(9600);
  //line direction sensor
  pinMode(SENSOR_T1, INPUT);
  pinMode(SENSOR_T2, INPUT);
  pinMode(SENSOR_T3, INPUT);
  pinMode(SENSOR_T4, INPUT);
  pinMode(SENSOR_T5, INPUT);
  pinMode(SENSOR_T6, INPUT);
  pinMode(SENSOR_T7, INPUT);

  //motor and power rolling
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  // Slider
  pinMode(PWM_SLDR, OUTPUT);
  pinMode(SLDR, OUTPUT);

  // Switches
  pinMode(SLDR_SW_TOP, INPUT);
  pinMode(SLDR_SW_BTM, INPUT);

  // Color Sensors
  pinMode(COLOR_S0, OUTPUT);
  pinMode(COLOR_S1, OUTPUT);
  pinMode(COLOR_S2, OUTPUT);
  pinMode(COLOR_S3, OUTPUT);
  pinMode(COLOR_SENSOR, INPUT);
  // Setting Color Sensor frequency scaling to 20%
  digitalWrite(COLOR_S0,HIGH);
  digitalWrite(COLOR_S1,LOW);

  

} //Ending setup fucntion

void loop() {
  Serial.print("state = ");
  Serial.println(state);

  switch(state) {
    case START:
      controlFollowLine(); //FollowLine
      if (detectCheckpoint()) {
        forward(0, 0);
        delay(1000);
        state = WAIT;
      }
      break;
      
    case WAIT:
      // replace with wait for infared sonsor
//      while (!hasBox()) {
//        forward(0, 0);
//        delay(100);
//      }

      do {
        delay(100);
      } while (digitalRead(BOX_IR));

      forward(pwm_l, pwm_r);
      delay(300);
      
      state = GO;
      
      // color = getBoxColor();

      // if (color != -1) {
//          state = GO;
      // } else {
      //   color = getBoxColor();
      // }
      
      break;
    case GO:
      controlFollowLine(); //FollowLine
      if (detectCheckpoint()) {
        delay(100);
        ++count;
      }
      // count == counts to go for color
      if (count == goCheckpointCount(GREEN)) {
//        delay(250);
        count = 0;
        state = DROP_IN;
      }
      break;
      
    case DROP_IN:
      forward(0, 0);
      
      // Drop the box(es)
      while (digitalRead(SLDR_SW_TOP)) {
        analogWrite(PWM_SLDR, 120);
        digitalWrite(SLDR, HIGH);
        delay(100);
      }

      analogWrite(PWM_SLDR, 0);

      state = DROP_OUT;
      
      break;

    case DROP_OUT:

      while (digitalRead(SLDR_SW_BTM)) {
        analogWrite(PWM_SLDR, 120);
        digitalWrite(SLDR, LOW);
        delay(100);
        controlFollowLine();
      }

      analogWrite(PWM_SLDR, 0);
//
//      forward(pwm_l, pwm_r);
//      delay(300);
      
      state = BACK;

      break;
      
    case BACK:
      controlFollowLine(); //FollowLine
      if (detectCheckpoint()) {
        delay(100);
        ++count;
      }
      if (count == backCheckpointCount(color)) {
        state = WAIT;
        color = changeToNextColor(color);
        count = 0;
      }

      break;
  }

} //End_Loop

//control_Sensor
  void control_Sensor()
  {
    //Line Sensor
  data_sensor_1 = digitalRead(SENSOR_T1); // PIN 22
  data_sensor_2 = digitalRead(SENSOR_T2); // PIN 23
  data_sensor_3 = digitalRead(SENSOR_T3); // PIN 24
  data_sensor_4 = digitalRead(SENSOR_T4); // PIN 25
  data_sensor_5 = digitalRead(SENSOR_T5); // PIN 26
  data_sensor_6 = digitalRead(SENSOR_T6); // PIN 6
  data_sensor_7 = digitalRead(SENSOR_T7); // PIN 7   
  }
  
// TODO: SENSOR_T3 is not working must change the new once
void controlFollowLine() 
{
      control_Sensor();
      
      // always moving
      if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      { 
              forward(pwm_l, pwm_r);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 1) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 1) && (data_sensor_7 == 0))
      {
              forward(pwm_l, pwm_r);
      }
      else if ((!data_sensor_6 == 1) && (data_sensor_1 == 0) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 0) && (data_sensor_7 == 1))
      {
              forward(pwm_l, pwm_r);
      }
      else if ((!data_sensor_6 == 1) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 0) && (data_sensor_7 == 1))
      {
              forward(pwm_l, pwm_r);
      }
      else if ((!data_sensor_6 == 1) && (data_sensor_1 == 0) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 1))
      {
              forward(pwm_l, pwm_r);
      }
      else if ((!data_sensor_6 == 1) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 1) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 1))
      {
              forward(pwm_l, pwm_r);
      }
      else if  ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 0) && (data_sensor_7 == 1))
      { 
              forward(pwm_l, pwm_r);
      }
      else if  ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 0) && (data_sensor_7 == 1))
      { 
              forward(pwm_l, pwm_r);
      }
      // turn right in line 
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnRightZone(pwmTurn_l, pwmTurn_r);
      }
      // turn left in line 
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmTurn_l, pwmTurn_r);
      }
      // turn right at the uturn zone
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 1) && (data_sensor_7 == 0))
      {
        uturnRightZone(pwmUturn_l - 5, pwmUturn_r - 5);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 1) && (data_sensor_7 == 0))
      {
        uturnRightZone(pwmUturn_l, pwmUturn_r);
        delay(5);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 1)&& (data_sensor_5 == 1) && (data_sensor_7 == 0))
      {
        uturnRightZone(pwmUturn_l, pwmUturn_r);
        delay(10);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 1)&& (data_sensor_5 == 1) && (data_sensor_7 == 1))
      {
        uturnRightZone(pwmUturn_l - 5, pwmUturn_r - 5);
        delay(20);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 1) && (data_sensor_7 == 0))
      {
        uturnRightZone(pwmUturn_l, pwmUturn_r);
        delay(18);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 1) && (data_sensor_7 == 1))
      {
        uturnRightZone(pwmUturn_l + 13, pwmUturn_r + 25);
        delay(35); 
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 1))
      {
        uturnRightZone(pwmUturn_l + 15, pwmUturn_r + 5);
        delay(40);
      }
      //turn left at the uturn zone
       else if ((!data_sensor_6 == 0) && (data_sensor_1 == 1) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 1)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmUturn_l - 5, pwmUturn_r - 5);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 1) && (data_sensor_2 == 1) && (data_sensor_3 == 1) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmUturn_l - 5, pwmUturn_r - 5);
        delay(5);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 1) && (data_sensor_2 == 1) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmUturn_l, pwmUturn_r);
        delay(10);
      }
      else if ((!data_sensor_6 == 1) && (data_sensor_1 == 1) && (data_sensor_2 == 1) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmUturn_l, pwmUturn_r);
        delay(20);
      }
      else if ((!data_sensor_6 == 0) && (data_sensor_1 == 1) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmUturn_l, pwmUturn_r);
        delay(18);
      }
      else if ((!data_sensor_6 == 1) && (data_sensor_1 == 1) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmUturn_l + 25, pwmUturn_r + 13);
        delay(35);
      }
      else if ((!data_sensor_6 == 1) && (data_sensor_1 == 0) && (data_sensor_2 == 0) && (data_sensor_3 == 0) && (data_sensor_4 == 0)&& (data_sensor_5 == 0) && (data_sensor_7 == 0))
      {
        uturnLeftZone(pwmUturn_l + 5, pwmUturn_r + 15);
        delay(40);
      } 
      else 
      {
        forward(0, 0);
      }
      //delay(100);
} //end control follow line


void forward(int pwm_l, int pwm_r)
{
    //left motor
  digitalWrite(DIRL1, LOW);
  digitalWrite(DIRL2, HIGH);
  analogWrite(PWML, pwm_l);
  //right motor
  digitalWrite(DIRR1, LOW);
  digitalWrite(DIRR2, HIGH);
  analogWrite(PWMR, pwm_r);
} // End forward 

void backward(int pwm_l, int pwm_r)
{
  //left motor
  digitalWrite(DIRL1, HIGH);
  digitalWrite(DIRL2, LOW);
  analogWrite(PWML, pwm_l);
  //right motor
  digitalWrite(DIRR1, HIGH);
  digitalWrite(DIRR2, LOW);
  analogWrite(PWMR, pwm_r);
} // end backward


void uturnLeftZone (int pwm_l, int pwm_r)
{
    //left motor
  digitalWrite(DIRL1, HIGH);
  digitalWrite(DIRL2, LOW);
  analogWrite(PWML, pwm_l);
  //right motor
  digitalWrite(DIRR1, LOW);
  digitalWrite(DIRR2, HIGH);
  analogWrite(PWMR, pwm_r);
}

void uturnRightZone (int pwm_l, int pwm_r)
{
    //left motor
  digitalWrite(DIRL1, LOW);
  digitalWrite(DIRL2, HIGH);
  analogWrite(PWML, pwm_l);
  //right motor
  digitalWrite(DIRR1, HIGH);
  digitalWrite(DIRR2, LOW);
  analogWrite(PWMR, pwm_r);
}
