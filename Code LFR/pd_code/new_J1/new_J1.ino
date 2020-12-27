#include<QTRSensors.h>

int a[7];

int i=1;
int error;

int lmf = 52;
int lmb = 50;
 
int rmf = 53;
int rmb = 51;

int lme = 46; 
int rme = 47;

float I =0;
float Ki = 0.002;
float Kp = 0.2;
int Kd = 2;
int lastError = 0;

int rightMotorSpeed,leftMotorSpeed;
int rightBaseSpeed=150;
int leftBaseSpeed=150;
int rightMaxSpeed=180;
int leftMaxSpeed=180;

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
  for(int i=0;i<100;i++)
  {
    qtrrc.calibrate();
    
  }
  
  digitalWrite(13, LOW);
  delay(500);
  
}

void sensor_reading() {

  a[0] = digitalRead(8);
  a[1] = digitalRead(7);
  a[2] = digitalRead(6); 
  a[3] = digitalRead(5);
  a[4] = digitalRead(4);
  a[5] = digitalRead(3);
  a[6] = digitalRead(2);
/* 
Serial.print(a[0]); 
Serial.print(" "); 
Serial.print(a[1]); 
Serial.print(" "); 
Serial.print(a[2]);
Serial.print(" "); 
Serial.print(a[3]); 
Serial.print(" "); 
Serial.print(a[4]); 
Serial.print(" "); 
Serial.print(a[5]); 
Serial.print(" "); 
Serial.println(a[6]);*/
} 

void loop()
{
 sensor_reading(); 
if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1)
  {
  analogWrite(leftMotorPWM, leftBaseSpeed);
   analogWrite(rightMotorPWM,rightBaseSpeed);
   digitalWrite(leftMotor1,HIGH);  
   digitalWrite(rightMotor1,HIGH);
    delay(300);
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1)
  {
    digitalWrite(rightMotor1, LOW);
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, LOW);

  analogWrite(leftMotorPWM, leftMotorSpeed);
  delay(30000);
     }

   if(digitalRead(48)==0 && digitalRead(46)==0 && digitalRead(44)==0 && digitalRead(42)==0 && digitalRead(40)==0 && digitalRead(38)==0 && digitalRead(36)==0)
    {digitalWrite(rightMotor1, LOW);
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, LOW);

  analogWrite(leftMotorPWM, leftMotorSpeed);
  delay(500);
     }
  }
  
  unsigned int sensors[7];
  signed int position=qtrrc.readLine(sensors);
  int error=position-3000;

  Serial.println(error);
  float p = Kp*error;
  float I = p+I;
  int motorSpeed = Kp * error + Kd * (error - lastError)+I*Ki;
  lastError = error;
  
  
  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;
  
    if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed;
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed; 
  if (rightMotorSpeed < 0) rightMotorSpeed = 0;
  if (leftMotorSpeed < 0) leftMotorSpeed = 0;
  
  Serial.print(rightMotorSpeed); 
  Serial.print(" ");
  Serial.println(leftMotorSpeed);
   {
  
  digitalWrite(rightMotor1, HIGH);
  
  analogWrite(rightMotorPWM, rightMotorSpeed);
  
  digitalWrite(leftMotor1, HIGH);

  analogWrite(leftMotorPWM, leftMotorSpeed);
   }
}

