
//char ssid[] = "XLGO-0AF7";
//char pass[] = "67021280";

#define BLYNK_PRINT Serial
#define SOLENOID D2

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//char auth[] = "mwayr9v3KZBWIrv3KXVyWCZx9AwIYreB";
char auth[] = "eRGkXIdxGQj8y50qVC2p0uYwjLfmgQgI";
char ssid[] = "XLGO-0AF7";
char pass[] = "67021280";

bool switchStatus = 0; // 0 = manual,1=auto
int soilMoistureLimit = 0;
bool manualSwitch = 0;

BlynkTimer timer;

// sync all status
BLYNK_CONNECTED() {
    Blynk.syncAll();
}

// update switchStatus
BLYNK_WRITE(V0)
{   
  switchStatus = param.asInt(); // Get value as integer
}

// update soilMosture setting
BLYNK_WRITE(V1)
{   
  soilMoistureLimit = param.asInt(); // Get value as integer
}

// update manualSwitch
BLYNK_WRITE(V2)
{
  manualSwitch = param.asInt();
}

void manualAutoAction()
{
  Serial.print("switchStatus = ");
  Serial.println(switchStatus);
  Serial.print("soimoi = ");
  Serial.println(soilMoistureLimit);
  Serial.print("manualSwitch = ");
  Serial.println(manualSwitch);
  
  if(switchStatus)
  {
    // auto
    if(analogRead(A0) < soilMoistureLimit)
    {
      // D6 connect relay 
      digitalWrite(SOLENOID,LOW);
    }  
    else
    {
      digitalWrite(SOLENOID,HIGH);
    }
  }
  else
  {
    if(manualSwitch)
    {
      digitalWrite(SOLENOID,LOW);
    }
    else
    {
      digitalWrite(SOLENOID,HIGH);
    }
    // manaul
  }
}

void checkTemp()
{
  Serial.println("CheckTemp");
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(SOLENOID,OUTPUT);
  digitalWrite(SOLENOID,HIGH);
  
  Blynk.begin(auth, ssid, pass);

  // key
  timer.setInterval(1000L, manualAutoAction);
  timer.setInterval(10000L, checkTemp);
}

void loop()
{
  Blynk.run();
  timer.run();
}
