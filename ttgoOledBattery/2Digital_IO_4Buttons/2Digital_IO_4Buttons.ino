//Written by Matrix Naovaratpong on May 13th, 2020

//Libraries

//Definitions
#define button1       18
#define button2       19
#define button3       22
#define button4       23
#define led           LED_BUILTIN       //GPIO16 on TTGO Battery OLED 

//Variables
int i               = 0;
int button1State    = 0;
int button2State    = 0;
int button3State    = 0;
int button4State    = 0;

void setup() 
{
  Serial.begin(115200);
  
  pinMode (led, OUTPUT);
  pinMode (button1, INPUT);
  pinMode (button2, INPUT);
  pinMode (button3, INPUT);
  pinMode (button4, INPUT);
  
}

void loop() 
{
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);
  button4State = digitalRead(button4);

  if(button1State)
  {
    digitalWrite(led, LOW);
    Serial.println("18");
  }
  if(button2State)
  {
    digitalWrite(led, HIGH);
    Serial.println("19");
  }
  if(button3State)
  {
    digitalWrite(led, LOW);
    Serial.println("22");
  }
  if(button4State)
  {
    digitalWrite(led, HIGH);
    Serial.println("23");
  }

  delay(100);
}
