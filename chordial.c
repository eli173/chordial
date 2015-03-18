

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
  printf("%d\n",grab_succ);
  while(grab_succ == 0) // is 0 right?
    {
      XMaskEvent(display, KeyPressMask | KeyReleaseMask, &event);
      KeySym ks = get_keysym(event);
      if(ks == XK_Escape)
	return 0;
      if(event.type == KeyPress)
	{
	  printf("kp");
	  key_down(ks, pressedkeys);
	}
      else // KeyRelease
	{
	  KeySym *action = NULL;
	  unsigned long mask = get_mask(num_keys, pressedkeys);
	  printf("mask: %lu\n",mask);
	  bool assigned = lookup(mask, action);
	  printf("assn: %d\n", assigned);
	  //if(action!=NULL)
	  //printf("action: %u", *action);
	  if(assigned)
	    { // is grab-ungrab necessary?
	      /* XUngrabKeyboard(display, CurrentTime); */
	      send_key(*action);
	      /* grab_succ = XGrabKeyboard(display, rootwin, False, */
	      /* 				GrabModeAsync, GrabModeAsync, CurrentTime); */
	    }
	}
    }
  return 0;
}
