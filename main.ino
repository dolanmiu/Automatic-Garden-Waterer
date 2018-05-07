#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Adafruit_DCMotor *motor1 = AFMS.getMotor(1);
// Adafruit_DCMotor *motor2 = AFMS.getMotor(2);
// Adafruit_DCMotor *motor3 = AFMS.getMotor(3);
// Adafruit_DCMotor *motor4 = AFMS.getMotor(4);
Adafruit_DCMotor motors[4] = {
 *AFMS.getMotor(1),
 *AFMS.getMotor(2),
 *AFMS.getMotor(3),
 *AFMS.getMotor(4)
};
void setup() {
  Serial.begin(9600);
  Serial.println("Garden plant waterer");

  // create with the default frequency 1.6KHz
  AFMS.begin();

  // Set the speed to start, from 0 (off) to 255 (max speed)
  for(int i = 0; i < sizeof(motors); i++) {
    motors[i].setSpeed(150);
    motors[i].run(FORWARD);
    motors[i].run(RELEASE);
  }

}

void loop() {
  for(int i = 0; i < sizeof(motors); i++) {
    motors[i].run(FORWARD);
  }
  
  delay(1000);
  
  for(int i = 0; i < sizeof(motors); i++) {
    motors[i].run(RELEASE);
  }
  
  delay(1000);
}
