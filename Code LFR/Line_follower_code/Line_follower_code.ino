#include<QTRSensors.h>

int s[7];

int error;
int last_error = 0;

int lmf = 34;
int lmb = 32;

int rmf = 30;
int rmb = 28;

int lme = 52;
int rme = 50;

int base_speed = 120;
int left_motor_speed, right_motor_speed;
int max_speed = 180;

char select_turn(unsigned char found_left, unsigned char found_right, unsigned char found_st);
void turn(char dir);
int set_motors(int l, int r);
void pid();

QTRSensorsRC qtrrc((unsigned char[]){8, 7, 6, 5, 4, 3, 2} , 7, 3000, 2);
unsigned int sensorValues[7];

float P;
float I = 0;
float D;
int Output;

float Kp = 0.299;
float Ki = 0.0002;
float Kd = 2.115;
  

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

void loop() {
  pid();
  
  set_motors(120, 120);
  delay(20);
  
  unsigned char found_left = 0;
  unsigned char found_right = 0;
  unsigned char found_st = 0;

  readline();
  if(s[0] == 1)
    found_left = 1;
  if(s[6] == 1)
    found_right = 1;
  if(s[3] == 1)
    found_st = 1;

  unsigned char dir;
  dir = select_turn(found_left, found_right, found_st);
  turn(dir);
}

void readline() {
  s[0] = digitalRead(8);
  s[1] = digitalRead(7);
  s[2] = digitalRead(6); 
  s[3] = digitalRead(5);
  s[4] = digitalRead(4);
  s[5] = digitalRead(3);
  s[6] = digitalRead(2);
  
//Serial.print(s[0]); Serial.print(" "); Serial.print(s[1]); Serial.print(" "); Serial.print(s[2]); Serial.print(" "); Serial.print(s[3]); Serial.print(" "); Serial.print(s[4]); Serial.print(" "); Serial.print(s[5]); Serial.print(" "); Serial.println(s[6]);
}

int Error() {
  readline();
  unsigned int sensors[7];
  signed int position=qtrrc.readLine(sensors);
  int error=position-3000;
  
  Serial.println(error);
}
void pid() {
 Error();
 while(1)
 {
  P = error * Kp;
  I = I + P;
  D = error - last_error;
 
  last_error = error;

  Output = P + I + D;

  left_motor_speed = Output + base_speed;
  right_motor_speed = Output - base_speed;

  if(left_motor_speed > max_speed)
      left_motor_speed = max_speed;
  if(right_motor_speed > max_speed)
      right_motor_speed = max_speed;
  if(left_motor_speed < 0)
      left_motor_speed = 0;
  if( right_motor_speed < 0)
      right_motor_speed = 0; 

Serial.print(left_motor_speed); Serial.print(" "); Serial.println(right_motor_speed);

 {
   analogWrite(lme, left_motor_speed);
   analogWrite(rme, right_motor_speed);
   digitalWrite(lmf, HIGH);
   digitalWrite(lmb, LOW);
   digitalWrite(rmf, HIGH);
   digitalWrite(rmb, LOW);  
 }

readline();
  if(s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0)
  return;
  else if(s[0] == 1 || s[6] == 1)
  return;
 }
}

char select_turn(unsigned char found_left, unsigned char found_right, unsigned char found_st) {
  
  if(found_left == 1)
      return 'L';
   else if(found_st == 1)
      return 'S';      
   else if(found_right == 1)
      return 'R';
   else
      return 'B';
}

void turn(char dir) {
  {
    switch(dir)
    {
      case 'L': 
                set_motors(200, -200);
                delay(350);
                break;
      case 'R': 
                set_motors(-200, 200);
                delay(350);
                break;
      case 'B': 
                set_motors(200, -200);
                delay(650);
                break;
      case 'S':
                break;
      }                      
    }
}

int set_motors( int l, int r) {
  
  if(l>0 && r>0) {
    analogWrite(lme, modl(l));
    analogWrite(rme, modr(r));
    digitalWrite(lmf, HIGH);
    digitalWrite(lmb, LOW);
    digitalWrite(rmf, HIGH);
    digitalWrite(rmb, LOW);    
  }
  if(l<0 && r>0) {
    analogWrite(lme, modl(l));
    analogWrite(rme, modr(r));
    digitalWrite(lmb, HIGH);
    digitalWrite(lmf, LOW);
    digitalWrite(rmf, HIGH);
    digitalWrite(rmb, LOW);
  }
   if(l>0 && r<0) {
    analogWrite(lme, modl(l));
    analogWrite(rme, modr(r));
    digitalWrite(lmf, HIGH);
    digitalWrite(lmb, LOW);
    digitalWrite(rmb, HIGH);
    digitalWrite(rmf, LOW);
  }
  if(l==0 && r==0) {
    analogWrite(lme, modl(l));
    analogWrite(rme, modr(r));
    digitalWrite(lmb, LOW);
    digitalWrite(lmf, LOW);
    digitalWrite(rmf, LOW);
    digitalWrite(rmb, LOW);
  }
}
int modl( int l) {
  if(l<0)
    l = (-1)*l;
  if(l>0)
    l = l;  
}
int modr(int r) {
   if(r<0)
    r = (-1)*r;
   if(r>0)
    r = r; 
}

