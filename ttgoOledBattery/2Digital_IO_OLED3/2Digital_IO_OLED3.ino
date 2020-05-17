//Written by Matrix Naovaratpong on May 12th, 2020

//Libraries
#include "SSD1306Wire.h"

//Definition
//LCD
#define i2cAddress    0x3c
#define SDA           5
#define SCL           4
//GPIO
#define button1       18
#define button2       19

//System Variables
int button1LastState, button2LastState  = 0;
int i,j = 0;

//Object declaration
SSD1306Wire oled(i2cAddress, SDA, SCL);

//Functions declaration
void oledPrint();
int buttonRead();

void setup() 
{
  //Serial Initial
  Serial.begin(115200);

  //GPIO Initial
  pinMode (LED_BUILTIN, OUTPUT);
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);

  //OLED Initial
  oled.init();
  oled.flipScreenVertically();
  oled.setFont(ArialMT_Plain_10);
  oled.setTextAlignment(TEXT_ALIGN_LEFT);
}

void loop() 
{
  
  if(i==100)
  {
    i = 0;
    int a = buttonRead();
    if(a=0)
    {
      oled.clear();
      oled.drawString(0,0,"-");
    }
    else 
    {
      oled.clear();
      oled.drawString(0,0,String(j));
      //oled.display();
    }
  }
  i++;
  delay(1);
  oledPrint();
}

void oledPrint()
{
  
  oled.setTextAlignment(TEXT_ALIGN_LEFT);
  //oled.drawString(0, 0, "TEST " + String(j));
  oled.display();
}

int buttonRead()
{
  int scenario, repeatKey = 0;
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);

  if (button1State != button1LastState || button2State != button2LastState) 
  {
    repeatKey = 0;
    if (button1State)
    {
      j++;
      scenario = 1;
    }
    if (button2State)
    {
      j--;
      scenario = 2;
    }
  }

  else
  {
    if(button1State)
    {
      repeatKey++;
      if (repeatKey = 10)
      { 
        while (button1State)
        {
          j++;
          delay(100);
          button1State = digitalRead(button1);
        } 
      }
      scenario = 3;
    }
    else if(button2State)
    {
      repeatKey++;
      if (repeatKey = 10)
      { 
        while (button2State)
        {
          j--;
          delay(100);
          button2State = digitalRead(button2);
        } 
      }
      scenario = 4;
    }
    else
    {
      scenario = 0;
    }
  }
  button1LastState = button1State;
  button2LastState = button2State;
  return scenario;
}
