
#define button_mode 3
#define led_2 4
#define led_3 5
#define sensor 6
#define sensor_2 7
#define button_1 8
#define led_1 9
#define buzzer 10
int previous = LOW;
int State;
int present = LOW;
int present_2 = LOW;
int readingmode = LOW;
int reading;
int k = HIGH, n;
int m;
int kon = LOW;
int X = LOW;
int State_1 = LOW;
int State_2 = LOW;
int add;
int breaker = HIGH;
int a, out;

void setup() {
  // put your setup code here, to run once:
  pinMode(button_1, INPUT);
  pinMode(sensor, INPUT);
  pinMode(sensor_2, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(button_mode, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  X = LOW;
  State = LOW;
  reading = LOW;

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

  digitalWrite(led_3, breaker);


  switch(m){
    case 1:               // come in mode 1 if m = 1
    do{
      digitalWrite(led_1, State_1);
      digitalWrite(led_2, State_2);

      do{
        readingmode = digitalRead(button_mode);         // if readingmode = high; stop mode 1 come in mode 2
        if (readingmode == HIGH && kon == LOW){
          m = 2;
          State_1 = LOW;
          State_2 = HIGH;
          Serial.println(readingmode);
          delay(200);
          
        }
      }while(readingmode == HIGH);

      reading = digitalRead(button_1);
      if(reading == HIGH && previous == LOW){
        if( State == HIGH )
          State = LOW;
        else
          State = HIGH;
      }

      digitalWrite(led_3, State);
      delay(100);
      previous = reading;
    }while( m == 1);                       // if m = 2 stop Mode 1 ; come in Mode 2

        digitalWrite(led_3, LOW);           // if stop Mode 1 , led_3 off

    case 2:                               // come in Mode 2   

    do{
      digitalWrite(led_2 ,State_2);   // State Mode
      digitalWrite(led_1, State_1);

      do{
        addmode_1();                    // if button_Mode = HIGH : STOP MODE 2; COME IN MODE 1
        
      }while(readingmode == HIGH);

      State = LOW;
      present = LOW;

      do{
        n = 6;
        present = digitalRead(sensor);     // sensor out room
        if( present == HIGH){
          add = 1;
        }

        present_2 = digitalRead(sensor_2);
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
          present_2 = digitalRead(sensor_2);      // sensor in room
          delay(200);
          if(present_2 == HIGH && a == LOW){
            do{
              addmode_1();                     // if button_Mode = HIHG, stop mode 2 ; come in mode 1
            } while (readingmode == HIGH);
          }
        }while( present_2 == HIGH);

          present_2 = LOW;
      }

        a = HIGH;
        delay(100);

        do{
          addmode_1();             // if button_Mode = HIGH, stop mode 2 ; come in mode 1
        } while ( readingmode == HIGH);

        present_2 = digitalRead(sensor_2);      // sensor in room
        if(present_2 == HIGH){
          out = 1;
        }

        present = digitalRead(sensor);         // sensor out room
        if( present == HIGH && out == 1){
          k = LOW;                          // led_3 off or on
        }

        delay(100);
        n++;

       if(n == 40){
        tone(buzzer, 988, 250);
        delay(400);
        do{
          addmode_1();
          
        }while(readingmode == HIGH);
        tone(buzzer, 880, 250);
        delay(400);

        do{
          addmode_1();
        }while(readingmode == HIGH);
        
        tone(buzzer, 784, 1000);
        delay(1000);

        do{
          addmode_1();
        }while(readingmode == HIGH);
        tone(buzzer, 784, 1000);
        delay(1000);
       }
    } while (k == HIGH && n <= 60);
   }

   digitalWrite(led_3, LOW);

   do{
    present = digitalRead(sensor);       // sensor out room
   } while (present == HIGH);
   delay(100);  
    
    } while (m == 2);            // if m = 1 is Mode 2 off

    digitalWrite( led_3, LOW );     // if stop Mode 2 is led_3 off
  }

}

void addmode_1(){
  readingmode = digitalRead(button_mode);     // if readingmode = HIGH; stop Mode2 come in Mode 1
  if(readingmode == HIGH && kon == LOW ){
    m = 1;
    k = LOW;
    State_1 = HIGH;
    State_2 = LOW;
  }
}
