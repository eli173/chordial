
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

#endif
