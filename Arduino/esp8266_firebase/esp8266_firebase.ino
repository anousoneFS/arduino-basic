/* Copyright 2018 Electrical Engineering Enterprise Group.
 *  ESP-EP.9_Firebase
 *  
 *  Dev.Jukrapun Chitpong
 */
 #include <DHT.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti WiFiMulti;

// FIREBASE NAME/SECRET Config 
#define PROJECT_IO "smart-farm-3ef1a.firebaseio.com"
#define DATA_SECRET "19I22ePTZJdPlsd8AINmtFQwlZHrdlrIWLhj4L2P"

// WiFi Access Config
#define SSID_1 "CEIT-IoT"
#define PASS_1 "IoT12345678" 
#define LED 4
#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LED, OUTPUT);
  Serial.end();
  Serial.begin(115200);
  delay(10);
  SetWiFi();
  CheckWiFi();
  
  Firebase.begin(PROJECT_IO, DATA_SECRET);
  dht.begin(); 
}

void loop() {
  CheckWiFi();
  Firebase_SET();
  Firebase_GET();
}

void Firebase_SET(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Firebase.set("temp", t);
  Firebase.set("humid", h);
  delay(500);
}

void Firebase_GET(){
  int VALUE_A = Firebase.get("users/my key");
  Serial.println("users/my key: " + String(VALUE_A));

  if(VALUE_A == 0){
    digitalWrite(LED, LOW);
  }else{
    digitalWrite(LED, HIGH);
  }
  delay(500);
}

void CheckWiFi(){
  while(WiFiMulti.run() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    delay(1000);
  }
}

void SetWiFi(){
  Serial.print("\n\nElectricl Engineering Enterprise Group\n");
  WiFiMulti.addAP(SSID_1, PASS_1);  
  WiFiMulti.addAP("AndroidAP", "ifmd0883");
  Serial.println("Connecting Wifi...");
  delay(2000);  
  Serial.println("Connecting Wifi...");
  if (WiFiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}
