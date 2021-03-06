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
float Ki = 0.00035;
float Kp = 0.07;//.08899;
float Kd = 0.7; //0.6
int lastError = 0;

int rightMotorSpeed,leftMotorSpeed;
int rightBaseSpeed=160;
int leftBaseSpeed=160;
int rightMaxSpeed=255;
int leftMaxSpeed=255;

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
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==0 && digitalRead(3)==0 && digitalRead(2)==0) //right turn
  {
    right_turn();
     
  }
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==0 && digitalRead(2)==0) //right turn
  {
    right_turn();
  }
  
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==0 && digitalRead(4)==0 && digitalRead(3)==0 && digitalRead(2)==0) //right turn
  {
     right_turn();   
  }
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==0 && digitalRead(5)==1 && digitalRead(4)==0 && digitalRead(3)==0 && digitalRead(2)==0) //right turn
  {
      right_turn();
  }
  /*if(digitalRead(8)==1 && digitalRead(7)==0 && digitalRead(6)==0 && (digitalRead(5)==1 || digitalRead(4)==0) && digitalRead(3)==0 && digitalRead(2)==0) //right turn
  {
     analogWrite(leftMotorPWM, 150);
     analogWrite(rightMotorPWM, 150);
     digitalWrite(leftMotor1,HIGH); 
      digitalWrite(rmf,LOW);
     digitalWrite(rmb,HIGH);    
     delay(2000);
     digitalWrite(rmb,LOW);
     digitalWrite(rmf,HIGH);
  }*/

  
  if(digitalRead(8)==0 && digitalRead(7)==0 && digitalRead(6)==0 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1) //left turn
  {
    left_turn(); 
  }
  if(digitalRead(8)==0 && digitalRead(7)==0 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1) //left turn
  {
    left_turn();
  }
  if(digitalRead(8)==0 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1) //left turn
  {
    left_turn();
  }
  if(digitalRead(8)==0 && digitalRead(7)==0 && digitalRead(6)==0 && digitalRead(5)==0 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1) //left turn
  {
    left_turn();
  }
  if(digitalRead(8)==0 && digitalRead(7)==0 && digitalRead(6)==0 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead( 3)==1 && digitalRead(2)==0) //left turn
  {
    left_turn();    
  }
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1)
  {
    stop_bot();
    delay(5000);
  }
  else if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==0)
  {
    stop_bot();
    delay(5000);
  }
}
void loop()
{
  sensor();
  

  /*//try2
  if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1)
  {
    stop_bot();
    delay(30000);
    analogWrite(leftMotorPWM, leftBaseSpeed);
    analogWrite(rightMotorPWM,rightBaseSpeed);
    digitalWrite(leftMotor1,HIGH);  
    digitalWrite(rightMotor1,HIGH);
    delay(50);
    if(digitalRead(8)==1 && digitalRead(7)==1 && digitalRead(6)==1 && digitalRead(5)==1 && digitalRead(4)==1 && digitalRead(3)==1 && digitalRead(2)==1)
    {
      stop_bot();
      delay(30000);
    }
  }*/
  
  unsigned int sensors[7];
  signed int position=qtrrc.readLine(sensors);
  int error=position-3000;
  
  Serial.println(error);


  //float p = Kp*error;
  //float I = p+I;
 
  int motorSpeed = Kp * error + Kd * (error - lastError);
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
