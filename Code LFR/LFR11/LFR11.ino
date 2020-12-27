int s2;
int s3;
int s4;
int lmf = 8;
int rmf = 9;
int lmb = 12;
int rmb = 13;
int lme = 11;
int rme = 10;
int r2, r3, r4;
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
   if(data== 0b010) {
    analogWrite(lme, 150);
    analogWrite(rme, 150);
    go();
   }
   if(data== 0b100) {
    analogWrite(lme, 100);
    analogWrite(rme, 150);
    go();
   }
    if(data== 0b001) {
    analogWrite(lme, 150);
    analogWrite(rme, 100);
    go();
   }
   if(data== 0b110) {
    analogWrite(lme, 0);
    analogWrite(rme, 125);
    go();
   }
   if(data== 0b011) {
    analogWrite(lme, 125);
    analogWrite(rme, 0);
    go();
   }
   if(data==0b000) {
    stop_bot();
   }
   if(data==0b111) {
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
  
  s2 = analogRead(A1);
  s3 = analogRead(A2); 
  s4 = analogRead(A3);


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


Serial.print(r2);
Serial.print(" ");
Serial.print(r3);
Serial.print(" ");
Serial.println(r4);


data= r4*4+r3*2+r2*1;
}
void stop_bot() {
  analogWrite(lme, 0);
  analogWrite(rme, 0);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
}
