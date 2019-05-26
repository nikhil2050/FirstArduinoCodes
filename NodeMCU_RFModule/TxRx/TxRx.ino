/** 
 *  RF Transmitter and Receiver on single NodeMCU
 *  Ref.: https://github.com/jlarghi/esp8266-mqtt-telegram/blob/master/esp8266-mqtt-telegram.ino
 */
#include <RCSwitch.h>

int txPin = D8;
RCSwitch mySwitch = RCSwitch();

int rxPin = D2;
RCSwitch mySwitch2 = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(txPin);
  mySwitch.enableReceive(rxPin);
}

void loop() {
  /* See Example: TypeA_WithDIPSwitches */
/*
  mySwitch.switchOn("11111", "00010");
  delay(1000);
  mySwitch.switchOn("11111", "00010");
  delay(1000);
*/
  Serial.println("Start");
  /* Same switch as above, but using decimal code */
  mySwitch.send("000000000001010100010001");
  delay(1000);  
/*  mySwitch.send(5396, 24);
  delay(1000);  */

  Serial.println("Txd");

  char *b = NULL;
  if(mySwitch2.available()) {
    //b = dec2binWzerofill(mySwitch2.getReceivedValue(), mySwitch2.getReceivedBitlength());
    Serial.println("Rxd");
    Serial.println(mySwitch2.getReceivedValue());
    mySwitch2.resetAvailable();
  }
//  Serial.println("Rxd");
//  Serial.println(b);
  
  delay(2000);
}

// https://github.com/sui77/rc-switch
static char * dec2binWzerofill(unsigned long Dec, unsigned int bitLength){
  static char bin[64]; 
  unsigned int i=0;

  while (Dec > 0) {
    bin[32+i++] = (Dec & 1 > 0) ? '1' : '0';
    Dec = Dec >> 1;
  }

  for (unsigned int j = 0; j< bitLength; j++) {
    if (j >= bitLength - i) {
      bin[j] = bin[ 31 + i - (j - (bitLength - i)) ];
    }else {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';
  
  return bin;
}
