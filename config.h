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

#ifndef CONFIG_H
#define CONFIG_H

#include <X11/Xlib.h>

typedef struct {
  KeySym action;
  unsigned long chordmask;
} keydef;

extern KeySym keyboard_keys[];

extern keydef key_mapping[];

extern unsigned long num_maps;
extern unsigned long num_keys;


#endif
