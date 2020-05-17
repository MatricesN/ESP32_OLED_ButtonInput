/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
#include "SSD1306.h"

boolean inp = false;
boolean prevInp = inp;
int i = 0;

SSD1306 display(0x3c, 5, 4); // instance for the OLED. Addr, SDA, SCL

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  
  display.init(); // initialise the OLED
  display.flipScreenVertically(); // does what is says
  display.setFont(ArialMT_Plain_24); // does what is says
  // Set the origin of text to top left
  display.setTextAlignment(TEXT_ALIGN_LEFT);

}

// the loop routine runs over and over again forever:
void loop() 
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  if(sensorValue>=1000) inp = true;
  else inp = false;
  if (inp!=prevInp)
  {
    digitalWrite(LED_BUILTIN, LOW);               // GET /H turns the LED on
    display.clear(); // clear the display
    // prep a string in the screen buffer
    display.drawString(0, 0, "LED ON");
    display.display(); // display whatever is in the buffer

    digitalWrite(LED_BUILTIN, HIGH);                // GET /L turns the LED off
    display.clear(); // clear the display
    // prep a string in the screen buffer
    display.drawString(0, 0, "LED OFF");
    display.display(); // display whatever is in the buffer
  }
  
  Serial.println(sensorValue);
  
  delay(1);        // delay in between reads for stability
  prevInp = inp;
}
