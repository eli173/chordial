

#include <X11/Xlib.h>
#include <X11/keysym.h>

#include "event_handler.h"




int main(int argc, char **argv)
{
  Display *display = XOpenDisplay(0);
  Window rootwin = XRootWindow(display, XDefaultScreen(display));
  int grab_succ = XGrabKeyboard(display, rootwin, False, GrabModeAsync, GrabModeAsync, CurrentTime);
  Xevent event;
  while(grab_succ == 0) // is 0 right?
    {
      XMaskEvent(display, KeyPressMask | KeyReleaseMask, &event);
      KeySym ks = get_keysym(event);
    }
  
  
}
