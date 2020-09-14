int num = 2;
char str[] = "test"; // create a string
  char out_str[40]; // output from string functions placed here
    // general purpose integer
   int n = 0;
   String fileName = String("test");
   
void setup() {
   
   Serial.begin(9600);
  
   
   
}

void loop() {
num++;

String number = String(num);
fileName = String("test" + number + ".csv");

Serial.println(fileName);

delay(1000);
  
}
