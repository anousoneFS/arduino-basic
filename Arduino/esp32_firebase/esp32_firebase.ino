
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>
#include <DHT.h>

// Set these to run example.
#define FIREBASE_HOST "smart-farm-3ef1a.firebaseio.com"
#define FIREBASE_AUTH "19I22ePTZJdPlsd8AINmtFQwlZHrdlrIWLhj4L2P"
#define WIFI_SSID "XLGO-0AF7"
#define WIFI_PASSWORD "thuekkhakl"
//#define WIFI_SSID "M2_Core"
//#define WIFI_PASSWORD "khoithuekhackleo"

#define DHTPIN 23
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  dht.begin();
}

void CheckWiFi(){
  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    delay(1000);
  }
}
void loop() {
  delay(2000);
//  float t = dht.readTemperature();
//  float h = dht.readHumidity();
//  Serial.println(t , h);
  
  // set value
//  Firebase.setFloat("temp", t);
//  Firebase.setFloat("humid", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /temp & humid failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // get value 
  Serial.print("temperature: ");
  Serial.println(Firebase.getFloat("temp"));
  Serial.print("humidity: ");
  Serial.println(Firebase.getFloat("humid"));

  CheckWiFi();
  
}
