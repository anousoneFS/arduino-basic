#include<Wire.h>
#define SLAVE_ADDR 8
#define ANSWERSIZE 20
String answer = "Helloanousone";

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
String temp;

void setup() {
  temp = Dht22();
  // put your setup code here, to run once:
  Wire.begin(SLAVE_ADDR);
  // Function to run when data requested from master
  Wire.onRequest(requestEvent);
  // Function to run when data receive from master
  Wire.onReceive(receiveEvent);
  
  Serial.begin(9600);
  Serial.println("I2C Slave demonstration");
  dht.begin();
}

void receiveEvent(){
  // Read while data receive
  while(0 < Wire.available()){
    byte x = Wire.read();
  }
  Serial.println("receive Event");
}
void requestEvent(){
  // Setup byte Variable in the correct size
  byte response[ANSWERSIZE];
  // Format answer as array
  for(byte i = 0; i < ANSWERSIZE; i++){
    response[i] = (byte)answer.charAt(i);
  }

  // Send response back to master
  Wire.write(response, sizeof(response));
  Serial.println("request Event");
  
}

float Dht22(){
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
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

//  Serial.print(F("Humidity: "));
//  Serial.print(h);
//  Serial.print(F("%  Temperature: "));
//  Serial.print(t);
//  Serial.print(F("°C "));
//  Serial.print(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
  return t;
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  temp = Dht22();
//  Serial.print("temp = ");
//  Serial.println(temp);

}
