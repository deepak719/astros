void left()
{
     digitalWrite(dir1, 1);
     analogWrite(pwm1,(spd/2));
     digitalWrite(dir2, 1);
     analogWrite(pwm2, spd/2);
     digitalWrite(dir3, 1);
     analogWrite(pwm3, spd);
     Serial.println("LEFFFFTTTTT");
}

void holo()
{
  

  

  
  
}
void right()
{
      digitalWrite(dir1, 0);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd/2);
      digitalWrite(dir3, 0);
      analogWrite(pwm3,  spd);
      Serial.println("RIGHHHHTTT");
}

void forward()
{
      digitalWrite(dir1, 0);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 1);
      analogWrite(pwm2, spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
      Serial.println("FORWARDDDDDD");
}

void reverse()
{
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
      Serial.println("REVERSEEEEEE");

}

void clockwise()
{
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 1);
      analogWrite(pwm2, spd/2);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, spd/2);
      Serial.println("CLOCKWISEEEEEE");
}

void anticlock () 
{
      digitalWrite(dir1, 0);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 0);
      analogWrite(pwm2, spd/2);
      digitalWrite(dir3, 1);
      analogWrite(pwm3, spd/2);
      Serial.println("ANTI-CLOCKWISEEEEEE");
}

void joystick()
{
  int s1=0,s2=0,s3=0;
  int d1,d2,d3;
   x=PS4.getAnalogHat(LeftHatX);
   y=PS4.getAnalogHat(LeftHatY);
   x=map(x,0,255,-128,127);
   y=map(y,0,255,127,-128);
 
   if((x<=-10 || x>=10)&&(y>10 || y<=-10))
     {
      int sp=0;
      float ang;
       ang=atan2(y,x);
       ang=ang*(180/3.14);
        
      if(ang<0)
      {
        ang=map(ang,-179,-1,181,359); 
      }
      Serial.println("Angle : " + String(ang));

     
      
      if(ang<=30 && ang>0 )
      {
          spd=map(y,0,127,200,60);

      Serial.print(F("\r\nRight "));
      
      digitalWrite(dir1, 0);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd/2);
      digitalWrite(dir3, 0);
      analogWrite(pwm3,  spd);
      Serial.println(ang);
      Serial.println("RIGHHHHTTT");
      }
      else if(ang>30 && ang<=60)
      {

          spd=map(y,0,127,200,60);
        
          digitalWrite(dir1, 0);
        analogWrite(pwm1, spd);
        digitalWrite(dir2, 0);
        analogWrite(pwm2,0);
        digitalWrite(dir3, 0);
        analogWrite(pwm3, spd);
         Serial.println(ang);
         Serial.println("NORTH EAST");
      }
      else if(ang>60 && ang<=90)
      {
        
          spd=map(y,0,127,200,60);
       digitalWrite(dir1, 0);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 1);
      analogWrite(pwm2, spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
       Serial.println(ang);
      Serial.println("FORWARDDDDDD");
      }
      else if(ang>90 && ang<=120)
      {
          spd=map(y,0,127,200,60);
       digitalWrite(dir1, 0);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 1);
      analogWrite(pwm2, spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
       Serial.println(ang);
      Serial.println("FORWARDDDDDD");
      }
          else if(ang>120 && ang<=150)
      {
       
          spd=map(y,0,127,200,60);
       digitalWrite(dir1, 0);
        analogWrite(pwm1, 0);
        digitalWrite(dir2, 1);
        analogWrite(pwm2,spd);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, spd);
        Serial.println(ang);
      Serial.println("NORTH WEST");
      }
      else if(ang>150 && ang<=180)
      {
          spd=map(y,0,127,200,60);
      Serial.print(F("\r\nLeft "));
      
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 1);
      analogWrite(pwm2,spd/2);
      digitalWrite(dir3, 1);
      analogWrite(pwm3,  spd);
       Serial.println(ang);
      Serial.println("LEFTTT"); 
      }
      else if(ang>180 && ang<=210)
      {
          spd=map(y,0,-128,200,60);
      Serial.print(F("\r\nLeft "));
      
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 1);
      analogWrite(pwm2,spd/2);
      digitalWrite(dir3, 1);
      analogWrite(pwm3,  spd);
       Serial.println(ang);
      Serial.println("LEFTTT"); 
      }
      else if(ang>210 && ang<=240)
      {
        
          spd=map(y,0,-128,200,60);
         digitalWrite(dir1, 1);
        analogWrite(pwm1, spd);
        digitalWrite(dir2, 0);
        analogWrite(pwm2,0);
        digitalWrite(dir3 ,1);
        analogWrite(pwm3, spd);
         Serial.println(ang);
      Serial.println("SOUTH WEST");
      }
      else if(ang>240 && ang<=270)
      {
           spd=map(y,0,-128,200,60);
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
       Serial.println(ang);
      Serial.println("REVERSEEEEEE");
      }
       else if(ang>270 && ang<=300)
      {
        spd=map(y,0,-128,200,60);
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
       Serial.println(ang);
      Serial.println("REVERSEEEEEE");
      }
      else if(ang>300 && ang<=330)
      {
               spd=map(y,0,-128,200,60);
         digitalWrite(dir1, 0);
        analogWrite(pwm1, 0);
        digitalWrite(dir2, 0);
        analogWrite(pwm2,spd);
        digitalWrite(dir3, 0);
        analogWrite(pwm3, spd);
         Serial.println(ang);
      Serial.println("SOUTH EAST");
      }
      else if(ang>330 && ang<360)
      {
        spd=map(y,0,-128,200,60);
          digitalWrite(dir1, 0);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd/2);
      digitalWrite(dir3, 0);
      analogWrite(pwm3,  spd);
      Serial.println(ang);
      Serial.println("RIGHHHHTTT");
      }
      else
      {
        digitalWrite(dir1, 0);
      analogWrite(pwm1, 0);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,0);
      digitalWrite(dir3, 0);
      analogWrite(pwm3,  0);
      Serial.println("STOP");
      }
    } 
    
   /*if (x == 127) {
      spd=map(x,0,127,0,200);

      Serial.print(F("\r\nRight "));
      
      digitalWrite(dir1, 0);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd/2);
      digitalWrite(dir3, 0);
      analogWrite(pwm3,  spd);
      Serial.println("RIGHHHHTTT");
      
    }
  if (x == -128) {
        spd=map(x,-128,0,200,0);
      Serial.print(F("\r\nLeft "));
      
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd/2);
      digitalWrite(dir2, 1);
      analogWrite(pwm2,spd/2);
      digitalWrite(dir3, 1);
      analogWrite(pwm3,  spd);
      Serial.println("LEFTTT");
      
    }
 if (y == 127) {
       spd=map(y,0,127,0,200);
       digitalWrite(dir1, 0);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 1);
      analogWrite(pwm2, spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
      Serial.println("FORWARDDDDDD");
      
    }
  if (y == -128) {
       spd=map(y,-128,0,200,0);
      digitalWrite(dir1, 1);
      analogWrite(pwm1, spd);
      digitalWrite(dir2, 0);
      analogWrite(pwm2,spd);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
      Serial.println("REVERSEEEEEE");
      
    }
    if(x>0 && y>0)
       {
        
         digitalWrite(dir1, 0);
        analogWrite(pwm1, spd);
        digitalWrite(dir2, 0);
        analogWrite(pwm2,0);
        digitalWrite(dir3, 0);
        analogWrite(pwm3, spd);
         Serial.println(x);
           Serial.println(y);
     }
   if(x>0 && y<0)
      {
       
         digitalWrite(dir1, 0);
        analogWrite(pwm1, 0);
        digitalWrite(dir2, 0);
        analogWrite(pwm2,spd);
        digitalWrite(dir3, 0);
        analogWrite(pwm3, spd);
  Serial.println(x);
           Serial.println(y);
      }
    if(x<0 && y>0)
      {
         digitalWrite(dir1, 0);
        analogWrite(pwm1, 0);
        digitalWrite(dir2, 1);
        analogWrite(pwm2,spd);
        digitalWrite(dir3, 1);
        analogWrite(pwm3, spd);
 Serial.println(x);
           Serial.println(y);
       }
  if(x<0 && y<0)
       {
         digitalWrite(dir1, 1);
        analogWrite(pwm1, spd);
        digitalWrite(dir2, 0);
        analogWrite(pwm2,0);
        digitalWrite(dir3 1);
        analogWrite(pwm3, spd);
 Serial.println(x);
           Serial.println(y);
      }*/

}
void stopp()
{
      digitalWrite(dir1, 0);
      analogWrite(pwm1, 0);
      digitalWrite(dir2, 0);
      analogWrite(pwm2, 0);
      digitalWrite(dir3, 0);
      analogWrite(pwm3, 0);
      digitalWrite(rdir1,0);
       analogWrite(rpwm1,0);
      
      Serial.println("STOPPPPPP");
}
