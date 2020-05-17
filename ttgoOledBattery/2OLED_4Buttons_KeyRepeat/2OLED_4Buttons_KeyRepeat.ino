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
#define button3       22
#define button4       23

//System Variables
int button1LastState,button2LastState,button3LastState,button4LastState  = 0;
int counter,fanSpeed,button1Hold,button2Hold,button3Hold,button4Hold, = 0;

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
  pinMode (button3, INPUT);
  pinMode (button4, INPUT);

  //OLED Initial
  oled.init();
  oled.flipScreenVertically();
  oled.setFont(ArialMT_Plain_10);
  oled.setTextAlignment(TEXT_ALIGN_LEFT);
}

void loop() 
{
  if (counter == 100)
  {
    counter = 0;
    int a = buttonRead();
    oled.clear();
    
    if (a == 1){ fanSpeed++; oled.drawString(0,0,String(fanSpeed)); }
    else if (a == 2){ fanSpeed--; oled.drawString(0,0,String(fanSpeed)); }
    else oled.drawString(0,0,"-");
    
    oledPrint();
  }
  counter++;
  delay(1);
}

void oledPrint()
{
  oled.setTextAlignment(TEXT_ALIGN_LEFT);
  oled.display();
}

int buttonRead()
{
  int buttonPressed = 0;
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);
  int button3State = digitalRead(button3);
  int button4State = digitalRead(button4);

  button1Hold++;
  button2Hold++;

  if (button1State && !button1LastState) buttonPressed = 1;
  if (button2State && !button2LastState) buttonPressed = 2;

  if (!button1State) button1Hold = 0;
  if (!button2State) button2Hold = 0;

  if (button1Hold >= 10) { buttonPressed = 1; button1Hold = 10; }
  if (button2Hold >= 10) { buttonPressed = 2; button2Hold = 10; }
  
  button1LastState = button1State;
  button2LastState = button2State;
  button3LastState = button3State;
  button4LastState = button4State;
  return buttonPressed;
}
