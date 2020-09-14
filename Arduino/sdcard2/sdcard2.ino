#include <SD.h>

File myFile; // สร้างออฟเจค File สำหรับจัดการข้อมูล
String fileName = "text.txt";

const int chipSelect = 4;
int n = 1;
void setup(){

  connect2sdcard();
  write2file(fileName);
//  readfile(fileName);

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

 SD.remove(fileName); //ถ้าต้องการลบไฟล์ทิ้ง

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

void write2file(String filename){
  // เปิดไฟล์ที่ชื่อ fileName เพื่อเขียนข้อมูล โหมด FILE_WRITE ===========================
myFile = SD.open(filename, FILE_WRITE); 

 // ถ้าเปิดไฟล์สำเร็จ ให้เขียนข้อมูลเพิ่มลงไป
 if (myFile) {
Serial.print("Writing to " + filename + "...");

myFile.println("bung soud");
for(int j = 2 ; j <= 10 ; j++ ){
  for(int i = 1 ; i <= 12 ; i++){
//    myFile.println(j, "x" ,i," = ",j*i); // สั่งให้เขียนข้อมูล  
    myFile.print(j);
    myFile.print(" x ");
    myFile.print(i);
    myFile.print(" = ");
    myFile.println(j*i);
  }
  myFile.println("==========");
}

myFile.close(); // ปิดไฟล์
Serial.println("done.");

} else {
  
 // ถ้าเปิดไฟลืไม่สำเร็จ ให้แสดง error 
Serial.println("error opening "+filename);

}
}
void loop(){

if(n <= 3){
  readfile(fileName);  
  n ++;
  Serial.println("read again");
  if(n == 3){
    myFile = SD.open(fileName, FILE_WRITE); 
    myFile.println("This is data in SDCard");
    myFile.close();
  }
}

}
