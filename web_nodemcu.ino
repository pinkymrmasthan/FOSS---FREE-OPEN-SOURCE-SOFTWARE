#include<ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>


String inString = "";


int flag;
int cnt=0;
String line1="";
String line2="";
#define rx D1
#define tx D2
String temp3,temp4;
int len;
SoftwareSerial NodeSerial (rx, tx); // RX | TX

#define green D6
#define yellow D5

const char* ssid = "iot";
const char* password = "123456789";

char server[]="http://www.iotcloud22.in/248/post_value.php";

 
 WiFiClient client;
 HTTPClient http;
float l1,l2,l3,l4,l5;
void setup () {
pinMode (rx, INPUT);
pinMode (tx, OUTPUT);

Serial.begin (9600);
NodeSerial.begin (9600);
delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
//  server.begin();
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");  
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);

}  


void status_filter(String buff)
  {
    if(buff[0]=='$')
    if(buff[2]=='G')
    if(buff[4]=='L')
    if(buff[7]=='T')
    if(buff[10]=='H')
    if(buff[13]=='#')
    //$1G3L50T33H74#
    {
      
         String temp1=buff.substring(1,2);
         String temp2=buff.substring(3,4);
         String temp3=buff.substring(5,7);
         String temp4=buff.substring(8,10);
         String temp5=buff.substring(11,13);
     l1=temp1.toFloat();
          l2=temp2.toFloat();
          l3=temp3.toFloat();
          l4=temp4.toFloat();
          l5=temp5.toFloat();
         
         Serial.println(l1);
         Serial.println(l2);
         Serial.println(l3);
         Serial.println(l4);
         Serial.println(l5);
         displaydata();
   }
  }
void status_filter1(String buff)
  {
  
    if(buff[0]=='$')
    if(buff[3]=='G')
    if(buff[6]=='L')
    if(buff[9]=='T')
    if(buff[12]=='H')
    if(buff[15]=='#')
    //$1G3L50T33H74#
    {
      
         String temp1=buff.substring(1,3);
         String temp2=buff.substring(4,6);
         String temp3=buff.substring(7,9);
         String temp4=buff.substring(10,12);
         String temp5=buff.substring(13,15);
     l1=temp1.toFloat();
          l2=temp2.toFloat();
          l3=temp3.toFloat();
          l4=temp4.toFloat();
          l5=temp5.toFloat();
         
         Serial.println(l1);
         Serial.println(l2);
         Serial.println(l3);
         Serial.println(l4);
         Serial.println(l5);
         displaydata();
   }
  }
void status_filter2(String buff)
  {
  
    if(buff[0]=='$')
    if(buff[3]=='G')
    if(buff[5]=='L')
    if(buff[8]=='T')
    if(buff[11]=='H')
    if(buff[14]=='#')
    //$1G3L50T33H74#
    {
      
         String temp1=buff.substring(1,3);
         String temp2=buff.substring(4,5);
         String temp3=buff.substring(6,8);
         String temp4=buff.substring(9,11);
         String temp5=buff.substring(12,14);
   l1=temp1.toFloat();
          l2=temp2.toFloat();
          l3=temp3.toFloat();
          l4=temp4.toFloat();
          l5=temp5.toFloat();
         
         Serial.println(l1);
         Serial.println(l2);
         Serial.println(l3);
         Serial.println(l4);
         Serial.println(l5);
         displaydata();
   }
  }
void status_filter3(String buff)
  {
 
    if(buff[0]=='$')
    if(buff[2]=='G')
    if(buff[5]=='L')
    if(buff[8]=='T')
    if(buff[11]=='H')
    if(buff[14]=='#')
    //$1G3L50T33H74#
    {
      
         String temp1=buff.substring(1,2);
         String temp2=buff.substring(3,5);
         String temp3=buff.substring(6,8);
         String temp4=buff.substring(9,11);
         String temp5=buff.substring(12,14);
          l1=temp1.toFloat();
          l2=temp2.toFloat();
          l3=temp3.toFloat();
          l4=temp4.toFloat();
          l5=temp5.toFloat();
         
         Serial.println(l1);
         Serial.println(l2);
         Serial.println(l3);
         Serial.println(l4);
         Serial.println(l5);
         displaydata();
   }
  }
  
  
void displaydata()
{
  if(l1>20 || l2>20){
    digitalWrite(yellow,HIGH);
digitalWrite(green,LOW);
  }else{
    digitalWrite(yellow,LOW);
digitalWrite(green,HIGH);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    http.begin(client, server);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String httpRequestData = "&value1=" + String(l1) + "&value2=" + String(l2) + "&value3=" + String(l4) + "&value4=" + String(l5) + "&value5=" + String(l3) + "";
    //    Serial.print("httpRequestData: ");
    //    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  delay(1500);
}




 void loop () {
 
while (NodeSerial.available() > 0) {

    char c = NodeSerial.read();
//Serial.print(c);
     if (c == '\n' || c == '\r') {
               if(cnt >=5){
                            status_filter(inString);
                            status_filter1(inString);
                            status_filter2(inString);
                            status_filter3(inString);
                            Serial.println(inString);
                            inString = "";
                            cnt=0;
                           }
                      else
                           { 
                            inString = "";
                            cnt=0;
                            }
                 }
                else
                 {
                 inString +=c;
                 cnt++;
                  }
      
  
    }
  }
