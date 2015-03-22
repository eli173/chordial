
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
	  //printf("\tc:%d\t",c);
	  pressedkeys[c]=false;
	}

    }  
  
  return true;  
}


bool action_in_pressedkeys(KeySym action, bool* pressedkeys)
{
  unsigned long mask = get_mask(num_keys, pressedkeys);
  unsigned char c;
  for(c=0;c<num_keys;c++)
    {
      if(true&&(action==keyboard_keys[c]))
	return true;
    }
  return false;
}
