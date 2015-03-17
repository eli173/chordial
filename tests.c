



#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include <stdbool.h>

#include "keymap.h"
#include "event_handler.h"
#include "sendkey.h"
#include "config.h"


int oldmain(int argc, char **argv)
{
  Display *display = XOpenDisplay(0);

  // test for send_key
  int event_base=0, error_base=0, major_version=0, minor_version=0;
  printf("uhhh\n");
  Bool enabled = XTestQueryExtension(display, &event_base, &error_base, &major_version, &minor_version);
  printf("event base: %d, error base: %d, major version: %d, minor version: %d, enabled?: %d\n",
	 event_base, error_base, major_version, minor_version, enabled);
  int i;
  for(i=0;i<10;i++)
    {
      send_key(XK_T);
      send_key(XK_e);
      send_key(XK_s);
      send_key(XK_t);
    }

  // tests kb grab
  Window rootwin = XRootWindow(display, XDefaultScreen(display));
  sleep(1);
  int xgksucc = XGrabKeyboard(display, rootwin, False, GrabModeAsync, GrabModeAsync, CurrentTime);
  printf("\n\nok\n\n");
  sleep(1);
  XEvent event; 
  bool exitvar = false;
  while(exitvar)
    {
      XMaskEvent(display, KeyPressMask | KeyReleaseMask, &event);
      KeySym ks = get_keysym(event);
      if(ks==XK_Escape)
	exitvar = true;
      unsigned long i;
      /* for(i=0;i<num_keys;i++) */
      /* 	  if(ks == keyboard_keys[i]) */
      /* 	    printf("in the thing\n"); */
      /* 	  else */
      /* 	    printf("not in the thing\n"); */
      printf("kp: %X\n", ks);
    }
  XUngrabKeyboard(display, CurrentTime);
  printf("%d\n",xgksucc);

  // tests for lookup
  unsigned long mask = 0;
  KeySym lu = NULL;
  //lookup()
  printf("num maps: %X\n", num_maps);
  for(mask=0;mask<num_maps;mask++)
    {
      printf("kmm %X: %X\n", mask, key_mapping[mask].chordmask);
    }
  printf("keys: \n");
  for(mask=0;mask<num_keys;mask++)
    {
      printf("k: %X\n",keyboard_keys[mask]);
    }
  printf("\n\n%X\n",XK_q);
  printf("0'd in");
  KeySym *retsym;
  printf("rly?");
  bool intbl = lookup(1, retsym);
  printf("OH-KAY!\n");
  printf("\n\nmask: %X lookup: %X, %X\n\n",1,intbl, *retsym);
  return 0;
}


int main(void)
{
    unsigned long mask = 0;
  KeySym lu = NULL;
  //lookup()
  printf("num maps: %X\n", num_maps);
  for(mask=0;mask<num_maps;mask++)
    {
      printf("kmm %X: %X\n", mask, key_mapping[mask].chordmask);
    }
  printf("keys: \n");
  for(mask=0;mask<num_keys;mask++)
    {
      printf("k: %X\n",keyboard_keys[mask]);
    }
  printf("\n\n%X\n",XK_q);
  printf("0'd in");
  KeySym *retsym;
  printf("rly?");
  bool intbl = lookup(1, *retsym);
  printf("OH-KAY!\n");
  printf("\n\nmask: %X lookup: %X, %X\n\n",1,intbl, *retsym);
  return 0;
}
