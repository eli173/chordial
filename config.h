#ifndef CONFIG_H
#define CONFIG_H

#include <X11/Xlib.h>

typedef struct {
  KeySym action;
  unsigned long chordmask;
} keydef;

KeySym *keyboard_keys;

keydef *key_mapping;



#endif
