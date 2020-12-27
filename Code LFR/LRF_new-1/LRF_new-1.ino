int i=1;
int s[5];
int lme = 8; 
int lmf = 9;
int lmb = 10;
int rmf = 11;
int rmb = 12;
int rme = 13;
int r[5];
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
   if(data== 0b00100) {
    analogWrite(lme, 48);
    analogWrite(rme, 42);
    go();
   }
   if(data== 0b01110) {
    analogWrite(lme, 48);
    analogWrite(rme, 42);
    go();
   }
   if(data== 0b01000) {
    analogWrite(lme, 24);
    analogWrite(rme, 42);
    go();
   }
   if(data== 0b01100) {
    analogWrite(lme, 36);
    analogWrite(rme, 42);
    go();
   }
   if(data== 0b10000) {
    analogWrite(lme, 18);
    analogWrite(rme, 42);
    go();
   }      
   if(data== 0b11000) {
    analogWrite(lme, 18);
    analogWrite(rme, 42);
    go();
   }
    if(data== 0b11100) {
    analogWrite(lme, 18);
    analogWrite(rme, 42);
    go();
   } 
    if(data== 0b00001) {
    analogWrite(lme, 48);
    analogWrite(rme, 18);
    go();
   }
   if(data== 0b00010) {
    analogWrite(lme, 48);
    analogWrite(rme, 21);
    go();
   }
   if(data== 0b00011) {
    analogWrite(lme, 48);
    analogWrite(rme, 30);
    go();
   }      
   if(data== 0b00110) {
    analogWrite(lme, 48);
    analogWrite(rme, 30);
    go();
   }
    if(data== 0b00111) {
    analogWrite(lme, 48);
    analogWrite(rme, 18);
    go();
   } 

   if(data==0b00000) {
    stopbot();
    delay(50);
    go();
   }
   if(data==0b00000) {
    stopbot();                                                                                                                                                                                                                                                                                                                                                     
   }
   
}

void go() {
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
}
void stopbot() {
  analogWrite(lme, 0);
  analogWrite(rme, 0);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
}

void sensor_reading() {
  s[1] = analogRead(A0);
  s[2] = analogRead(A1);
  s[3] = analogRead(A2); 
  s[4] = analogRead(A3);
  s[5] = analogRead(A4);

  for(i=1;i<=5;i++)
  {
    if(s[i]<100)
    r[i]=0;
    else
    r[i]=1;
    
  }


  /*if(s1<80) {
    r1=0;
  }
  if(s1>400) {
    r1=1;
  }
  if(s2<100) {
    r2=0;
  }
  if(s2>400) {
    r2=1;
  }   
  if(s3<100) {
    r3=0;
  }
  if(s3>400) {
    r3=1;
  }
  if(s4<100) {
    r4=0;
  }
  if(s4>400) {
    r4=1;
  } 
  if(s5<80) {
    r5=0;
  }
  if(s5>400) {
    r5=1;
  }*/

/*Serial.print(r1);
Serial.print(" ");
Serial.print(r2);
Serial.print(" ");
Serial.print(r3);
Serial.print(" ");
Serial.print(r4);
Serial.print(" ");
Serial.println(r5);
*/
data= r[5]*16+r[4]*8+r[3]*4+r[2]*2+r[1]*1;
}
