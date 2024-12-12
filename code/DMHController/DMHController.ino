/*  DMH-01 Controller for Mister Portable
 *  Original Author: Mikael Norrgård <mick@daemonbite.com>
 *  Modified by: Ken St. Cyr <ken@whatskenmaking.com>
 *
 *  Copyright (c) 2020 Mikael Norrgård <http://daemonbite.com>
 *  Modifications Copyright (c) 2024 What's Ken Making <https://whatskenmaking.com>
 *  
 *  GNU GENERAL PUBLIC LICENSE
 *  Version 3, 29 June 2007
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "DMHController.h"
#include "Gamepad.h"

const char *gp_serial = "Mister Portable";

DMHController controller;

// Set up USB HID gamepad
Gamepad_ Gamepad;

// Controller states
word currentState = 0;
word lastState = 1;

void setup()
{ 
}

void loop() { while(1)
{
  currentState = controller.getStateMD();
  sendState();
}}

void sendState()
{
  // Only report controller state if it has changed
  if (currentState != lastState)
  {
    Gamepad._GamepadReport.buttons = currentState;
    Gamepad._GamepadReport.Y = ((currentState & SC_BTN_DOWN) >> SC_BIT_SH_DOWN) - ((currentState & SC_BTN_UP) >> SC_BIT_SH_UP);
    Gamepad._GamepadReport.X = ((currentState & SC_BTN_RIGHT) >> SC_BIT_SH_RIGHT) - ((currentState & SC_BTN_LEFT) >> SC_BIT_SH_LEFT);
    Gamepad.send();
    lastState = currentState;
  }
}
