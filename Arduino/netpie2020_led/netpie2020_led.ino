#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define PIR 15
#define relay 4

const char* ssid = "XLGO-0AF7";
const char* password = "67021280";
const char* mqtt_server = "broker.netpie.io";
const int mqtt_port = 1883;
const char* mqtt_Client = "475b6ac8-27ce-46ca-b187-187f4b42ac39";
const char* mqtt_username = "6frcemX79qwTnftzqbs4L1UU2oreca8g";
const char* mqtt_password = "64no6(kJzMlCiG!2pu3UCyz$YtoSdaoi";

char msg[100];
char Msg[100];
int lighting = 0;
int PIRstate = 0;
int period = 1500;
unsigned long countTime = 0;
String data;
WiFiClient espClient;
PubSubClient client(espClient);

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection…");
    if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) {
      Serial.println("Connected");
      client.subscribe("@msg/LEDstatus");
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println("Try again in 5 seconds...");
      delay(5000);
    }
  }
}

void onoff(int lighting) {
  if (lighting == 1){
    Serial.println("Turn on the light!");
    digitalWrite(relay,HIGH);
    data = "{\"data\" : {\"LEDstatus\" : \"on\"}}";
    data.toCharArray(Msg, (data.length() + 1));
    client.publish("@shadow/data/update", msg);
  } 
  else if (lighting == 0) {
    Serial.println("Turn off the light!");
    digitalWrite(relay,LOW);
    data = "{\"data\" : {\"LEDstatus\" : \"off\"}}";
    data.toCharArray(Msg, (data.length() + 1));
    client.publish("@shadow/data/update", msg);
  }  
}

void callback(char* topic,byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]: ");
  String msg;
  for (int i = 0; i < length; i++) {
    msg = msg + (char)payload[i];
  }
   Serial.println(msg);
  if (String(topic) == "@msg/LEDstatus") {
    if (msg == "on"){
      lighting = 1;
      onoff(lighting); 
    } 
    else if (msg == "off") {
      lighting = 0;
      onoff(lighting);
    } 
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("HELLO :)");
  pinMode(relay,OUTPUT);
  pinMode(PIR,INPUT);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  if(millis() >= countTime + period) {
    PIRstate = digitalRead(PIR);
    countTime += period;
    if (PIRstate == LOW) {
      Serial.println("Motion absent");
    }
    else if (PIRstate == HIGH) {
      Serial.println("Motion detected :)");
      lighting = lighting + 1;
      if (lighting == 2) {
        lighting = 0;
      }
        onoff(lighting);  
      } 
    }
  client.loop();
}
