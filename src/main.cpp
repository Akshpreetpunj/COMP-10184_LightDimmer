/* I Akshpreet Singh Punj, 000820040 certify that this material is my original work. 
No other person's work has been used without due acknowledgement. 
I have not made my work available to anyone else." 
*/

#include <Arduino.h>

// declaring variables with global scope for checking the state of button and LED

// The initial state of button is off
bool buttonState = false;

// The initial state of LED is off
bool ledState = false;

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 

  // set default PWM range 
  analogWriteRange(1023);
}

void loop() {
  // declaring the variables
  int iVal;
  int iButton; 

  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 

  // read the push button input...
  iButton = digitalRead(D5); 
  // ... and write it to the LED output 
  digitalWrite(D4, iButton); 

  // Checking the button value/state
  // Serial.println(String(iButton)); 

  // Handling the button and LED state.
  if (iButton == 0 && !buttonState) 
  {
    buttonState = true;
    ledState = !ledState; // Changing the LED state. if LED is ON change it to OFF and vice-versa.
  } 
  else if (iButton == 1) {
    buttonState = false;
  }

  // Handling the LED when the button is pushed
  // If the LED is ON. Changing the brightness level by the variable resistor
  if (ledState == true) 
  {
    analogWrite(D4, iVal);
  } else { // If the LED is OFF
    // Turn OFF the LED
    digitalWrite(D4, 1);
  }

  // debounce
  delay(1);
}