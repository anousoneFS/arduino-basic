#include <virtuabotixRTC.h> //Library used


//Wiring SCLK -> 6, I/O -> 7, CE -> 8
//Or CLK -> 6 , DAT -> 7, Reset -> 8
#define D5 6
#define D6 7
#define D7 8
int previous;
int current;
int diff = 1;

virtuabotixRTC myRTC(D5, D6, D7); //If you change the wiring change the pins here also

void setup() {
 Serial.begin(9600);

// Set the current date, and time in the following format:
 // seconds, minutes, hours, day of the week, day of the month, month, year
 myRTC.setDS1302Time(33, 35, 9, 1, 16, 11, 2019); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done
 //The setup is done only one time and the module will continue counting it automatically
}

void loop() {
 // This allows for the update of variables for time or accessing the individual elements.
 myRTC.updateTime();
 
previous = int(myRTC.seconds);
Serial.print("previous= ");
Serial.println(previous);

// Start printing elements as individuals
 Serial.print("Current Date / Time: ");
 Serial.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
 Serial.print("/");
 Serial.print(myRTC.month);
 Serial.print("/");
 Serial.print(myRTC.year);
 Serial.print(" ");
 Serial.print(myRTC.hours);
 Serial.print(":");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 Serial.println(myRTC.seconds);
// Serial.print(":");
// Serial.println(minute);

// Delay so the program doesn't print non-stop
delay(3000);

myRTC.updateTime();
 current = int(myRTC.seconds);
 Serial.print("current: ");
 Serial.println(current);

//diff = current - previous;
//Serial.print("diff = ");
//Serial.println(diff);

//Serial.println(myRTC.seconds % 60);

}
