#include<QTRSensors.h>
int s[7];
int i=1;
int error;
int lme = 10; 
int lmf = 8;
int lmb = 9;
int rmf = 7;
int rmb = 6;
int rme = 5;
int r[7];
int data1;
float Kp = .321;
int Kd = 2.799;
int lastError = 0;
int rightMotorSpeed,leftMotorSpeed;
int rightBaseSpeed=195;
int leftBaseSpeed=195;
int rightMaxSpeed=255;
int leftMaxSpeed=255;
#define rightMotor1 7
#define rightMotorPWM 5
#define leftMotor1 8
#define leftMotorPWM 10
QTRSensorsRC qtrrc((unsigned char[]){30, 32, 34, 36, 38, 40, 42} ,7,3000,2);
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
  s[7] = digitalRead(30);
  s[1] = digitalRead(32);
  s[2] = digitalRead(34);
  s[3] = digitalRead(36); 
  s[4] = digitalRead(38);
  s[5] = digitalRead(40);
  s[6] = digitalRead(42);






} 
/* 
void data()
{
  if(r[1]==1 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0)
  error = -150;
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==1)
  error = +150;
  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==1 && r[5]==0 && r[6]==0 && r[7]==0)
  error = 0;
  
  else if(r[1]==0 && r[2]==0 && r[3]==1 && r[4]==1 && r[5]==0 && r[6]==0 && r[7]==0)
  error = -44.32;
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==1 && r[5]==1 && r[6]==0 && r[7]==0)
  error = +42.35;
  
  else if(r[1]==0 && r[2]==1 && r[3]==1 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0)
  error = -95.45;
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==1 && r[6]==1 && r[7]==0)
  error = +94.59;
  
  else if(r[1]==1 && r[2]==1 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0)
  error = -150;
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==1 && r[7]==1)
  error = +150;
  
  else if(r[1]==1 && r[2]==1 && r[3]==1 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0)
  error = -150;
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==1 && r[6]==1 && r[7]==1)
  error = +150;
  
  else if(r[1]==0 && r[2]==1 && r[3]==1 && r[4]==1 && r[5]==0 && r[6]==0 && r[7]==0)
  error = -95.45;
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==1 && r[5]==1 && r[6]==1 && r[7]==0)
  error = +94.59;

  else if(r[1]==0 && r[2]==0 && r[3]==1 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0)
  error = -44.32;
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==1 && r[6]==0 && r[7]==0)
  error = +42.35;

  Serial.println (error);
  
  }
  */


void loop()
{
  
  if(digitalRead(30)==1 && digitalRead(32)==1 && digitalRead(34)==1 && digitalRead(36)==1 && digitalRead(38)==1 && digitalRead(40)==1 && digitalRead(42)==1)
  {
  analogWrite(leftMotorPWM, leftBaseSpeed);
   analogWrite(rightMotorPWM,rightBaseSpeed);
   digitalWrite(leftMotor1,HIGH);  
   digitalWrite(rightMotor1,HIGH);
    delay(200);
    if(digitalRead(30)==1 && digitalRead(32)==1 && digitalRead(34)==1 && digitalRead(36)==1 && digitalRead(38)==1 && digitalRead(40)==1 && digitalRead(42)==1)
    {digitalWrite(rightMotor1, LOW);
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, LOW);

  analogWrite(leftMotorPWM, leftMotorSpeed);
  delay(15000);
     }
  }
  unsigned int sensors[7];
  signed int position=qtrrc.readLine(sensors);
  int error=position-3000;
  
  Serial.println(error);
  
  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;
  
  
  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;
  
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
}
