

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
  Window rootwin = XRootWindow(display, XDefaultScreen(display));
  int grab_succ = XGrabKeyboard(display, rootwin, False, GrabModeAsync, GrabModeAsync, CurrentTime);
  XEvent event;
  bool *pressedkeys = malloc(sizeof(bool)*num_keys);
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
	return 0;
      if(event.type == KeyPress)
	{
	  key_down(ks, pressedkeys);
	}
      else // KeyRelease
	{
	  KeySym action;
	  unsigned long mask = get_mask(num_keys, pressedkeys);
	  bool assigned = lookup(mask, &action);
	  if(assigned)
	    {
	      send_key(action);
	    }
	}
    }
  XCloseDisplay(display);
  return 0;
}
