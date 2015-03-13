



#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>

#include "sendkey.h"



int main(int argc, char **argv)
{
  Display *display = XOpenDisplay(0);

  // test for send_key
  int event_base=0, error_base=0, major_version=0, minor_version=0;
  printf("uhhh\n");
  Bool enabled = XTestQueryExtension(display, &event_base, &error_base, &major_version, &minor_version);
  printf("event base: %d, error base: %d, major version: %d, minor version: %d, enabled?: %d\n",
	 event_base, error_base, major_version, minor_version, enabled);
  int i;
  for(i=0;i<10;i++)
    {
      send_key(XK_T);
      send_key(XK_e);
      send_key(XK_s);
      send_key(XK_t);
    }

  // tests kb grab
  Window rootwin = XRootWindow(display, XDefaultScreen(display));
  sleep(3);
  int xgksucc = XGrabKeyboard(display, rootwin, False, GrabModeAsync, GrabModeAsync, CurrentTime);
  printf("\n\nok\n\n");
  sleep(4);
  XUngrabKeyboard(display, CurrentTime);
  printf("%d\n",xgksucc);
  

  return 0;
}
