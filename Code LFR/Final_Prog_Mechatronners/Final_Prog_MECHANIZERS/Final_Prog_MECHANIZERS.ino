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
  s[1] = analogRead(A0);
  s[2] = analogRead(A1);
  s[3] = analogRead(A2); 
  s[4] = analogRead(A3);
  s[5] = analogRead(A4);
  s[6] = analogRead(A5);
  s[7] = analogRead(A6);

for(i=1; i<=7; i++)
  {
    if(s[i]<100)
    {
      r[i]=0;
    }
    else
    {
      r[i]=1;
      }
    }

Serial.print(r[1]);
Serial.print(" ");
Serial.print(r[2]);
Serial.print(" ");
Serial.print(r[3]);
Serial.print(" ");
Serial.print(r[4]);
Serial.print(" ");
Serial.print(r[5]);
Serial.print(" ");
Serial.print(r[6]);
Serial.print(" ");
Serial.println(r[7]);

} 
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
  


void loop()
{
  unsigned int sensors[7];
  signed int position=qtrrc.readLine(sensors);
  int erorr=position-3250;
  Serial.println(erorr);
  

}
