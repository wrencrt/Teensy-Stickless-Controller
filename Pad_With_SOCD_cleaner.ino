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
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);
Bounce button6 = Bounce(6, 10);
Bounce button7 = Bounce(7, 10);
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);
Bounce button10 = Bounce(10, 10);
Bounce buttonup= Bounce(11, 10);  
Bounce buttondown = Bounce(12, 10);  
Bounce buttonleft = Bounce(13, 10);  
Bounce buttonright = Bounce(14, 10);
int up,down,left,right,stick;

void setup() {
  Joystick.hat(-1);
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW.
  pinMode(0, INPUT_PULLUP);  // 1, Square
  pinMode(1, INPUT_PULLUP);  // 2, Cross
  pinMode(2, INPUT_PULLUP);  // 3, Circle
  pinMode(3, INPUT_PULLUP);  // 4, Triangle
  pinMode(4, INPUT_PULLUP);  // 5, L1
  pinMode(5, INPUT_PULLUP);  // 6, R1
  pinMode(6, INPUT_PULLUP);  // 7, L2
  pinMode(7, INPUT_PULLUP);  // 8, R2
  pinMode(8, INPUT_PULLUP);  // 9, Select/Back
  pinMode(9, INPUT_PULLUP);  // 10, Start
  pinMode(10, INPUT_PULLUP); // 13, Home Button
  pinMode(11, INPUT_PULLUP); // Up
  pinMode(12, INPUT_PULLUP); // Down
  pinMode(13, INPUT_PULLUP); // Left 
  pinMode(14, INPUT_PULLUP); // Right
  pinMode(15, INPUT_PULLUP); // Dpad/left stick switch
}

void loop() {

  int dpadSwitch = digitalRead(15);
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
  buttonup.update();  
  buttondown.update();   
  buttonleft.update();
  buttonright.update();

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
  if (buttonup.fallingEdge()) {
    int up = 1;
  }
  if (buttondown.fallingEdge()) {
    int down = 1;
  }
  if (buttonleft.fallingEdge()) {
    int left = 1;
  }
  if (buttonright.fallingEdge()) {
    int right = 1;
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
  if (buttonup.risingEdge()) {
    int up = 0;
  }
  if (buttondown.risingEdge()) {
    int down = 0;
  }
  if (buttonleft.risingEdge()) {
    int left = 0;
  }
  if (buttonright.risingEdge()) {
    int right = 0;
  }
  
  // Dpad/left stick shit
  // god this was annoying and there's 100% a better way to do it
  // but tbh, i don't care enough to do it that better way. 
  // variable stick uses numpad notation
  //    ╔════╗
  //    ║7  8  9║
  //    ║4  5  6║
  //    ║1  2  3║
  //    ╚════╝

                                                    // UDLR
  if (down+left == 2 && up+right == 0) {stick = 1;} // 0110
  if (down == 1 && up+left+right == 0) {stick = 2;} // 0100
  if (down+right == 2 && up+left == 0) {stick = 3;} // 0101
  if (left == 1 && up+down+right == 0) {stick = 4;} // 0010
  if (up+down+right+left == 0) {stick = 5;}         // 0000
  if (right == 1 && up+right+left == 0) {stick = 6;}// 0001
  if (up+left == 2 && down+right == 0) {stick = 7;} // 1010
  if (up == 1 && down+right+left == 0) {stick = 8;} // 1000
  if (up+right == 2 && down+left == 0) {stick = 9;} // 1001
  // SOCD cleaner stuff. sorted.
  if (up+down == 2 && left+right == 0) {stick = 8;} // 1100 
  if (up+down+left == 3 && right == 0) {stick = 7;} // 1110
  if (up+down+right == 3 && left == 0) {stick = 9;} // 1101
  if (left+right == 2 && up+down == 0) {stick = 5;} // 0011
  if (up+left+right == 3 && down == 0) {stick = 8;} // 1011
  if (down+left+right == 3 && up == 0) {stick = 2;} // 0111
  if (up+down+left+right == 4 ) {stick = 8;}        // 1111
  
  // now time for the actual _output_ shit :)
  if(dpadSwitch == LOW) { // if switch is ON use DPad...
    switch (stick) {
      case 1:
        Joystick.hat(225);
      break;
      case 2:
        Joystick.hat(180);
      break;
      case 3:
        Joystick.hat(135);
      break;
      case 4:
        Joystick.hat(270);
      break;
      case 5:
        Joystick.hat(-1);
      break;
      case 6:
        Joystick.hat(90);
      break;
      case 7:
        Joystick.hat(315);
      break;
      case 8:
        Joystick.hat(0);
      break;
      case 9:
        Joystick.hat(45);
      break;
      default:
        Joystick.hat(-1);
      break;
    }
  }
  else { // ... otherwise use the right stick.
    switch (stick) {   
      case 1:
        Joystick.X(0);
        Joystick.Y(0);
      break;
      case 2:
        Joystick.X(512);
        Joystick.Y(0);
      break;
      case 3:
        Joystick.X(1023);
        Joystick.Y(0);
      break;
      case 4:
        Joystick.X(0);
        Joystick.Y(512);
      break;
      case 5:
        Joystick.X(512);
        Joystick.Y(512);
      break;
      case 6:
        Joystick.X(1023);
        Joystick.Y(512);
      break;
      case 7:
        Joystick.X(0);
        Joystick.Y(1023);
      break;
      case 8:
        Joystick.X(512);
        Joystick.Y(1023);
      break;
      case 9:
        Joystick.X(1023);
        Joystick.Y(1023);
      break;
      default:
        Joystick.X(512);
        Joystick.Y(512);
      break;
      
    } 
  }
}
