#include<ESP8266WiFi.h>

#define SSID_NAME "CEIT-IoT "
#define SSID_PASS "IoT12345678"

//IPAddress staticIP(192,168,1,2);
//IPAddress gateway(192,168,1,1);
//IPAddress subnet(255,255,255,0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  WiFi.begin(SSID_NAME, SSID_PASS);
//  WiFi.config(staticIP, gateway, subnet);

  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
