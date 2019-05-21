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


#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>

#include "sendkey.h"
#include "event_handler.h"
#include "keymap.h"
#include "config.h"



int main(int argc, char **argv)
{
  Display *display = XOpenDisplay(0);
  XAutoRepeatOff(display);
  Window rootwin = XRootWindow(display, XDefaultScreen(display));
  int grab_succ = XGrabKeyboard(display, rootwin,
				false, GrabModeAsync,
				GrabModeAsync, CurrentTime);
  XEvent event;
  bool *pressedkeys = malloc(sizeof(bool)*num_keys);
  bool in_keyup = false;
  unsigned int i;
  for(i=0;i<num_keys;i++)
    {
      pressedkeys[i] = false;
    }
  while(grab_succ == 0) // is 0 right?
    {
      XMaskEvent(display, KeyPressMask | KeyReleaseMask, &event);
      KeySym ks = get_keysym(event);
      if(ks == XK_Escape)
	{
	  XAutoRepeatOn(display);
	  XCloseDisplay(display);
	  return 0;
	}
      if(event.type == KeyPress)
	{
	  key_down(ks, pressedkeys);
	  in_keyup = false;
	}
      else // KeyRelease
	{
	  KeySym action;
	  unsigned long mask = get_mask(num_keys, pressedkeys);
	  bool assigned = lookup(mask, &action);
	  key_up(ks, pressedkeys);
	  /* 
	   * Okayyy.. check that the key sent isn't 
	   * in the new mask and then sim a keyup before
	   * and another keydn after?
	   */
	  bool aipk = action_in_pressedkeys(action, pressedkeys);
	  if(assigned && !in_keyup)
	    {
	      in_keyup = true;
	      XUngrabKeyboard(display, CurrentTime);
	      send_key(action,display);
	      grab_succ = XGrabKeyboard(display, rootwin,
					false, GrabModeAsync,
					GrabModeAsync, CurrentTime);
	    }
	  mask = 0;
	}
    }
  XAutoRepeatOn(display);
  XCloseDisplay(display);
  return 0;
}
