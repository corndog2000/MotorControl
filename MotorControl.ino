//Joseph Schroed | FRC RI3D "Full Moon Robotics"

//A delay of 1000 Microseconds is Full Reverse
//A delay of 1000 to 1460 Microseconds is Proportional Reverse
//A delay of 1460 to 1540 Microseconds is neutral
//A delay of 1540 to 2000 Microseconds is Proportional Forward
//A delay of 2000 Microseconds is Full Forward

#include <Servo.h>

int backLeftPin = 7;      //Back Left Motor pin
int backLeftSpeed = 1460; //Back Left Motor starting speed
Servo backLeftMotor;           //Back Left Motor Servo Object

int frontLeftPin = 6;      //Front Left Motor pin
int frontLeftSpeed = 1460; //Front Left Motor starting speed
Servo frontLeftMotor;           //Front Left Motor Servo Object

int backRightPin = 5;      //Back Right Motor pin
int backRightSpeed = 1460; //Back Right Motor starting speed
Servo backRightMotor;           //Back Right Motor Servo Object

int frontRightPin = 4;      //Front Right Motor pin
int frontRightSpeed = 1460; //Front Right Motor starting speed
Servo frontRightMotor;           //Front Right Motor Servo Object

int Speed = 1460;           //Starting speed for Serial communication

void setup()
{
  // Tells each of the servo objects which pin it should output to
  backLeftMotor.attach(backLeftPin);
  frontLeftMotor.attach(frontLeftPin);
  backRightMotor.attach(backRightPin);
  frontRightMotor.attach(frontRightPin);

  Serial.begin(115200);
}

void loop()
{
  // This code is used when controlling using serial

  // FORMAT Example: fr 2000
  // FORMAT Example: a 1500

  // If you send the character "a" then all the motors will run at the provided speed
  // fr -> front right
  // fl -> front left
  // br -> back right
  // bl -> back left
  if (Serial.available() > 0) {
    char fb = Serial.read();
    if (fb == 'a') {
      Speed = Serial.parseInt();
      backLeftSpeed = frontLeftSpeed = backRightSpeed = frontRightSpeed = Speed;
    }
    else {
      char lr = Serial.read();
      Speed = Serial.parseInt();
      if (fb == 'b') {
        if (lr == 'l') {
          backLeftSpeed = Speed;
        }
        else {
          backRightSpeed = Speed;
        }
      }
      else {
        if (lr == 'l') {
          frontLeftSpeed = Speed;
        }
        else {
          frontRightSpeed = Speed;
        }
      }
    }
    Serial.println(Speed);
  }
  
  //This code creates the PWM signal on each pin based on the speed provided
  backLeftMotor.writeMicroseconds(backLeftSpeed);           //Back left motor driver code

  frontLeftMotor.writeMicroseconds(frontLeftSpeed);          //Back right motor driver code

  backRightMotor.writeMicroseconds(backRightSpeed);          //Front left motor driver code

  frontRightMotor.writeMicroseconds(frontRightSpeed);         //Front right motor driver code

}
