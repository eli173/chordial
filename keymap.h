
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
