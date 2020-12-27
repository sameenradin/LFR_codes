#include<QTRSensors.h>
int s[7];
int i=1;
int error;
int lme = 8; 
int lmf = 9;
int lmb = 10;
int rmf = 11;
int rmb = 12;
int rme = 13;
int r[7];
int data1;
float Kp = .37;
int Kd;
int lastError=0;
int rightMotorSpeed,leftMotorSpeed;
int rightBaseSpeed=255;
int leftBaseSpeed=255;
int rightMaxSpeed=255;
int leftMaxSpeed=255;
#define rightMotor1 11
#define rightMotorPWM 13
#define leftMotor1 9
#define leftMotorPWM 8
QTRSensorsRC qtrrc((unsigned char[]){32, 34, 36, 38, 40, 42, 44} ,7,2500,2);
unsigned int sensorValues[7];

void setup() {
  Serial.begin(38400);
  pinMode(lmf, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lme, OUTPUT);
  pinMode(rme, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  for(int i=0;i<100;i++)
  {
    qtrrc.calibrate();
    
  }
  
  digitalWrite(13, LOW);
  delay(500);
  
}

void sensor_reading() {
  s[1] = digitalRead(32);
  s[2] = digitalRead(34);
  s[3] = digitalRead(36); 
  s[4] = digitalRead(38);
  s[5] = digitalRead(40);
  s[6] = digitalRead(42);
  s[7] = digitalRead(44);






} 

  


void loop()
{
  
  if(digitalRead(32)==1 && digitalRead(34)==1 && digitalRead(36)==1 && digitalRead(38)==1 && digitalRead(40)==1 && digitalRead(42)==1 && digitalRead(44)==1)
  {
    delay(50);
    if(digitalRead(32)==1 && digitalRead(34)==1 && digitalRead(36)==1 && digitalRead(38)==1 && digitalRead(40)==1 && digitalRead(42)==1 && digitalRead(44)==1)
     {digitalWrite(rightMotor1, LOW);
  
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, LOW);

  analogWrite(leftMotorPWM, leftMotorSpeed);
  delay(10000);
     }
  }
  unsigned int sensors[7];
  signed int position=qtrrc.readLine(sensors);
  int error=position-3000;
  
  
  
  int motorSpeed = Kp * error;
  lastError = error;
  
  
  

  int rightMotorSpeed = rightBaseSpeed + 2*motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - 2*motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed;
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; 
  if (rightMotorSpeed < 0) rightMotorSpeed = 0;
  if (leftMotorSpeed < 0) leftMotorSpeed = 0;
  
   {
  
  digitalWrite(rightMotor1, HIGH);
  
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, HIGH);

  analogWrite(leftMotorPWM, leftMotorSpeed);
   }
  /*Serial.print(digitalRead(32));
  Serial.print(digitalRead(34));
  Serial.print(digitalRead(36));
  Serial.print(digitalRead(38));
  Serial.print(digitalRead(40));
  Serial.print(digitalRead(42));
  Serial.println(digitalRead(44));*/
  
  

}
