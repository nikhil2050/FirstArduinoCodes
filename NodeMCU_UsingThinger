#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "<Account Username>"
#define DEVICE_ID "<Device Name>"
#define DEVICE_CREDENTIAL "<Some Secret Key>"

#define SSID "<WiFi Name>"
#define SSID_PASSWORD "<WiFi Password>"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(D4, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(D4);

  // resource output example (i.e. reading a sensor value)
  thing["analog_data"] >> outputValue(analogRead(A0));

  thing["digital_data"] >> outputValue(digitalRead(D0));
  
  // thing["millis"] >> outputValue(millis());
  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
