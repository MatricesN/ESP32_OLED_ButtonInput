const int button1 = 16;
//const int button2 = 17;
const int ledPin =  LED_BUILTIN;
int b1State = 0;
//int b2State = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(button1, INPUT);
  //pinMode(button2, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  b1State = digitalRead(button1);
  //b2State = digitalRead(button2);
  Serial.println(b1State);
  
  if (b1State == HIGH) 
  {
    digitalWrite(ledPin, HIGH);
  } 
  //else;
  else //(b1State == LOW) 
  {
    digitalWrite(ledPin, LOW);
  } 
  //else;
}
