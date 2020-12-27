#include<QTRSensors.h>

int s[7];

int i=1;
int error;
 
int lmf = 52;
int lmb = 50;
 
int rmf = 53;
int rmb = 51;

int lme = 46; 
int rme = 47;

int I = 0;
float Ki = 0.0026;
float Kp = 0.26;//.08899;
float Kd = 2.6;
int lastError = 0;

int rightMotorSpeed,leftMotorSpeed;
int rightBaseSpeed=240;
int leftBaseSpeed=240;
int rightMaxSpeed=250;
int leftMaxSpeed=250;

#define rightMotor1 53
#define rightMotorPWM 47
#define leftMotor1 52
#define leftMotorPWM 46

QTRSensorsRC qtrrc((unsigned char[]){8, 7, 6, 5, 4, 3, 2} , 7, 3000, 2);
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
  for(int i=0;i<150;i++)
  {
    qtrrc.calibrate();
    
  }
  
  digitalWrite(13, LOW);
  delay(500);
  
}

void sensor() {
  s[0] = digitalRead(8);
  s[1] = digitalRead(7);
  s[2] = digitalRead(6); 
  s[3] = digitalRead(5);
  s[4] = digitalRead(4);
  s[5] = digitalRead(3);
  s[6] = digitalRead(2);
  
Serial.print(s[0]);
Serial.print(" ");
Serial.print(s[1]);
Serial.print(" ");
Serial.print(s[2]);
Serial.print(" ");
Serial.print(s[3]);
Serial.print(" ");
Serial.print(s[4]);
Serial.print(" ");
Serial.print(s[5]);
Serial.print(" ");
Serial.println(s[6]);

}
 
void sharpturn() {
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==0 && digitalRead(3)==0 && digitalRead(2)==0)
  {
     analogWrite(leftMotorPWM, 200);
     analogWrite(rightMotorPWM, 50);
     digitalWrite(leftMotor1,HIGH);  
     digitalWrite(rmb,LOW);     
  }
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==0 && digitalRead(2)==0)
  {
     analogWrite(leftMotorPWM, 200);
     analogWrite(rightMotorPWM, 50);
     digitalWrite(leftMotor1,HIGH);  
     digitalWrite(rmb,LOW);    
  }
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==0 && digitalRead(4)==0 && digitalRead(3)==0 && digitalRead(2)==0)
  {
     analogWrite(leftMotorPWM, 200);
     analogWrite(rightMotorPWM, 50);
     digitalWrite(leftMotor1,HIGH);  
     digitalWrite(rmb,LOW);    
  }
  if(digitalRead(8)==0 && digitalRead(7)==0 && digitalRead(6)==0 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1)
  {
     analogWrite(leftMotorPWM, 50);
     analogWrite(rightMotorPWM, 200);
     digitalWrite(lmb,HIGH);  
     digitalWrite(rightMotor1,HIGH);     
  }
  if(digitalRead(8)==0 && digitalRead(7)==0 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1) 
  {
     analogWrite(leftMotorPWM, 50);
     analogWrite(rightMotorPWM, 200);
     digitalWrite(lmb,HIGH);  
     digitalWrite(rightMotor1, HIGH);    
  }
  if(digitalRead(8)==0 && digitalRead(7)==0 && digitalRead(6)==0 && digitalRead(5)==0 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1) 
  {
     analogWrite(leftMotorPWM, 50);
     analogWrite(rightMotorPWM, 200);
     digitalWrite(lmb,HIGH); 
     digitalWrite(rightMotor1, HIGH);    
  }
}
void loop()
{
  sensor();
  
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==0)
  {
  analogWrite(leftMotorPWM, leftBaseSpeed);
   analogWrite(rightMotorPWM,rightBaseSpeed);
   digitalWrite(leftMotor1,HIGH);  
   digitalWrite(rightMotor1,HIGH);
    delay(250);
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==0)
  {
    digitalWrite(rightMotor1, LOW);
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, LOW);

  analogWrite(leftMotorPWM, leftMotorSpeed);
  delay(30000);
     }
  }
  
  unsigned int sensors[7];
  signed int position=qtrrc.readLine(sensors);
  int error=position-3000;
  
  Serial.println(error);


  float p = Kp*error;
  float I = p+I;
 
  int motorSpeed = Kp * error + Kd * (error - lastError) + I*Ki;
  lastError = error;
  
  
  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed;
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; 
  if (rightMotorSpeed < 0) rightMotorSpeed = 0;
  if (leftMotorSpeed < 0) leftMotorSpeed = 0;
  
//  Serial.println(rightMotorSpeed);
 //Serial.println(leftMotorSpeed);
   {
  
  digitalWrite(rightMotor1, HIGH);
  
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, HIGH);

  analogWrite(leftMotorPWM, leftMotorSpeed);
   }
   sharpturn();
}
