/**
   Copyright (C) 2014-2019 Elijah Cohen
   
   This file is part of Chordial.
   
   Chordial is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   Chordial is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with Chordial.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "keymap.h"
#include <X11/Xlib.h>
#include "config.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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
