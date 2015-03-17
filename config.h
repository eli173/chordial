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
