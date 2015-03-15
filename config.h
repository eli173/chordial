#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
  KeySym action;
  unsigned long chordmask;
} keydef;

KeySym *keyboard_keys;

keydef *key_mapping;



#endif
