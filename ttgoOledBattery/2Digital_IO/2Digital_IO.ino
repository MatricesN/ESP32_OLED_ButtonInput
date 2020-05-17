//Written by Matrix Naovaratpong on May 13th, 2020

//Libraries

//Definitions
#define bt1       18
#define bt2       19
#define led       LED_BUILTIN       //GPIO16 on TTGO Battery OLED 

//Variables
int i         = 0;
int bt1State   = 0;
int bt1pState  = bt1State;
int bt2State   = 0;
int bt2pState  = bt2State;

void setup() 
{
  pinMode (led, OUTPUT);
  pinMode (bt1, OUTPUT);
  pinMode (bt2, OUTPUT);
  
}

void loop() 
{
  bt1State = digitalRead(bt1);
  bt2State = digitalRead(bt2);

  if(bt1State)digitalWrite(led, LOW);
  if(bt2State)digitalWrite(led, HIGH);

  delay(100);
}
