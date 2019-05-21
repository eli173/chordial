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

#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <stdbool.h>

/**
 * @brief Extracts KeySym from an event
 *
 * Requires the event to be a key event
 *
 */
KeySym get_keysym(XEvent event);

/**
 * @brief Handles keypresses
 *
 * takes a keysym and sets its spot in pressedkeys to on (t)
 *
 */
void key_down(KeySym key, bool* pressedkeys);

bool key_up(KeySym key, bool* pressedkeys);

bool action_in_pressedkeys(KeySym action, bool* pressedkeys);

#endif
