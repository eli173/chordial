
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>

#include "keybindings.h"
#include "keypress.h"

int main(int argc, char **argv) {
  Display *theDisplay = XOpenDisplay(NULL);
  if(theDisplay==NULL){
    fprintf(stderr, "Display is null...");
    exit(1);
  }
  int defaultScreen = XDefaultScreen(theDisplay);
  Window rootWin = XRootWindow(theDisplay, defaultScreen);

  XSetWindowAttributes rootAttribs;
  rootAttribs.event_mask = KeyPressMask | KeyReleaseMask;
  XChangeWindowAttributes(theDisplay, rootWin,
  			  CWEventMask, &rootAttribs);

  int xkgres = XGrabKeyboard(theDisplay, rootWin,
			     True, GrabModeAsync, GrabModeAsync,
			     CurrentTime);
  if(xkgres != 0) {
    printf("Could not grab keyboard\n");
    return 1;
  }
  
  XFlush(theDisplay);
  int event_no = 0;
  XEvent event;
  XKeyEvent send_key_event;
  send_key_event.display = theDisplay;
  send_key_event.root = rootWin;
  send_key_event.subwindow = None;
  send_key_event.time = CurrentTime;
  send_key_event.same_screen = True;
  send_key_event.state = 0;
  Bool gtfo = False;
  Bool pressedkeys[] = {False,False,False,False,False};
  Bool ignoreKeyUp = False;
  do {
    if(XPending(theDisplay)>0) {
      XNextEvent(theDisplay, &event);
      XKeyEvent kev = event.xkey;
      KeySym ks;
      char *retbuf;
      retbuf = malloc(20*sizeof(char));
      XLookupString(&kev, retbuf, 20, &ks, NULL);
      if(kev.type == KeyPress) {
	ignoreKeyUp = False;
	switch (ks) {
	case XK_q:
	  gtfo = True;
	  break;
	case XK_space:
	  pressedkeys[0] = True;
	  break;
	case XK_k:
	  pressedkeys[1] = True;
	  break;
	case XK_o:
	  pressedkeys[2] = True;
	  break;
	case XK_p:
	  pressedkeys[3] = True;
	  break;
	case XK_apostrophe:
	  pressedkeys[4] = True;
	  break;
	}
      }
      if(kev.type == KeyRelease) {
	if(ignoreKeyUp==False) {
	  ignoreKeyUp = True;
	  /* XSendEvent(theDisplay, InputFocus, False, */
	  /* 	       KeyPressMask, send_event); */
	  /* // MODIFY SEND_EVENT!!! */
	  /* XSendEvent(the, InputFocus, False, KeyReleaseMask, */
	  /* 	       send_event); */
	  char kchar = onRelease(pressedkeys);
	  KeyCode kc = XKeysymToKeycode(theDisplay,
					XStringToKeysym(&kchar));
	  
	  
	  /* XUngrabKeyboard(theDisplay, CurrentTime); */
	  // ENDLESS FEEDBACK LOOP!!!
	  XTestFakeKeyEvent(theDisplay, kc, True, CurrentTime);
	  XFlush(theDisplay);
	  XTestFakeKeyEvent(theDisplay, kc, False, CurrentTime);
	  XFlush(theDisplay);
	  /* XGrabKeyboard(theDisplay, rootWin, True, GrabModeAsync, */
	  /* 		GrabModeAsync, CurrentTime); */
	  
	  
	  /* send_key_event.window = InputFocus; */
	  /* send_key_event.keycode = kc; */
	  /* send_key_event.type = KeyPress; */
	  /* XSendEvent(theDisplay, InputFocus, False, */
	  /* 	       KeyPressMask, (XEvent *)&send_key_event); */
	  /* send_key_event.type = KeyRelease; */
	  /* int xser = XSendEvent(theDisplay, InputFocus, False, */
	  /* 			  KeyPressMask, */
	  /* 			  (XEvent *)&send_key_event); */
	  /* printf("xser: %d\t",xser); */
	  
	  printf("%d: %c\n",boolstonum(pressedkeys)
		 ,onRelease(pressedkeys));
	}
	switch (ks) {
	case XK_space:
	  pressedkeys[0] = False;
	  break;
	case XK_k:
	  pressedkeys[1] = False;
	  break;
	case XK_o:
	  pressedkeys[2] = False;
	  break;
	case XK_p:
	  pressedkeys[3] = False;
	  break;
	case XK_apostrophe:
	  pressedkeys[4] = False;
	  break;
	}
      }
      
    }
    
  } while(gtfo == False);
  
  
  
  XCloseDisplay(theDisplay);
  return 0;
}
