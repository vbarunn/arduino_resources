/*
 *  This sketch demonstrates how to set up a simple HTTP-like server.
 *  The server will set a GPIO pin depending on the request
 *    http://server_ip/gpio/0 will set the GPIO2 low,
 *    http://server_ip/gpio/1 will set the GPIO2 high
 *  server_ip is the IP address of the ESP8266 module, will be 
 *  printed to Serial when the module is connected.
 */

#include <ESP8266WiFi.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(3,OUTPUT);
  digitalWrite(3, 0);
  pinMode(4,OUTPUT);
  digitalWrite(4, 0);
  pinMode(5,OUTPUT);
  digitalWrite(5, 0);
 
  // prepare GPIOs  
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  WiFi.config(IPAddress(192,168,8,115), IPAddress(192,168,8, 1), IPAddress(255, 255, 255, 0));
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
//  client.flush(); //--------------------------------------------------------------------

  // Prepare the response
/*  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  s += (val)?"high":"low";
  s += "</html>\n";

  // Send the response to the client
  client.print(s);*/

  printc(client,req);
  
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}



void printc(WiFiClient client,String readString)
{
Serial.println(readString);
client.println("HTTP/1.1 200 OK"); //send new page
client.println("Content-Type: text/html");
client.println();
client.println("<HTML>");
client.println("<HEAD>");
client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
client.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"https://dl.dropboxusercontent.com/s/u2wwrwordmqxaxk/autohome0.css?dl=0\" />");
client.println("</HEAD>");
client.println("<body bgcolor=\"#D0D0D0\">");
client.println("<hr/>");
client.println("<hr/>");
client.println("<h4><center><img border=\"2\" src=\"https://dl.dropbox.com/s/fmrq1cc8yef4rpp/ImageGen.jpg?dl=0\" /></center></h4>");
client.println("<hr/>");
client.println("<hr/>");
client.println("<br />");
client.println("<br />");
client.println("<br />");
client.println("<a href=\"/?relay1on\"\">ON Hall Light</a>");
client.println("<a href=\"/?relay1off\"\">OFF Hall Light</a><br />");
client.println("<br />");
client.println("<br />");
client.println("<br />");
client.println("<a href=\"/?relay2on\"\">ON Bathroom Light</a>");
client.println("<a href=\"/?relay2off\"\">OFF Bathroom Light</a><br />");
client.println("<br />");
client.println("<br />");
client.println("<br />");
client.println("<a href=\"/?relay3on\"\">ON Bedroom Light</a>");
client.println("<a href=\"/?relay3off\"\">OFF Bedroom Light</a><br />");
client.println("<br />");
client.println("<br />");
client.println("<br />");
client.println("<a href=\"/?relay4on\"\">ON Kitchen Light</a>");
client.println("<a href=\"/?relay4off\"\">OFF Kitchen Light</a><br />");
client.println("<br />");
client.println("<br />");
client.println("<br />");
client.println("<a href=\"/?relay5on\"\">ON Front Light</a>");
client.println("<a href=\"/?relay5off\"\">OFF Front Light</a><br />");
client.println("<br />");
client.println("<br />");
  if(readString.indexOf("?relay1on") >0)
  {
  digitalWrite(3, HIGH);
  Serial.println("Led1 On");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
  client.println("<br />");
  }
  else{
  if(readString.indexOf("?relay1off") >0)
  {
  digitalWrite(3, LOW);
  Serial.println("Led1 Off");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");
  client.println("<br />");
  }
  }
  
  if(readString.indexOf("?relay2on") >0)
  {
  digitalWrite(4, HIGH);
  Serial.println("Led2 On");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
  client.println("<br />");
  }
  else{
  if(readString.indexOf("?relay2off") >0)
  {
  digitalWrite(4, LOW);
  Serial.println("Led2 Off");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");
  client.println("<br />");
  }
  }
  if(readString.indexOf("?relay3on") >0)
  {
  digitalWrite(5, HIGH);
  Serial.println("Led3 On");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
  client.println("<br />");
  }
  
  else{
  if(readString.indexOf("?relay3off") >0)
  {
  digitalWrite(5, LOW);
  Serial.println("Led3 Off");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");
  client.println("<br />");
  }
  }
  if(readString.indexOf("?relay4on") >0)
  {
  digitalWrite(2, HIGH);
  Serial.println("Led4 On");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
  client.println("<br />");
  }
  else{
  if(readString.indexOf("?relay4off") >0)
  {
  digitalWrite(2, LOW);
  Serial.println("Led4 Off");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");
  client.println("<br />");
  }
  }
  if(readString.indexOf("?relay5on") >0)
  {
  digitalWrite(5, HIGH);
  Serial.println("Led5 On");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
  client.println("<br />");
  }
  else{
  if(readString.indexOf("?relay5off") >0)
  {
  digitalWrite(5, LOW);
  Serial.println("Led5 Off");
  client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");
  client.println("<br />");
  }
  }
readString="";
client.println("</body>");
client.println("</HTML>");
delay(1);
//client.stop(); ----------------------------------------------------------

}

