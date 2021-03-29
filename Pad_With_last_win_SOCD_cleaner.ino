/*  Hitbox/Mixbox/Stickless Arcade Stick Sketch Copyright (C) 2021 wrentheenby
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 2.1 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <Bounce.h>

// Create Bounce objects for each button.
//                        button number, proper name
Bounce button0 = Bounce(0, 10); // 1, Square
Bounce button1 = Bounce(1, 10); // 2, Cross
Bounce button2 = Bounce(2, 10); // 3, Circle
Bounce button3 = Bounce(3, 10); // 4, Triangle
Bounce button4 = Bounce(4, 10); // 5, L1
Bounce button5 = Bounce(5, 10); // 6, R1
Bounce button6 = Bounce(6, 10); // 7, L2
Bounce button7 = Bounce(7, 10); // 8, R2
Bounce button8 = Bounce(8, 10); // 9, Select/Back
Bounce button9 = Bounce(9, 10); // 10, Start
Bounce button10 = Bounce(10, 10); // 13, Home Button
char lastDir;
void hatrw();
const uint8_t joy[] = {14,13,12,11}; //change these pins to right, left, up, down, in order.

void setup() {
  Serial.begin(9600);
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW.
  pinMode(0, INPUT_PULLUP);  
  pinMode(1, INPUT_PULLUP); 
  pinMode(2, INPUT_PULLUP);  
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP); 
  pinMode(6, INPUT_PULLUP); 
  pinMode(7, INPUT_PULLUP);  
  pinMode(8, INPUT_PULLUP);  
  pinMode(9, INPUT_PULLUP);  
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP); 
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);  
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP); 
}

void loop() {
  hatrw();
  Joystick.send_now();
  delay(1);
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();

  // Check each button for "falling" edge. 
  if (button0.fallingEdge()) {
    Joystick.button(1, 1);
  }
  if (button1.fallingEdge()) {
    Joystick.button(2, 1);
  }
  if (button2.fallingEdge()) {
    Joystick.button(3, 1);
  }
  if (button3.fallingEdge()) {
    Joystick.button(4, 1);
  }
  if (button4.fallingEdge()) {
    Joystick.button(5, 1);
  }
  if (button5.fallingEdge()) {
    Joystick.button(6, 1);
  }
  if (button6.fallingEdge()) {
    Joystick.button(7, 1);
  }
  if (button7.fallingEdge()) {
    Joystick.button(8, 1);
  }
  if (button8.fallingEdge()) {
    Joystick.button(9, 1);
  }
  if (button9.fallingEdge()) {
    Joystick.button(10, 1);
  }
  if (button10.fallingEdge()) {
    Joystick.button(13, 1);
  }

  

  // Check each button for "rising" edge
  if (button0.risingEdge()) {
    Joystick.button(1, 0);
  }
  if (button1.risingEdge()) {
    Joystick.button(2, 0);
  }
  if (button2.risingEdge()) {
    Joystick.button(3, 0);
  }
  if (button3.risingEdge()) {
    Joystick.button(4, 0);
  }
  if (button4.risingEdge()) {
    Joystick.button(5, 0);
  }
  if (button5.risingEdge()) {
    Joystick.button(6, 0);
  }
  if (button6.risingEdge()) {
    Joystick.button(7, 0);
  }
  if (button7.risingEdge()) {
    Joystick.button(8, 0);
  }
  if (button8.risingEdge()) {
    Joystick.button(9, 0);
  }
  if (button9.risingEdge()) {
    Joystick.button(10, 0);
  }
  if (button10.risingEdge()) {
    Joystick.button(13, 0);
  }

}
  void hatrw()
  {
  	
  uint8_t read = 0;
  for (int i=0; i<4; i++) {
      read |= digitalRead(joy[i])  << i;
      //Serial.print(digitalRead(joy[i])  << i);
      Serial.print(lastDir);
    }
    //1,2,4,8
    //right left down up
    //when button is pressed it stops adding to the total
    // i.e. if i press up the total is 1+2+4, 7
  if(digitalRead(15) == 0) {
    
    switch (read)
    {
      case 14: //right
      Joystick.hat(90);
	    lastDir='R';
      break;
      case 13: //left
      Joystick.hat(270);
	    lastDir='L';
      break;
      case 11: //down
      Joystick.hat(180);
      break;
      case 7: //up
      Joystick.hat(0);
      break;
      case 6: //up right
      Joystick.hat(45);
	    lastDir='R';
      break;
      case 10: //down right
      Joystick.hat(135);
	    lastDir='R';
      break;
      case 5: //left up
      Joystick.hat(315);
	    lastDir='L';
      break;
      case 9: //left down
      Joystick.hat(225);
	    lastDir='L';
      break;
	    case 12: //left+right
	    if (lastDir == 'L') Joystick.hat(90); else Joystick.hat(270);
      break;
      case 3: //up+down
      Joystick.hat(0);
      break;
      case 1: //up,down,left
      Joystick.hat(315);
	    lastDir='L';
      break;
      case 2: //up,down,right
      Joystick.hat(45);
	    lastDir='R';
      break;
      case 4: //up,left,right
      Joystick.hat(0);
	    if (lastDir == 'L') Joystick.hat(45); else Joystick.hat(315);
      break;
      case 8: //down,left,right
      Joystick.hat(180);
	    if (lastDir == 'L') Joystick.hat(135); else Joystick.hat(225);
      break;
      case 0: //up,down,left,right
      Joystick.hat(0);
	    if (lastDir == 'L') Joystick.hat(45); else Joystick.hat(315);
      break;
      default:
      Joystick.X(512);
      Joystick.Y(512);
      Joystick.hat(-1);
      break;
    }
  }
  else {
    switch (read)
    {
      case 14: //right
      Joystick.X(1023);
      Joystick.Y(512);
      lastDir='R';
      break;
      case 13: //left
      Joystick.X(0);
      Joystick.Y(512);
      lastDir='L';
      break;
      case 11: //down
      Joystick.X(512);
      Joystick.Y(1023);
      break;
      case 7: //up
      Joystick.X(512);
      Joystick.Y(0);
      break;
      case 6: //up right
      Joystick.X(1023);
      Joystick.Y(0);
      lastDir='R';
      break;
      case 10: //down right
      Joystick.X(1023);
      Joystick.Y(1023);
      lastDir='R';
      break;
      case 5: //left up
      Joystick.X(0);
      Joystick.Y(0);
      lastDir='L';
      break;
      case 9: //left down
      Joystick.X(0);
      Joystick.Y(1023);
      lastDir='L';
      break;
      case 12: //left+right
      if (lastDir == 'L') {
      Joystick.X(0); 
      Joystick.Y(512);
      }
      else {
      Joystick.X(1023);
      Joystick.Y(512);
      }
      break;
      case 3: //up+down
      Joystick.X(512);
      Joystick.Y(0);
      break;
      case 1: //up,down,left
      Joystick.X(0);
      Joystick.Y(0);
      lastDir='L';
      break;
      case 2: //up,down,right
      Joystick.X(1023);
      Joystick.Y(0);
      lastDir='R';
      break;
      case 4: //up,left,right
      if (lastDir == 'L') {
      Joystick.X(0); 
      Joystick.Y(0);
      } 
      else {
      Joystick.X(1023); 
      Joystick.Y(0);
      }
      break;
      case 8: //down,left,right
      if (lastDir == 'L') {
      Joystick.X(0); 
      Joystick.Y(1023);
      }
      else {
      Joystick.X(1023);
      Joystick.Y(1023);
      }
      break;
      case 0: //up,down,left,right
      if (lastDir == 'L') {
      Joystick.X(0);
      Joystick.Y(0);
      }
      else {
      Joystick.X(1023);
      Joystick.Y(0);
      }
      break;
      default:
      Joystick.X(512);
      Joystick.Y(512);
      Joystick.hat(-1);
      break;
    }
  }
}
