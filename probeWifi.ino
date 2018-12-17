
#include <ESP8266WiFi.h>

//SSID of your network 
char ssid[] = "$DB2this_is_a_NodeMCU";
//password of your WPA Network 
char pass[] = "secretPassword";

void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
 Serial.begin(9600);
 Serial.print("WiFi started   ");

 
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(millis());
 WiFi.begin(ssid, pass);
  delay(500);
 
 Serial.println(millis());
 Serial.print("Gone sleep");
 //beep(1000);
// ESP.deepSleep(10 * 1000000);
  delay(20000);
Serial.println("looping");
}


void beep(int tt){
  
  while(tt-->1)
  {
    digitalWrite(2,LOW);
    delayMicroseconds(180);
    
    digitalWrite(2,HIGH);
    delayMicroseconds(180);
  }
  
 digitalWrite(2,LOW);
}
