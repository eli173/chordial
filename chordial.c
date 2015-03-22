

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
  unsigned int i;
  for(i=0;i<num_keys;i++)
    {
      pressedkeys[i] = false;
    }
  while(grab_succ == 0) // is 0 right?
    {
      XMaskEvent(display, KeyPressMask | KeyReleaseMask, &event);
      //printf("type: %d\n",event.type);
      KeySym ks = get_keysym(event);
      if(ks == XK_Escape)
	return 0;
      if(event.type == KeyPress)
	{
	  key_down(ks, pressedkeys);
	  printf("kdn: ");
	  for(i=0;i<num_keys;i++)
	    printf("%d", pressedkeys[i]);
	  printf("\n");
	}
      else // KeyRelease
	{
	  KeySym action;
	  unsigned long mask = get_mask(num_keys, pressedkeys);
	  bool assigned = lookup(mask, &action);
	  key_up(ks, pressedkeys);
	  printf("kup: ");
	  for(i=0;i<num_keys;i++)
	    printf("%d", pressedkeys[i]);
	  printf("\n");
	  //printf("mask: %lu\t",mask);
	  //printf("action: %u\t", action);
	  /* 
	   * Okayyy.. check that the key sent isn't 
	   * in the new mask and then sim a keyup before
	   * and another keydn after?
	   */
	  bool aipk = action_in_pressedkeys(action, pressedkeys);
	  printf("aipk: %d\n",aipk!=false);
	  if(aipk)
	    {
	      XUngrabKeyboard(display, CurrentTime);
	      send_key_up(action, display);
	      grab_succ = XGrabKeyboard(display, rootwin,
					false, GrabModeAsync,
					GrabModeAsync, CurrentTime);
	    }
	  if(assigned && true)
	    {
	      XUngrabKeyboard(display, CurrentTime);
	      //send_key(action,display);
	      grab_succ = XGrabKeyboard(display, rootwin,
					false, GrabModeAsync,
					GrabModeAsync, CurrentTime);
	    }
	  if(aipk)
	    {
	      XUngrabKeyboard(display, CurrentTime);
	      send_key_down(action, display);
	      grab_succ = XGrabKeyboard(display, rootwin,
					false, GrabModeAsync,
					GrabModeAsync, CurrentTime);
	    }
	  mask = 0;
	  //printf("newmask: %lu\n",get_mask(num_keys, pressedkeys));
	}
    }
  XAutoRepeatOn(display);
  XCloseDisplay(display);
  return 0;
}
