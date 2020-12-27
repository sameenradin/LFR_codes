int s1;
int s2;
int s3;
int s4;
int s5; 
int s6;
int lmf = 8;
int rmf = 9;
int lmb = 12;
int rmb = 13;
int lme = 11;
int rme = 10;
int r1, r2, r3, r4, r5, r6;
int data;

void setup() {
  Serial.begin(9600);
  pinMode(lmf, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lme, OUTPUT);
  pinMode(rme, OUTPUT);
}



void loop() {
  sensor_reading();
   if(data== 0b001100) {
    analogWrite(lme, 255);
    analogWrite(rme, 255);
    go();
   }
   if(data== 0b000110) {
    analogWrite(lme, 255);
    analogWrite(rme, 175);
    go();
   }
    if(data== 0b011000) {
    analogWrite(lme, 175);
    analogWrite(rme, 255);
    go();
   }
   if(data== 0b000011) {
    analogWrite(lme, 255);
    analogWrite(rme, 150);
    go();
   }
   if(data== 0b110000) {
    analogWrite(lme, 150);
    analogWrite(rme, 255);
    go();
   }
   if(data==0b000000) {
    stop_bot();
   }
   
}

void go() {
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
}

void sensor_reading() {
  s1 = analogRead(A0);
  s2 = analogRead(A1);
  s3 = analogRead(A2); 
  s4 = analogRead(A3);
  s5 = analogRead(A4);
  s6 = analogRead(A5);


  if(s1<175) {
    r1=1;
  }
  if(s1>175) {
    r1=0;
  }
  if(s2<165) {
    r2=1;
  }
  if(s2>165) {
    r2=0;
  }   
  if(s3<190) {
    r3=1;
  }
  if(s3>190) {
    r3=0;
  }
  if(s4<195) {
    r4=1;
  }
  if(s4>195) {
    r4=0;
  } 
  if(s5<170) {
    r5=1;
  }
  if(s5>200) {
    r5=0;
  }
  if(s6<160) {
    r6=1;
  }
  if(s6>160) {
    r6=0;
  }

Serial.print(r1);
Serial.print(" ");
Serial.print(r2);
Serial.print(" ");
Serial.print(r3);
Serial.print(" ");
Serial.print(r4);
Serial.print(" ");
Serial.print(r5);
Serial.print(" ");
Serial.println(r6);

data= r6*32+r5*16+r4*8+r3*4+r2*2+r1*1;
}
void stop_bot() {
  analogWrite(lme, 0);
  analogWrite(rme, 0);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
}
