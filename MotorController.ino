//A delay of 1000 Microseconds is Full Reverse
//A delay of 1000 to 1460 Microseconds is Proportional Reverse
//A delay of 1460 to 1540 Microseconds is neutral
//A delay of 1540 to 2000 Microseconds is Proportional Forward
//A delay of 2000 Microseconds is Full Forward

int backLeft = 7;        //Back Left Motor pin
int backLeftSpeed = 1460; //Back Left Motor starting speed

int frontLeft = 6;        //Front Left Motor pin
int frontLeftSpeed = 1460; //Front Left Motor starting speed

int backRight = 5;        //Back Right Motor pin
int backRightSpeed = 1460; //Back Right Motor starting speed

int frontRight = 4;        //Front Right Motor pin
int frontRightSpeed = 1460; //Front Right Motor starting speed

int Speed = 1460;           //Starting speed for Serial communication

void setup()
{
  pinMode(backLeft, OUTPUT);    //Makes the pins outputs
  pinMode(frontLeft, OUTPUT);
  pinMode(backRight, OUTPUT);
  pinMode(frontRight, OUTPUT);

  Serial.begin(250000);
}

void loop()
{
  // This code is used when controlling using serial
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

  //My owm PWM code because analogWrite 0-255 is not precise enough
  digitalWrite(backLeft, HIGH);           //Back left motor driver code
  delayMicroseconds(backLeftSpeed);
  digitalWrite(backLeft, LOW);
  delayMicroseconds(backLeftSpeed);

  digitalWrite(backRight, HIGH);          //Back right motor driver code
  delayMicroseconds(backRightSpeed);
  digitalWrite(backRight, LOW);
  delayMicroseconds(backRightSpeed);

  digitalWrite(frontLeft, HIGH);          //Front left motor driver code
  delayMicroseconds(frontLeftSpeed);
  digitalWrite(frontLeft, LOW);
  delayMicroseconds(frontLeftSpeed);

  digitalWrite(frontRight, HIGH);         //Front right motor driver code
  delayMicroseconds(frontRightSpeed);
  digitalWrite(frontRight, LOW);
  delayMicroseconds(frontRightSpeed);
}
