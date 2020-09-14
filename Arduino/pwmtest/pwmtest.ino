#define DIR_1 2   // PIN ควบคุมทิศทางการหมุนของมอเตอร์ 1
#define PWM_1 3   // PIN ความเร็วของมอเตอร์ 1
#define DIR_2 4   // PIN ควบคุมทิศทางการหมุนของมอเตอร์ 2
#define PWM_2 5   // PIN ความเร็วของมอเตอร์ 2
 
#define SPEED_MOTOR_1 50   // ค่าความเร็วมอเตอร์ 1 มีค่าตั้งแต่ 0 – 255 (Duty Cycle)
#define SPEED_MOTOR_2 50   // ค่าความเร็วมอเตอร์ 2 มีค่าตั้งแต่ 0 – 255 (Duty Cycle)
 
void setup() {
  pinMode(DIR_1, OUTPUT);   // ตั้งค่า DIR_1 ของมอเตอร์ 1 เป็น Output
  pinMode(PWM_1, OUTPUT);   // ตั้งค่า PWM_1 ของมอเตอร์ 1 เป็น Output
  pinMode(DIR_2, OUTPUT);   // ตั้งค่า DIR_2 ของมอเตอร์ 2 เป็น Output
  pinMode(PWM_2, OUTPUT);   // ตั้งค่า PWM_2 ของมอเตอร์ 2 เป็น Output
  analogWrite(PWM_1, SPEED_MOTOR_1);   // สร้างสัญญาณ PWM เป็น Output ให้กับมอเตอร์ 1
  analogWrite(PWM_2, SPEED_MOTOR_2);   // สร้างสัญญาณ PWM เป็น Output ให้กับมอเตอร์ 2
}
 
void loop() {
  digitalWrite(DIR_1, LOW);          // กำหนดทิศทางให้มอเตอร์ 1 หมุนตามเข็มนาฬิกา
  digitalWrite(DIR_2, LOW);          // กำหนดทิศทางให้มอเตอร์ 2 หมุนตามเข็มนาฬิกา
//  delay(1000);                       // หน่วงเวลา 1 วินาที
//  digitalWrite(DIR_1, HIGH);         // กำหนดทิศทางให้มอเตอร์ 1 หมุนทวนเข็มนาฬิกา
//  digitalWrite(DIR_2, HIGH);         // กำหนดทิศทางให้มอเตอร์ 2 หมุนทวนเข็มนาฬิกา
//  delay(1000);                       // หน่วงเวลา 1 วินาที
}
