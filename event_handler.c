
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include "config.h"

#include "event_handler.h"


KeySym get_keysym(XEvent event)
{
  XKeyEvent xk_event = event.xkey;
  return XLookupKeysym(&xk_event, 1); // magic number....
}

void key_down(KeySym key, bool* pressedkeys)
{
  unsigned char c;
  for(c=0;c<num_keys;c++)
    {
      if(keyboard_keys[c]==key)
	{
	  pressedkeys[c]=true;
	}
    }
  
  return;
}



bool key_up(KeySym key, bool* pressedkeys)
{
  unsigned char c;
  for(c=0;c<num_keys;c++)
    {
      if(keyboard_keys[c]==key)
	{
	  pressedkeys[c]=false;
	}

    }  
  
  return true;  
}
