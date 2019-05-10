/*  
 *  SIG(yellow/orange) - D9
 *  VCC(Red wire)      - 5V
 *  GND(Black/Brown)   - GND
*/

#include <Servo.h>

int servoPin = 9; // D9 Pin
Servo servo;
int servoAngle = 0;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  servo.write(45);  // Turn left to 45deg
  delay(1500);
  servo.write(90);  // Turn left back to 90deg (center pos)
  delay(1500);
  servo.write(135);  // Turn right to 135deg
  delay(1500);
  servo.write(90);  // Turn left back to 90deg (center pos)
  delay(1500);   

  // Move 0 to 180deg
  for(servoAngle=0; servoAngle<180; servoAngle++){
    servo.write(servoAngle);
    delay(50);
  }
  // Move back from 0 to 180deg
  for(servoAngle=180; servoAngle>0; servoAngle--){
    servo.write(servoAngle);
    delay(10);
  }
}
