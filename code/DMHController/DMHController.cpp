//
// DMHController.cpp
//
// Authors:
//       Jon Thysell <thysell@gmail.com>
//       Mikael Norrgård <mick@daemonbite.com>
//       Ken St. Cyr <ken@whatskenmaking.com>
//
// Copyright (c) 2017 Jon Thysell <http://jonthysell.com>
// Copyright (c) 2024 What's Ken Making <https://whatskenmaking.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "Arduino.h"
#include "DMHController.h"

DMHController::DMHController(void)
{
    // Setup input pins (A0,A1,A2,A3,14,15 or PF7,PF6,PF5,PF4,PB3,PB1)
    DDRF  &= ~B11110000; // input
    PORTF |=  B11110000; // high to enable internal pull-up

    DDRB  &= ~B11111110; // input
    PORTB |=  B11111110; // high to enable internal pull-up

    DDRD  &= ~B11110000;
    PORTD |= B11110000;
    
    _inputReg1 = 0;
    _inputReg2 = 0;
    _inputReg3 = 0;
    _currentState = 0;
}

word DMHController::getStateMD()
{
  
  // Short delay to stabilise outputs in controller
  delayMicroseconds(SC_CYCLE_DELAY);

  // Read input register(s)
  _inputReg1 = PINF;
  _inputReg2 = PINB;
  _inputReg3 = PIND;

  // Clear current state
  _currentState = 0;
  
  // Read input pins for Up, Down, Left, Right
  if (bitRead(_inputReg1, 7) == LOW) { _currentState |= SC_BTN_UP; }      // A0 - Up Button (Blue)
  if (bitRead(_inputReg1, 6) == LOW) { _currentState |= SC_BTN_DOWN; }    // A1 - Down Button (Yellow)
  if (bitRead(_inputReg1, 5) == LOW) { _currentState |= SC_BTN_LEFT; }    // A2 - Left Button (Green)
  if (bitRead(_inputReg1, 4) == LOW) { _currentState |= SC_BTN_RIGHT; }   // A3 - Right Button (White)

  // Read input pins for remaining buttons
  if (bitRead(_inputReg2, 1) == LOW) { _currentState |= DMH_BTN_A; }      // D15 - A Button (Red)
  if (bitRead(_inputReg2, 3) == LOW) { _currentState |= DMH_BTN_B; }      // D14 - B Button (Yellow)
  if (bitRead(_inputReg2, 2) == LOW) { _currentState |= DMH_BTN_X; }      // D16 - X Button (Blue)
  if (bitRead(_inputReg2, 4) == LOW) { _currentState |= DMH_BTN_Y; }      // D8 - Y Button (Green)
  if (bitRead(_inputReg2, 5) == LOW) { _currentState |= DMH_BTN_L; }      // D9 - L Shoulder Button (Red)
  if (bitRead(_inputReg2, 6) == LOW) { _currentState |= DMH_BTN_R; }      // D10 - R Shoulder Button (White)
  if (bitRead(_inputReg3, 7) == LOW) { _currentState |= DMH_BTN_SELECT; } // D4 - Select Button (Green)
  if (bitRead(_inputReg3, 4) == LOW) { _currentState |= DMH_BTN_START; }  // D6 - Start Button (Blue)

  return _currentState;
}
