
#ifndef SENDKEY_H
#define SENDKEY_H

#include <X11/Xlib.h>

int send_key(KeySym keysym, Display* display);

#endif
