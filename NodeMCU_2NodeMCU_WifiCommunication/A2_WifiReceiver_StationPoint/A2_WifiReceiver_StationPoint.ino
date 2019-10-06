#include <ESP8266WiFi.h>
/*
 * https://blog.zairza.in/esp8266-to-esp8266-communication-without-a-router-fe9642b93292
 */

void setup() {
  Serial.begin(115200);
  WiFi.begin("Blog_Zairza_In", "BlogZairzaIn");  
  Serial.print("\nConnecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
