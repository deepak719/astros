void direction1()
{
  digitalWrite(rdir1,1);
  analogWrite(rpwm1,fullspd);
}

void direction2()
{
  digitalWrite(rdir1,0);
  analogWrite(rpwm1,fullspd);
}
