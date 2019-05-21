/**
   Copyright (C) 2014-2019 Elijah Cohen
   
   This file is part of Chordial.
   
   Chordial is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   Chordial is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with Chordial.  If not, see <https://www.gnu.org/licenses/>.
*/


#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include <stdbool.h>


#include "sendkey.h"


#define KEYDOWN 1
#define KEYUP 0

int send_key(KeySym keysym, Display* display)
{
  /*
    okay, I think I need some additional X funcalls or something to do this.. look at xdotool for inspiration
   */
  if(display==NULL)
    {
      return -1;
    }
  XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), KEYDOWN, CurrentTime);
  XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), KEYUP, CurrentTime);
  XFlush(display);
  return 0;
}

int send_key_up(KeySym keysym, Display* display)
{
  if(display==NULL)
    return -1;
  XTestFakeKeyEvent(display, XKeysymToKeycode(display,keysym),
		    KEYUP, CurrentTime);
  XFlush(display);
  return 0;
}

int send_key_down(KeySym keysym, Display* display)
{
  if(display==NULL)
    return -1;
  XTestFakeKeyEvent(display, XKeysymToKeycode(display,keysym),
		    KEYDOWN, CurrentTime);
  XFlush(display);
  return 0;
}
