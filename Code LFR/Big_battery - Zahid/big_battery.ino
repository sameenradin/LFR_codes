
int l,i,x,error,motorSpeed,m;
float Kp = .127;
int Kd;
int lastError=0;
int rightMotorSpeed,leftMotorSpeed;
int rightBaseSpeed=255;
int leftBaseSpeed=255;
int rightMaxSpeed=255;
int leftMaxSpeed=255;
#define rightMotor1 50
#define rightMotorPWM 11
#define leftMotor1 52
#define leftMotorPWM 12
void setup() { 
   
   int motorspeed;
   pinMode(A0, INPUT);
   pinMode(A1, INPUT); 
   pinMode(A2, INPUT);
   pinMode(A3, INPUT);
   pinMode(A4, INPUT);
   pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  l=0;
  m=1;

}
void loop() {
  x=1;
  
  
 if(l==0)
    {
  if(digitalRead(A2)==m&&digitalRead(A3)==0&&digitalRead(A4)==0&&digitalRead(A0)==0&&digitalRead(A1)==0)
  {
    l=1;
    m=0;
  }
    }
    

      if (digitalRead(A2) == l && digitalRead(A3) == l && digitalRead(A4) == l && digitalRead(A0) == m)
  {
    digitalWrite(50, HIGH);

    analogWrite(11, 255);

    digitalWrite(52, HIGH);

    analogWrite(12, 255 );
    delay(130);
    digitalWrite(50, LOW);
    digitalWrite(51, HIGH);

    analogWrite(11, 255);
    digitalWrite(52, HIGH);



    analogWrite(12, 255 );
    delay(430);
    digitalWrite(51, LOW);
    for (i=0;x<=4;i++)
    {
       if (digitalRead(A2) == l && digitalRead(A3) == l && digitalRead(A4) == l && digitalRead(A0) == m)
  {x=x+1;
  if(x<=2)
  {
    digitalWrite(50, HIGH);

    analogWrite(11, 255);

    digitalWrite(52, HIGH);

    analogWrite(12, 255 );
    delay(130);
    digitalWrite(50, LOW);
    digitalWrite(51, HIGH);

    analogWrite(11, 255);
    digitalWrite(52, HIGH);



    analogWrite(12, 255 );
    delay(430);
    digitalWrite(51, LOW);
  }
  else if(x==3)
  {

     digitalWrite(50, HIGH);

    analogWrite(11, 255);
    digitalWrite(52, LOW);

    digitalWrite(53, HIGH);

    analogWrite(12, 255 );
    delay(800);
    digitalWrite(53, LOW);
    x=4;
  }
  }
  else if (digitalRead(A0) == l && digitalRead(A1) == l && digitalRead(A2) == l && digitalRead(A4) == m)
  {
     if(x==4)
  {
     digitalWrite(50, LOW);
    digitalWrite(51, HIGH);

    analogWrite(11, 255);
    digitalWrite(52, HIGH);



    analogWrite(12, 255 );
    delay(600);
    digitalWrite(51, LOW);
    x=5;
    
  }
  else
  {
    digitalWrite(50, HIGH);

    analogWrite(11, 255);

    digitalWrite(52, HIGH);

    analogWrite(12, 255 );
    delay(130);
    digitalWrite(50, HIGH);

    analogWrite(11, 255);
    digitalWrite(52, LOW);

    digitalWrite(53, HIGH);

    analogWrite(12, 255 );
    delay(430);
    digitalWrite(53, LOW);
    x=5;
  }
  }

else if(digitalRead(A0)==l&&digitalRead(A2)==l)
{
  error=1000;
}
else if(digitalRead(A4)==l&&digitalRead(A2)==l)
{
  error=-1000;
}
else if(digitalRead(A0)==l)
{
  error=1000;
}
else if(digitalRead(A4)==l)
{
  error=-1000;
}
else if(digitalRead(A1)==l&&digitalRead(A2)==l)
{
  error=595.23;
}
else if(digitalRead(A2)==l&&digitalRead(A3)==l)
{
  error=-595.23;
}
else if(digitalRead(A2)==l)
{
 error=0;
}


else if(digitalRead(A1)==l)
{
  error=690.47;
}else if(digitalRead(A3)==l)
{
  error=-690.47;
}


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
  
  analogWrite(11, rightMotorSpeed);
  
  digitalWrite(leftMotor1, HIGH);

  analogWrite(12, leftMotorSpeed);
}

    }
  }
  else if (digitalRead(A0) == l && digitalRead(A1) == l && digitalRead(A2) == l && digitalRead(A4) == m)
  {
    
    digitalWrite(50, HIGH);

    analogWrite(11, 255);

    digitalWrite(52, HIGH);

    analogWrite(12, 255 );
    delay(130);
    digitalWrite(50, HIGH);

    analogWrite(11, 255);
    digitalWrite(52, LOW);

    digitalWrite(53, HIGH);

    analogWrite(12, 255 );
    delay(430);
    digitalWrite(53, LOW);
    for(i=0;x<=4;i++)
    {
        if (digitalRead(A2) == l && digitalRead(A3) == l && digitalRead(A4) == l && digitalRead(A0) == m)
  {x=x+1;
    if (x<=2)
    {
    digitalWrite(4, HIGH);

    analogWrite(5, 255);

    digitalWrite(2, HIGH);

    analogWrite(3, 255 );
    delay(130);
    digitalWrite(4, HIGH);

    analogWrite(5, 255);
    digitalWrite(2, LOW);

    digitalWrite(10, HIGH);

    analogWrite(3, 255 );
    delay(430);
    digitalWrite(10, LOW);
    }
    else if(x==3)
    {
      digitalWrite(4, LOW);
    digitalWrite(12, HIGH);

    analogWrite(5, 255);
    digitalWrite(2, HIGH);



    analogWrite(3, 255 );
    delay(800);
    digitalWrite(12, LOW);
    x=4;
    }
  }
  else if (digitalRead(A0) == l && digitalRead(A1) == l && digitalRead(A2) == l && digitalRead(A4) == m)
  { if(x==4)
  {
    digitalWrite(4, HIGH);

    analogWrite(5, 255);
    digitalWrite(2, LOW);

    digitalWrite(10, HIGH);

    analogWrite(3, 255 );
    delay(600);
    digitalWrite(10, LOW);
  }
  else{
    digitalWrite(4, HIGH);

    analogWrite(5, 255);

    digitalWrite(2, HIGH);

    analogWrite(3, 255 );
    delay(130);
    digitalWrite(4, LOW);
    digitalWrite(12, HIGH);

    analogWrite(5, 255);
    digitalWrite(2, HIGH);



    analogWrite(3, 255 );
    delay(430);
    digitalWrite(12, LOW);
    x=5;
  }
  }






  else if (digitalRead(A0) == l && digitalRead(A2) == l)
  {
    error = 1000;
  }
  else if (digitalRead(A4) == l && digitalRead(A2) == l)
  {
    error = -1000;
  }
  else if (digitalRead(A0) == l)
  {
    error = 1000;
  }
  else if (digitalRead(A4) == l)
  {
    error = -1000;
  }
  else if (digitalRead(A1) == l && digitalRead(A2) == l)
  {
    error = 595.23;
  }
  else if (digitalRead(A2) == l && digitalRead(A3) == l)
  {
    error = -595.23;
  }
  else if (digitalRead(A2) == l)
  {
    error = 0;
  }


  else if (digitalRead(A1) == l)
  {
    error = 690.47;
  } else if (digitalRead(A3) == l)
  {
    error = -690.47;
  }


  int motorSpeed = Kp * error;
  lastError = error;



  int rightMotorSpeed = rightBaseSpeed -  motorSpeed;
  int leftMotorSpeed = leftBaseSpeed +  motorSpeed;

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
  }

else if(digitalRead(A0)==l&&digitalRead(A2)==l)
{
  error=1000;
}
else if(digitalRead(A4)==l&&digitalRead(A2)==l)
{
  error=-1000;
}
else if(digitalRead(A0)==l)
{
  error=1000;
}
else if(digitalRead(A4)==l)
{
  error=-1000;
}
else if(digitalRead(A1)==l&&digitalRead(A2)==l)
{
  error=595.23;
}
else if(digitalRead(A2)==l&&digitalRead(A3)==l)
{
  error=-595.23;
}
else if(digitalRead(A2)==l)
{
 error=0;
}


else if(digitalRead(A1)==l)
{
  error=690.47;
}else if(digitalRead(A3)==l)
{
  error=-690.47;
}


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
  
  analogWrite(11, rightMotorSpeed);
  
  digitalWrite(leftMotor1, HIGH);

  analogWrite(12, leftMotorSpeed);
}


     
  
     
     
     

}
