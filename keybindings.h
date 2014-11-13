#ifndef KEYBINDINGS_H
#define KEYBINDINGS_H

#include <X11/Xlib.h>
#include <X11/keysym.h>

typedef struct keypair {
  ushort keysym;
  char keychar;
} keypair;

char* e_better_keybinds; //= "0abcdefghijklmnopqrstuvwxyz .,-\b";

char* e_keybinds; 

char* e_usrkeys; //= " kop'";


  /* {'a','b','c','d','e','f','g','h','i','j','k','l', */
  /*  'm','n','o','p','q','r','s','t','u','v','w','x', */
  /*  'y','z',' ','.',',','-'}; */



#endif // KEYBINDINGS_H
