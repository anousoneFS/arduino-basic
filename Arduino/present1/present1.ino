
#define button_mode 3
#define led_2 4
#define led_3 5
#define Echo_1 6
#define Trig_1 7
#define button_1 8
#define led_1 9
#define buzzer 10
#define Echo_2 11
#define Trig_2 12

int previous = LOW;
int State;
int present = LOW;
int present_2 = LOW;
int readingmode = LOW;
int reading;
int k = HIGH, n;
int m ;
int kon = LOW;
int X = LOW;
int State_1 = LOW;
int State_2 = LOW;
int add;
int breaker = HIGH;
int a, out;
long duration;
int distance;

// ==========================================================

void setup() {
  // put your setup code here, to run once:
  pinMode(button_1, INPUT);
  pinMode(Echo_1, INPUT);
  pinMode(Trig_1, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(button_mode, INPUT);
  pinMode(Echo_2, INPUT);
  pinMode(Trig_2, OUTPUT);
  
  Serial.begin(9600);

}

bool readUltrasonic(){
  digitalWrite(Trig_1, LOW);
delayMicroseconds(2);

digitalWrite(Trig_1, HIGH);
delayMicroseconds(10);

digitalWrite(Trig_1, LOW);

duration = pulseIn(Echo_1, HIGH);
distance = duration * 0.034 / 2;

if( distance < 65){
  return HIGH;
}else{
  return LOW;
}

}

// ===========================================

bool readUltrasonic2(){
  digitalWrite(Trig_2, LOW);
delayMicroseconds(2);

digitalWrite(Trig_2, HIGH);
delayMicroseconds(10);

digitalWrite(Trig_2, LOW);

duration = pulseIn(Echo_2, HIGH);
distance = duration * 0.034 / 2;

if( distance < 65){
  return HIGH;
}else{
  return LOW;
}

}

// ==============================================================

void selectMode(){
  do{
    readingmode = digitalRead(button_mode);  // choose Mode: 1 or 2
    if(readingmode == HIGH && kon == LOW){
      if(X == HIGH){                        // choose Mode 2
        State_1 = LOW;
        State_2 = HIGH;
        m = 2;
        breaker = LOW;
      }else{
        State_1 = HIGH;        // choose Mode 1
        State_2 = LOW;
        m = 1; 
        breaker = LOW;
      }
    }
    kon = readingmode;
  }while(readingmode == HIGH);
}

// ==============================================================================

void mode1 (){
  do{
      digitalWrite(led_1, State_1);
      digitalWrite(led_2, State_2);

      chooseMode_2();
      
      reading = digitalRead(button_1);
      if(reading == HIGH && previous == LOW){
        State = !State;
      }

      digitalWrite(led_3, State);
      delay(100);
      previous = reading;
    }while( m == 1);                       // if m = 2 stop Mode 1 ; come in Mode 2

      digitalWrite(led_3, LOW);           // if stop Mode 1 , led_3 off
}

// ==================================================================

void mode2 (){
  do{
      digitalWrite(led_2 ,State_2);   // State Mode
      digitalWrite(led_1, State_1);

      do{
        chooseMode_1();                    // if button_Mode = HIGH : STOP MODE 2; COME IN MODE 1
        
      }while(readingmode == HIGH);

      State = LOW;
      present = LOW;

      do{
        n = 6;
        present = readUltrasonic();     // sensor out room
        
        if( present == HIGH)
          add = 1;
        
        present_2 = readUltrasonic2();
        if( present_2 == HIGH && add == 1){
          if(State == LOW){
            State = HIGH;
            n = 5;
            add = 0;
          }
        }

        digitalWrite(led_3, State);

        if( n == 5){
          tone(buzzer, 925, 225);
          delay(1000);
        }
      } while (add == 1);

      out = 0;
      k = HIGH;
      n = 0;
      a = LOW;
      present = LOW;

   if ( State == HIGH){
    do{
      if( a == LOW ){
        
        do {
          present_2 = readUltrasonic2();      // sensor in room
          delay(200);
          
          if(present_2 == HIGH && a == LOW){
            do{
              chooseMode_1();                     // if button_Mode = HIHG, stop mode 2 ; come in mode 1
              } while (readingmode == HIGH);
            }
          
           }while( present_2 == HIGH);

          present_2 = LOW;
      }

        a = HIGH;
        delay(100);

        do{
          chooseMode_1();             // if button_Mode = HIGH, stop mode 2 ; come in mode 1
        } while ( readingmode == HIGH);

        present_2 = readUltrasonic2();      // sensor in room
        if(present_2 == HIGH){
          out = 1;
        }

        present = readUltrasonic();         // sensor out room
        if( present == HIGH && out == 1){
          k = LOW;                          // led_3 off or on
        }

        delay(100);
        n++;

     if(n == 40){
      
        tone(buzzer, 988, 250);
        delay(400);
        
        do{
          chooseMode_1();
          
        }while(readingmode == HIGH);
        
        tone(buzzer, 880, 250);
        delay(400);

        do{
          chooseMode_1();
        }while(readingmode == HIGH);
        
        tone(buzzer, 784, 1000);
        delay(1000);

        do{
          chooseMode_1();
        }while(readingmode == HIGH);
        
        tone(buzzer, 784, 1000);
        delay(1000);
      }
       
    } while (k == HIGH && n <= 60);
  }

   digitalWrite(led_3, LOW);

   do{
    present = readUltrasonic();       // sensor out room
     } while (present == HIGH);
   
   delay(100);   
   
   } while (m == 2);            // if m = 1 is Mode 2 off

    digitalWrite( led_3, LOW );     // if stop Mode 2 is led_3 off
    
}

// ======================================================

void chooseMode_1(){
  readingmode = digitalRead(button_mode);     // if readingmode = HIGH; stop Mode2 come in Mode 1
  if(readingmode == HIGH && kon == LOW ){
    m = 1;
    k = LOW;
    State_1 = HIGH;
    State_2 = LOW;
  }
}

// =====================================================

void chooseMode_2(){
  do{
        readingmode = digitalRead(button_mode);         // if readingmode = high; stop mode 1 come in mode 2
        if (readingmode == HIGH && kon == LOW){
          m = 2;
          State_1 = LOW;
          State_2 = HIGH;
          
        }
    }while(readingmode == HIGH);
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void loop() {

    X = LOW;
    State = LOW;
  reading = LOW;

  selectMode();  // Mode 1 or 2

  digitalWrite(led_3, breaker);


  switch(m){
    case 1:               // come in mode 1 if m = 1
    
    mode1();
    
    case 2:                               // come in Mode 2   

    mode2();
  }
  
}
