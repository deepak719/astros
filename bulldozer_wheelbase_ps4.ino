#include <PS4USB.h>
#include <usbhub.h>
#include<math.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside
//BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at  the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4USB PS4(&Usb);

#define rdir1  30
#define rpwm1 11
#define pisa 47
#define pisb 49
#define dir1 26
#define pwm1 7
#define dir2 24
#define pwm2 6
#define dir3 5
#define pwm3 4
//#define spd 100
#define fullspd 255
int x=0;
int y=0; 
int spd=100;
void setup() {
  pinMode(pisa,OUTPUT);
  pinMode(pisb,OUTPUT);
  pinMode(rdir1,OUTPUT);
  pinMode(rpwm1,OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(pwm3, OUTPUT);
  Serial.begin(9600);
  
  if (Usb.Init() == -1) {
    Serial.println("Error");
  }
}

void loop() {


  Usb.Task();
  
  if (PS4.connected())
  {
    if(PS4.getButtonPress(L1)||PS4.getButtonPress(R1))
    {
          if(PS4.getButtonPress(R1))
             anticlock();
           else
          {  
            //clockwise
            clockwise();
          }
    }
    else  if(PS4.getButtonPress(SQUARE)||PS4.getButtonPress(CIRCLE))
    {
         if(PS4.getButtonPress(CIRCLE))
        {
          piston_close();
        }
        else 
        {
          piston_open();
        }
    }
    else
    {
      
if(PS4.getButtonClick(TRIANGLE))
{
  spd=spd+10;
  spd = constrain(spd,0,255);
}
else if(PS4.getButtonClick(CROSS))
{
  spd=spd-10;
  spd=constrain(spd,0,255);
}     
 else   if (PS4.getButtonPress(LEFT))
    {
      //left
      left();

    }
    
   
else if (PS4.getAnalogHat(LeftHatX) > 137 || PS4.getAnalogHat(LeftHatX) < 117 || PS4.getAnalogHat(LeftHatY) > 137 || PS4.getAnalogHat(LeftHatY) < 117 || PS4.getAnalogHat(RightHatX) > 137 || PS4.getAnalogHat(RightHatX) < 117 || PS4.getAnalogHat(RightHatY) > 137 || PS4.getAnalogHat(RightHatY) < 117) {
   joystick();
    }
    else if (PS4.getButtonPress(RIGHT))
    {
      //right
      right();
    }

    else if (PS4.getButtonPress(UP))
    {
      //forward
      forward();
      
    }
    else if (PS4.getButtonPress(DOWN))
    {
      //reverse
      reverse();
      
    }
  
    else if(PS4.getButtonPress(L2))
    {
       direction1();
    }
    else if(PS4.getButtonPress(R2))
    {
       direction2();
    }
   
    else
    {
      stopp();
    }
   }
  }


}
