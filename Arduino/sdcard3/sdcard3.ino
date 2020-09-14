#include <SD.h>

//Connect VCC with 5V in the Arduino.
//Then, connect the GND of SD card to the ground of Arduino.
//Connect CS to pin 4
//Connect SCK to pin 13
//MOSI connect to the pin 11
//Lastly, connect MISO to pin 12

File myFile; // สร้างออฟเจค File สำหรับจัดการข้อมูล
String fileName = "temp.csv";

const int chipSelect = 4;

//======================

#include "DHT.h"

#define DHTPIN 2     

#define DHTTYPE DHT22   

DHT dht(DHTPIN, DHTTYPE);

int n = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();

  connect2sdcard();
//  write2file(fileName);
  readfile(fileName);
  
}

void connect2sdcard(){
  Serial.begin(9600);
 
 while (!Serial) {
   ; // รอจนกระทั่งเชื่อมต่อกับ Serial port แล้ว (สำหรับ Arduino Leonardo เท่านั้น)
 }

Serial.print("Initializing SD card...");
pinMode(SS, OUTPUT); // Slave select ตัว library มันจะขอให้เป็น OUTPUT เสมอ 

 if (!SD.begin(chipSelect)) {
  
Serial.println("initialization failed!");
 return;
 
 }
 
Serial.println("initialization done.");

// SD.remove(fileName); //ถ้าต้องการลบไฟล์ทิ้ง

}

void readfile(String filename){
  
  // เปิดไฟล์เพื่ออ่าน ==================================
myFile = SD.open(filename); // สั่งให้เปิดไฟล์ชื่อ cmlog.txt เพื่ออ่านข้อมูล

 if (myFile) {
Serial.println(filename + ":");
 // อ่านข้อมูลทั้งหมดออกมา
 
while (myFile.available()) {
  
  Serial.write(myFile.read());
  
}
 
myFile.close(); // เมื่ออ่านเสร็จ ปิดไฟล์

} else {
 // ถ้าอ่านไม่สำเร็จ ให้แสดง error 
Serial.println("error opening " + filename);
 }
}

//***************************************

void write2file(String filename){

 // ถ้าเปิดไฟล์สำเร็จ ให้เขียนข้อมูลเพิ่มลงไป
 myFile = SD.open(filename, FILE_WRITE); 
 if (myFile) {
Serial.print("Writing to " + filename + "...");
myFile.println("save data to SD Card");

  // เปิดไฟล์ที่ชื่อ fileName เพื่อเขียนข้อมูล โหมด FILE_WRITE ===========================
  myFile = SD.open(filename, FILE_WRITE); 
  
  delay(2000);

  float h = dht.readHumidity();
 
  float t = dht.readTemperature();
  
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(n);
  Serial.print(".) ");
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  myFile.print(n);
  myFile.print(",");
  myFile.print(h);
  myFile.print(",");
  myFile.print(t);
  myFile.print(",");
  myFile.print(f);
  myFile.print(",");
  myFile.print(hic);
  myFile.print(",");
  myFile.println(hif);
  
  n++;
  myFile.close();

 // ปิดไฟล์
Serial.println("done.");

} else {
 // ถ้าเปิดไฟลืไม่สำเร็จ ให้แสดง error 
Serial.println("error opening "+filename);
}

}
void loop() {
  
//  write2file(fileName);
}
