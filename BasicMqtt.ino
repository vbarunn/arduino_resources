// basic MQTT PUB and SUB

#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <EEPROM.h>

#define MQTT_SERVER "iot.eclipse.org"   // Server
#define PORT 1883
String id="AA10001001";   // ID
String rfid="Default";
char* outTopic = "pubArunn";  // publish topic
char* inTopic="subArunn";
char* user_name="rabbit";
char* pass_word="rabbit";
const char WiFiAPPSK[] = "dialog123"; //SSID of AP

void callback(char* topic, byte* payload, unsigned int length);
void reconnect();
int publishpress();
String macToStr(const uint8_t* mac);
String IpAddress2String(const IPAddress& ipAddress);



static boolean isOn = false;
static boolean isConnected = false;


WiFiServer server(80);
WiFiClient wifiClient;
PubSubClient client(MQTT_SERVER, PORT, callback, wifiClient);
 
void setup() {
  Serial.begin(9600);
  EEPROM.begin(512);
  char sent1[50];
  connectWifi();
  Serial.println("STart publish");
  reconnect();

  String sent="Rain"; 
  sent.toCharArray(sent1,50);
  int status1= client.publish(outTopic, sent1);
  Serial.println(status1);
    delay(500);
 if (status1==0)
    {
      status1= client.publish(outTopic, sent1);
      
      }
  
  Serial.println(status1);
  Serial.print("MTQQ Finished\n");
  
}



void loop(){
 // client.loop();
}
  
//MQTT callback
void callback(char* topic, byte* payload, unsigned int length) {
	String topicStr = topic; 
	Serial.println("Callback update.");

 String msg=(char*)payload;
	Serial.print("Topic: ");
	Serial.println(msg);
}

void setupWiFi()
{
  WiFi.mode(WIFI_AP);
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX) + String(mac[WL_MAC_ADDR_LENGTH - 1], HEX);
  macID.toUpperCase();
  String AP_NameString = "Smart Button";
  char AP_NameChar[AP_NameString.length() + 1];
  memset(AP_NameChar, 0, AP_NameString.length() + 1);
 
  for (int i=0; i<AP_NameString.length(); i++)
  AP_NameChar[i] = AP_NameString.charAt(i);
  WiFi.softAP(AP_NameChar);
}

int publishpress(){
}

void AP_Mode(){
        Serial.println("\nAP Mode Activated");
       // ENDWHILE=true;
        setupWiFi();
        server.begin();
  }

void reconnect() {
	 int wait=0;
	if(WiFi.status() == WL_CONNECTED){
		while (!client.connected()) {
      wait++;
     
			Serial.print("Attempting MQTT connection...\n");
			String clientName;
			clientName += "esp8266-";
			uint8_t mac[6];
			WiFi.macAddress(mac);
			clientName += macToStr(mac);
			if (client.connect((char*) clientName.c_str())) {
				
        isConnected=true;
		  	client.subscribe(inTopic);
       Serial.print("MTQQ Connected\n");
			}
			else{Serial.println("Failed.\n"); /*abort();*/ isConnected=false;}
		}
	}
}


void connectWifi() //with default passsword
{
 
  Serial.print("Wifi search started");
 

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");

  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);   // this is a temporary line, to be removed after SDK update to 1.5.4  -- to solve connection miss issue >> Arunn
  WiFi.mode(WIFI_STA);
  //WiFi.begin(ssid, password);

  WiFi.begin("Jungle Book", "17242QkWj");
    WiFi.config(IPAddress(192, 168, 10, 108), IPAddress(192, 168, 10, 1), IPAddress(255, 255, 255, 0)); //Static 
  
  int wait=0;
  while (WiFi.status() != WL_CONNECTED) {
    wait++;
    Serial.print(".");
    delay(100);
   
  } 
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("done");
  
  
}

String macToStr(const uint8_t* mac){
  String result;
  for (int i = 0; i < 6; ++i) {
    result += String(mac[i], 16);
    if (i < 5){
      result += ':';
    }
  }
  return result;
}




