#include <Wire.h>
#include <Adafruit_MotorShield.h>

#define MOTOR_COUNT 4

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor motors[MOTOR_COUNT] = {
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
  for(int i = 0; i < MOTOR_COUNT; i++) {
    Serial.println("Init Motor: " + String(i));
    motors[i].setSpeed(150);
    motors[i].run(FORWARD);
    motors[i].run(RELEASE);
  }

}

void loop() {
  Serial.println("Running Motors");
  for(int i = 0; i < MOTOR_COUNT; i++) {
    motors[i].run(FORWARD);
  }
  
  delay(1000);

  Serial.println("Stopping Motors");
  for(int i = 0; i < MOTOR_COUNT; i++) {
    motors[i].run(RELEASE);
  }
  
  delay(10000);
}
