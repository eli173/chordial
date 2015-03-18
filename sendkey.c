

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

int send_key(KeySym keysym)
{
  /*
    okay, I think I need some additional X funcalls or something to do this.. look at xdotool for inspiration
   */
  Display *display = XOpenDisplay(0);
  if(display==NULL)
    {
      return -1;
    }
  XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), KEYDOWN, CurrentTime);
  XTestFakeKeyEvent(display, XKeysymToKeycode(display, keysym), KEYUP, CurrentTime);
  XFlush(display);
  XCloseDisplay(display);
  return 0;
}
