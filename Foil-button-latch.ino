///*
//
//  The circuit:
//   LED attached from pin 13 to ground
//   pushbutton attached to pin 2 from +5V
//   10K resistor attached to pin 2 from ground
//
//   Note: on most Arduinos there is already an LED on the board
//   attached to pin 13.
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
const int ledPins[] = {8,9,10,11};

const int seqNum = 4;
const int keySequence[] = {key1, key2, key3, key4};

const int keyNum = 4;
const int keyPins[] = {2, 3, 4, 5};



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

  switch (currentState) {
    case 0:

      //gets input that is detected 
      input = getInput();

      //checks if input matches sequence
      if (keySequence[posSequence] == input) {

        //checks state 
        buttonState = digitalRead(input);
        
        if (buttonState == HIGH)
        {
          //loop until button state changes to low
          do {
            delay(100);
            buttonState = digitalRead(input);
          } while (buttonState == HIGH);

          digitalWrite(ledPin, HIGH);
          //currentState = 1;
          posSequence++;
          if (posSequence == seqNum)
            currentState = 2;
        }
      } else {
        currentState = 0;
        posSequence = 0;
      }
      break;

    case 1: // waitInput
      do {
        input = getInput();
        //wait until next input received.
        //maybe have related timeout
      } while (input == 0);
      currentState = 0;
      break;

    case 2: //output
      digitalWrite(ledPin, HIGH);
      break;
      
    default:
      break;
  }
}

int getInput()
{
  int in;
  for (int i = 0; i < keyNum; i++) {
    int in = digitalRead(keyPins[i]);
    if (in == HIGH)
      return keyPins[i];
  }

  /*
    in = digitalRead(key1);
    if (in == HIGH)
    return key1;

    in = digitalRead(key2);
    if (in == HIGH)
    return key2;

    in = digitalRead(key3);
    if (in == HIGH)
    return key3;

    in = digitalRead(key4);
    if (in == HIGH)
    return key4;
  */

  
  return 0;
}


