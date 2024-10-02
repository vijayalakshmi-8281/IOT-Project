#include<ESP8266WiFi.h>
#include<WiFiClientSecure.h>
#include<UniversalTelegramBot.h>
#include<ArduinoJson.h>


#define BotToken "6309947602:AAGHAeykO-MvPiqIO4mlG8msZJ_AXy8ocpM"
#define chat_id "1257872657"


char*ssid="Musukoni balence vepinchuko";
char*password="12345678";

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BotToken,client);
int sensor=A0;
int threshold=1024;
void setup() {
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  configTime(0,0,"pool.ntp.org"); 
  client.setTrustAnchors(&cert);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED)
  Serial.print(".");
  delay(1500);
  Serial.println("wifi connected");
}
void loop() {
  int m=analogRead(sensor);
  Serial.println(m);
  if(m<threshold){
    Serial.println("wet");
    bot.sendMessage(chat_id,"moisture is detected in sanitary pads ","");   
    delay(5000);
  }else{
    Serial.println("dry");
  
  }
  

}
