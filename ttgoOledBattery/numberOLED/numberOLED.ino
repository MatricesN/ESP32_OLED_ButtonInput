
// Written by Matrix Naovaratpong May 10th, 2020

#include "SSD1306.h"

#define led 16 // on-board LED
#define i2cAddress 0x3c
#define SDA 5
#define SCL 4

int i = 0;

SSD1306 display (i2cAddress, SDA, SCL);


void setup() 
{
  pinMode (led, OUTPUT);

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  
}

void loop() 
{
  i++;
  display.clear();
  display.drawString(0, 0, "fan" + String(i));
  display.display();
  delay(1000);
}
