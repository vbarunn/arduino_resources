void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//*johnjgjjhhnn#20$168.9
while(Serial.available()){
String data=Serial.readString();

String name1=data.substring(data.indexOf("*")+1,data.indexOf("#"));
String age=data.substring(data.indexOf("#")+1,data.indexOf("$"));
String height=data.substring(data.indexOf("$")+1);

String printdata= "Name : "+name1+"Age : "+age+"Height : " +height;
Serial.println(printdata);

  
}

delay(1000);
}
