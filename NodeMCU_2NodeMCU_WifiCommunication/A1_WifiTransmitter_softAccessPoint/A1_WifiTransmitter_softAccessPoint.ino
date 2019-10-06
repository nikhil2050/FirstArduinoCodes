#include <ESP8266WiFi.h>
/*
 * https://blog.zairza.in/esp8266-to-esp8266-communication-without-a-router-fe9642b93292
 */

void setup() {
  Serial.begin(115200);
  Serial.print("\nSetting soft-AP ... ");
  boolean result = WiFi.softAP("Blog_Zairza_In", "BlogZairzaIn");
  
  if(result == true) {
    Serial.println("Ready");
  } else {
    Serial.println("Failed!");
  }
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  delay(3000);
}
