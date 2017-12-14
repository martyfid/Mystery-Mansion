///*
//
//  The circuit:
//   LED attached from pin 13 to ground
//   pushbutton attached to pin 2 from +5V
//   resistor attached to pin 2 from ground
//
//   Note: on most Arduinos there is already an LED on the board
//   attached to pin 13. This can cause flickering on some pins so
//
//  Created By: Marten Fidler
//  Date: December 12, 2017
//
//
//
//  http://www.arduino.cc/en/Tutorial/Button
//*/

// constants won't change. They're used here to
// set pin numbers:
const int key1 = 2;     // the number of the pushbutton 2 pin
const int key2 = 3;     // the number of the pushbutton 3 pin
const int key3 = 4;     // the number of the pushbutton 4 pin
const int key4 = 5;     // the number of the pushbutton 5 pin
const int ledPin =  8;      // the number of the LED pin

const int keyNum = 4;
const int keyPins[] = {2,3,4,5};
const int keySequence[] = {key1, key2, key3, key4};



// variables will change:
int buttonState;         // variable for reading the pushbutton status
int currentState;        // recording current state of operation
int posSequence;         // which entry of keySequence is being looked at
int input;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(key1, INPUT);
  pinMode(key2, INPUT);
  pinMode(key3, INPUT);
  pinMode(key4, INPUT);

  currentState = 0;
  posSequence = 0;
}

void loop() {
  //read the state of the pushbutton value:
  buttonState = digitalRead(key1);
  //loop to latch the light on when input signal is stopped (keyup/falling edge detection) detected as pressed down
  if (buttonState == HIGH)
  {
    //loop until button state changes to low
    do {
      delay(100);
      buttonState = digitalRead(key1);
    } while (buttonState == HIGH);

    digitalWrite(ledPin, HIGH);
  }


}



