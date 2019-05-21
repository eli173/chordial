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

#ifndef KEYMAP_H
#define KEYMAP_H

#include<X11/Xlib.h>
#include<stdbool.h>
#include"config.h"

/**
 * @brief Finds keysym
 *
 * looks for matching keysym,
 * stores in retsym and returns true if found
 * otherwise returns false and sets retsym to NULL
 *
 */
bool lookup(unsigned long mask, KeySym *retsym);

/**
 * @brief To be passed to qsort to sort map for binary search
 *
 */
//static int sort_fn(keydef a, keydef b);

/**
 * @brief gets the mask from the given keys
 *
 *
 */
unsigned long get_mask(unsigned long numkeys, bool* pressedkeys);

#endif
