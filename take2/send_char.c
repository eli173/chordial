


#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <X11/Xproto.h>
#include <X11/extensions/XTest.h>

//#include "keybindings.h"


int send_char(Display *theDisplay, char c)
{
  KeyCode kc = XKeysymToKeycode(theDisplay,
				XStringToKeysym(&c));
  XTestFakeKeyEvent(theDisplay, kc, True, CurrentTime);
  XFlush(theDisplay);
  XTestFakeKeyEvent(theDisplay, kc, False, CurrentTime);
  XFlush(theDisplay);
  return 0;
}
