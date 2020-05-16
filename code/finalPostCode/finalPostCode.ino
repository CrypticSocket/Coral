#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "test1";
const char* password = "test123123";

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password); 
  Serial.print("\n\nConnecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(" .");
  }
  Serial.println();
  Serial.println("Connection Successful");

}

void loop() {
  // Calculate Data Here

  String data = "asdasd";
  postDataToServer(data);
}

void postDataToServer(String data)
{
  if(WiFi.status()== WL_CONNECTED){

   HTTPClient http;   
   
   String dataString = "{\"description\":\"Finally Created\",\"public\":\"true\",\"files\":{\"data.txt\":{\"content\":\"df gggggggn\"}}}"; 
   
   http.begin("https://api.github.com/gists/add6f0a7427b7d735b18f111acddbca9","59:74:61:88:13:CA:12:34:15:4D:11:0A:C1:7F:E6:67:07:69:42:F5");
   http.addHeader("Accept-Encoding", "*/*");
   http.addHeader("Content-Type", "application/x-www-form-urlencoded", "Content-Length", dataString.length());
   http.addHeader("Connection", "close");
   http.addHeader("Authorization", "token 50c52dd68b03df0ae539c80cb36ef9428e3824fd");  

   int httpResponseCode = http.PATCH(dataString);   
   String response = http.getString();
   if(httpResponseCode>0){

    String response = http.getString();   

    Serial.println("HTTP CODE: " + httpResponseCode);
    Serial.println("Response\n" + response);          

   }else{

    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);

   }

   http.end();

 }else{
    Serial.println("Error in WiFi connection");
 }
  delay(6000000000000000000000000);
}
