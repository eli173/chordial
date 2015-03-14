
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include "config.h"

#include "event_handler.h"


KeySym get_keysym(XEvent event)
{
  XKeyEvent xk_event = event.xkey;
  return XLookupKeysym(xk_event, 1); // magic number....
}

bool key_down(KeySym key, KeySym* )
