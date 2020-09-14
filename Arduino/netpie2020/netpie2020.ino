#include <ESP8266WiFi.h>
//#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "XLGO-0AF7";
const char* password = "67021280";
const char* mqtt_server = "broker.netpie.io";
const int mqtt_port = 1883;
const char* mqtt_Client = "b773645d-9aa1-41af-88e3-0410d354ee9c";
const char* mqtt_username = "EhZQwVqYda7oZjeg86wMm8g6kRFtXRFY";
const char* mqtt_password = "d355n813E9LBhsvLD9*wYyjp8_e*1KNS";
    
WiFiClient espClient;
PubSubClient client(espClient);
char msg[256];

#define DHTTYPE DHT11
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);
float data0;
String data = "";
unsigned long previousMillis=0, previous=0;
int x=0;
float temp, humid;
float sumtemp, sumhumid, sumdata;
#define LED 4

void reconnect() {
  while (!client.connected()) {
  Serial.print("Sensor MQTT connection…");
  if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) {
  Serial.println("connected");
  client.subscribe("@msg/power");
  }
  else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println("try again in 5 seconds");
    delay(5000);
  }
 }
}

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  dht.begin();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]: ");
  String message;
  for (int i = 0; i < length; i++) {
    message = message + (char)payload[i];
  }
  Serial.println(message);
  if (String(topic) == "@msg/power") {
    if (message == "reset") {
      digitalWrite(LED, HIGH);
    }else{
      digitalWrite(LED, LOW);
    }
  }
}


void loop() {

  unsigned long currentMillis = millis();
  if(currentMillis - previous >= 1000){
    previous = currentMillis;
    data0 = random(20,80);
    temp = dht.readTemperature();
    humid = dht.readHumidity();
    Serial.print("temperature : ");
    Serial.print(temp);
    Serial.print(", humidity : ");
    Serial.println(humid);
    data = String(temp) + "," + String(humid) + "," + String(data0) ;
    Serial.println(data);
    data.toCharArray(msg, (data.length() + 1));
    client.publish("@msg/update", msg);

    sumdata += data0;
    sumtemp += temp;
    sumhumid += humid;
    x++;
  }

  
//  Serial.println(" %");
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  if( currentMillis - previousMillis >= 10000){
      previousMillis = currentMillis;
      temp = sumtemp / x;
      humid = sumhumid / x;
      data0 = sumdata / x;
      
      data = "{\"data\": {\"Temperature\":" + String(temp) + ", \"Humidity\":" + String(humid) +",  \"LIGHT\":" + String(data0) + "}}";
      Serial.println(data);
      data.toCharArray(msg, (data.length() + 1));
      client.publish("@shadow/data/update", msg);

      sumtemp = 0;
      sumhumid = 0;
      sumdata = 0;
      x = 0;
  }

}
