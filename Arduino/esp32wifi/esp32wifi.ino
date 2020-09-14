
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>

// Set these to run example.
#define FIREBASE_HOST "smart-farm-3ef1a.firebaseio.com"
#define FIREBASE_AUTH "19I22ePTZJdPlsd8AINmtFQwlZHrdlrIWLhj4L2P"
#define WIFI_SSID "vivo 1718"
#define WIFI_PASSWORD "anousone123"
#define LIGHT 36

void setup() {
  Serial.begin(9600);
  pinMode(LIGHT, INPUT);
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
}

void loop() {
  // set value
  Firebase.setInt("LIGHT", analogRead(LIGHT));
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /LIGHT failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  // get value 
  Serial.println("LIGHT: " + String(Firebase.getInt("LIGHT")));
  delay(1000);
  
}
