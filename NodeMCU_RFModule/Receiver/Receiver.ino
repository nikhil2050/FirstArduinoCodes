/**
 * https://github.com/jlarghi/esp8266-mqtt-telegram/blob/master/esp8266-mqtt-telegram.ino
 */ 
#include <RCSwitch.h>

int rxPin = 5;
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(rxPin);
  
}

void loop() {
  char *b = NULL;
  if(mySwitch.available()) {
    b = dec2binWzerofill(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength());
    mySwitch.resetAvailable();
  }
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
