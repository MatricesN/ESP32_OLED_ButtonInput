// Written by Matrix Naovaratpong May 11th, 2020
/***************************** libraries *****************************/
#include "SSD1306.h"

/****************************** define *******************************/
#define i2cAddress          0x3c
#define SDA                 5
#define SCL                 4

#define ledPin              16                      // on-board LED
#define button1             18
#define button2             19

/***************************** variables ****************************/
int b1State   = 0;
int b1pState  = b1State;

int b2State   = 0;
int b2pState  = b2State;

int i         = 0;

/******************************* config *****************************/
SSD1306 display (i2cAddress, SDA, SCL);

void setup() 
{
  Serial.begin(115200);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(ledPin, OUTPUT);

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}

void loop() 
{
  b1State = digitalRead(button1);
  b2State = digitalRead(button2);
  Serial.println(b1State);

  if (b1State != b1pState || b2State != b2pState) 
  {
    if (b1State)i++;digitalWrite(ledPin, HIGH);
    if (b2State)i--;digitalWrite(ledPin, LOW);
  } 
  
  display.clear();
  display.drawString(0, 0, "fan" + String(i));
  display.display();
  delay(100);
  b1pState = b1State;
  b2pState = b2State;
}
