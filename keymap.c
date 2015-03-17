
#include "keymap.h"
#include <X11/Xlib.h>
#include "config.h"
#include <stdbool.h>
#include <stdlib.h>

// note to self: use masks from the beginning..
// how do I make config easy though?


// later.. just use linear search for now
void initialize(keydef* keymapping)
{
  //qsort(keymapping, sizeof(keymapping)/sizeof(keydef), sizeof(keydef), sort_fn);
  return;
}


bool lookup(unsigned long mask, KeySym* retsym)
{
  unsigned long numdefs = num_maps;
  unsigned long i;
  for(i=0;i<numdefs;i++)
    {
      if(key_mapping[i].chordmask == mask)
	{ // do I need a malloc?
	  *retsym = key_mapping[i].action;
	  return true;
	}
    }
  return false;
}

unsigned long get_mask(unsigned long numkeys, bool* pressedkeys)
{
  unsigned long mask = 0;
  unsigned long i;
  for(i=0;i<numkeys;i++)
    {
      if(pressedkeys[i])
	{
	  mask |= (1)<<i;
	}
    }
  return mask;
}


/*
static int sort_fn(keydef a, keydef b)
{
  if(a.chordmask<b.chordmask)
    return -1;
  else if(a.chordmask>b.chordmask)
    return 1;
  else
    return 0;
}
*/
