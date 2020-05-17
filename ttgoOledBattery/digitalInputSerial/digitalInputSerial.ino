const int button1 = 17;
const int ledPin =  LED_BUILTIN;
int b1State = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(button1, INPUT);
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
    //delay(1000);
  } 
  else digitalWrite(ledPin, LOW);
  /*if (b1State == LOW) 
  {
    digitalWrite(ledPin, LOW);
    delay(1000);
  } 
  else;*/
}
