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
int b2State   = 0;
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
  
  if (b1State == HIGH) 
  {
    i++;
    digitalWrite(ledPin, HIGH);
  } 
  else if(b2State == HIGH) 
  {
    i--;
    digitalWrite(ledPin, LOW);
  } 
  /*else //(b1State == LOW) 
  {
    i--;
    digitalWrite(ledPin, LOW);
  } */
  //else;

  display.clear();
  display.drawString(0, 0, "fan" + String(i));
  display.display();
  delay(100);
}
