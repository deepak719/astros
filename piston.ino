void piston_close()
{
  digitalWrite(pisa,1);
  digitalWrite(pisb,0);
  Serial.println("Piston Closingggg");
}

void piston_open()
{
  digitalWrite(pisa,0);
  digitalWrite(pisb,1);
  Serial.println("Piston Openinggggg");
}
