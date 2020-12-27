int v = 0;
int ls = A0;
int rs = A1;
int lmf = 8;
int rmf = 9;
int lmb = 12;
int rmb = 13;
int lme = 11;
int rme = 10;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
void forward() {
  analogWrite(lme, 255);
  analogWrite(rme, 255);
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
}
void left() {
  analogWrite(lme, 110);
  analogWrite(rme, 255);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);  
}
void right() {
  analogWrite(lme, 200);
  analogWrite(rme, 0);
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
}

void stop_bot(){
  analogWrite(lme, 0);
  analogWrite(rme, 0);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, LOW);
}

void loop() {
  if (Serial.available() > 0)
  {
    v = Serial.read();
  if (ls>989 && rs>989)
    forward();
    delay(50);
  if (ls<989 && rs>989)
    stop_bot();
   delay(50);
  if (ls<989 && rs>989)
    right();
    delay(50);
  if( ls>989 && rs<989)
    left();
    delay(50);  
}}

