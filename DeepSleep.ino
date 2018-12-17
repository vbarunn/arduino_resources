// Final  30/03/2017  form mqttdefaulttest.ino    

#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <EEPROM.h>

int now=0;
void setup() {
  Serial.begin(9600);
 
  Serial.print("ESP started");
  now=millis();
  
}



void loop(){

  now=millis();
  Serial.println(now);
 ESP.deepSleep(10* 1000000);
}
  



