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

void setup() {
  Serial.begin(38400);
  pinMode(lmf, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lme, OUTPUT);
  pinMode(rme, OUTPUT);
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
void forward() {
  analogWrite(lme, 255);
  analogWrite(rme, 255);
  digitalWrite(lmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(rmb, LOW);
}
void left() {
  analogWrite(lme, 0);
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







void data()
{
  if(r[1]==1 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0){
  error = -150;
  left();
  delay(50);}
  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==1){
  error = +150;
  right();
  delay(50);}
  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==1 && r[5]==0 && r[6]==0 && r[7]==0){
  error = 0;
  forward();
  delay(50);}
  
  else if(r[1]==0 && r[2]==0 && r[3]==1 && r[4]==1 && r[5]==0 && r[6]==0 && r[7]==0){
  error = -44.52;
  left(rme,200);}
  delay(50);
  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==1 && r[5]==1 && r[6]==0 && r[7]==0){
  error = +42.83;
  right(lme,190);
  delay(50);}
  
  else if(r[1]==0 && r[2]==1 && r[3]==1 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0){
  error = -97.60;
  left(rme,150);
  delay(50);}

  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==1 && r[6]==1 && r[7]==0){
  error = +99.42;
  right(lme,150);}
  
  else if(r[1]==1 && r[2]==1 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0){
  error = -150;
  left(rme,50);
  delay(50);}
  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==0 && r[6]==1 && r[7]==1){
  error = +150;
  right(lme,50);
  delay(50);}
  
  else if(r[1]==1 && r[2]==1 && r[3]==1 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0){
  error = -150;
  left(rme,100);
  delay(50);}
  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==1 && r[6]==1 && r[7]==1){
  error = +150;
  right(lme,100);
  delay(50);}
  
  else if(r[1]==0 && r[2]==1 && r[3]==1 && r[4]==1 && r[5]==0 && r[6]==0 && r[7]==0){
  error = -97.60;
  left(lme,200);
  delay(50);}
  
  else if(r[1]==0 && r[2]==0 && r[3]==0 && r[4]==1 && r[5]==1 && r[6]==1 && r[7]==0){
  error = +99.42;
  right(rme,200);
  delay(50);}

  else if(r[1]==0 && r[2]==0 && r[3]==1 && r[4]==0 && r[5]==0 && r[6]==0 && r[7]==0){
  error = -44.52;
  forward(lme,200; rme,200);
  delay(50);}
  
  else (r[1]==0 && r[2]==0 && r[3]==0 && r[4]==0 && r[5]==1 && r[6]==0 && r[7]==0){
  error = +44.83;
  forward(lme,200; rme,200);
  delay(50);}

  Serial.println (error);
  
  }
  


void loop()
{
  sensor_reading();
  //data();

}
