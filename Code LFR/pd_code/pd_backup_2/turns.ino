void right_turn()
{
  digitalWrite(rmf, HIGH);
  digitalWrite(lmf, HIGH);
  analogWrite(leftMotorPWM, 150); 
  analogWrite(rightMotorPWM, 150); 
  delay(350);
  digitalWrite(rmf, LOW);
  digitalWrite(rmb, HIGH);
  delay(600);
  digitalWrite(rmb, LOW);
  digitalWrite(rmf, HIGH);
  
   
}
void left_turn()
{
  digitalWrite(rmf, HIGH);
  digitalWrite(lmf, HIGH);
  analogWrite(leftMotorPWM, 150); 
  analogWrite(rightMotorPWM, 150); 
  delay(350);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, HIGH);
  delay(600);
  digitalWrite(lmb, LOW);
  digitalWrite(lmf, HIGH);
}
void stop_bot()
{
  digitalWrite(rmf, LOW);
  analogWrite(rightMotorPWM, 0);
  digitalWrite(lmf, LOW);
  analogWrite(leftMotorPWM,0);
  digitalWrite(rmb, LOW);
  digitalWrite(lmb, LOW); 
}
