
#ifndef SENDKEY_H
#define SENDKEY_H

#include <X11/Xlib.h>

int send_key(KeySym keysym, Display* display);
int send_key_up(KeySym keysym, Display* display);
int send_key_down(KeySym keysym, Display* display);

#endif
