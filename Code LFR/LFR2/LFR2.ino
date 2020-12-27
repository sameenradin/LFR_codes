int data =0;
int ls = A0;
int rs = A1;
int lmf =8; 
int rmf =9;
int lmb = 12;
int rmb = 13;
int lme = 10;
int rme = 11;
void setup() {
  Serial.begin(9600);
  pinMode(ls, INPUT);
  pinMode(rs, INPUT);
  pinMode(lmf, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmb, OUTPUT);    
  pinMode(lme, OUTPUT);
  pinMode(rme, OUTPUT);  
}

void loop() {
  if (Serial.available() >0)
  {
    if (data == (ls >989 && rs >989))
     forward();
     delay(50);
    if (data == (ls < 989 && rs < 989)) 
     stop_bot();
     delay(50);
    if (data == (ls > 989 && rs < 989))
     left();
     delay(50);
    if (data == (ls < 989 && rs > 989))
     right();
     delay(50);
  }

}

void forward() {
  analogWrite(lme, 255);
  analogWrite(rme, 255);
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);  
}

void stop_bot() {
  analogWrite(lme, 0);
  analogWrite(rme, 0);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);  
}

void right() {
  analogWrite(lme, 255);
  analogWrite(rme, 255);
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, HIGH);
}

void left() {
  analogWrite(lme, 255);
  analogWrite(rme, 255);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, HIGH);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
}

