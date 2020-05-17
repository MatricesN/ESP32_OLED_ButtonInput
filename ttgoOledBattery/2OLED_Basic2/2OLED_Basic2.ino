//Written by Matrix Naovaratpong on May 12th, 2020

//Libraries
#include "SSD1306Wire.h"

//Definition
#define i2cAddress    0x3c
#define SDA           5
#define SCL           4

//Variables
int i,j = 0;

//Configurations
SSD1306Wire matdis(i2cAddress, SDA, SCL);

void dp();

void setup() 
{
  Serial.begin(115200);

  matdis.init();
  matdis.flipScreenVertically();
  matdis.setFont(ArialMT_Plain_10);
  
}

void loop() 
{
  if(i==100)
  {
    dp();
    i=0;
    j++;
  }
  i++;
  delay(1);

}

void dp()
{
  matdis.clear();
  matdis.setTextAlignment(TEXT_ALIGN_LEFT);
  matdis.drawString(0, 0, "TEST " + String(j));
  matdis.display();
}
