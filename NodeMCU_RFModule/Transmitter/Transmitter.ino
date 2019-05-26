/**
 * https://github.com/jlarghi/esp8266-mqtt-telegram/blob/master/esp8266-mqtt-telegram.ino
 */ 
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
}

void loop() {
  /* See Example: TypeA_WithDIPSwitches */
/*
  mySwitch.switchOn("11111", "00010");
  delay(1000);
  mySwitch.switchOn("11111", "00010");
  delay(1000);
*/

  /* Same switch as above, but using decimal code */
  mySwitch.send(5393, 24);
  delay(1000);  
  mySwitch.send(5396, 24);
  delay(1000);  

}
