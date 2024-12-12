//
// DMHController.h
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

#ifndef DMHController_h
#define DMHController_h

enum
{
  SC_BTN_UP       = 1,
  SC_BTN_DOWN     = 2,
  SC_BTN_LEFT     = 4,
  SC_BTN_RIGHT    = 8,
  DMH_BTN_A       = 32,
  DMH_BTN_B       = 16,
  DMH_BTN_X       = 64,
  DMH_BTN_Y       = 128,
  DMH_BTN_L       = 256,
  DMH_BTN_R       = 2048,
  DMH_BTN_SELECT  = 512,
  DMH_BTN_START   = 1024,
  SC_BIT_SH_UP    = 0,
  SC_BIT_SH_DOWN  = 1,
  SC_BIT_SH_LEFT  = 2,
  SC_BIT_SH_RIGHT = 3
};

const byte SC_CYCLE_DELAY = 10; // Delay (µs) between setting the select pin and reading the button pins

class DMHController {
  public:
    DMHController(void);

    word getStateMD();

  private:
    word _currentState;

    byte _inputReg1;
    byte _inputReg2;
    byte _inputReg3;
};

#endif
