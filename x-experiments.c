
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
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
  printf("%d\n",XDisplayHeightMM(theDisplay, defaultScreen));
  unsigned long bw[2] = {XBlackPixel(theDisplay, defaultScreen),
			 XWhitePixel(theDisplay, defaultScreen)};
  printf("B:%lu W:%lu\n",bw[0],bw[1]);
  Window rootWin = XRootWindow(theDisplay, defaultScreen);
  XSetWindowAttributes winAttribs;
  winAttribs.background_pixmap = None;
  winAttribs.background_pixel = 0x888888;
  winAttribs.border_pixmap = CopyFromParent;
  winAttribs.bit_gravity = ForgetGravity;
  winAttribs.win_gravity = NorthWestGravity;
  winAttribs.backing_store = NotUseful;
  winAttribs.backing_planes = ~(0UL);
  winAttribs.backing_pixel = 0;
  winAttribs.save_under = False;
  winAttribs.override_redirect = False;
  winAttribs.colormap = CopyFromParent;
  winAttribs.cursor = None;
  winAttribs.event_mask = KeyPressMask | KeyReleaseMask;
  winAttribs.do_not_propagate_mask = NoEventMask;
  Window myWin = XCreateWindow(theDisplay, rootWin, 0, 0, 400, 400,
			       10, CopyFromParent, InputOutput,
			       CopyFromParent,
			       CWBackPixel|
			       CWEventMask | CWDontPropagate,
			       &winAttribs);

  //sleep(2);
  XMapWindow(theDisplay, myWin);
  XRaiseWindow(theDisplay, myWin);
  //redundant XSelectInput(disp, win, event_mask), done in winattribs
  //fprintf(stdout,"pending: %d",XPending(theDisplay));
  /* XFlush(theDisplay); */
  /* fprintf(stdout, "go\n") */
  /* sleep(2); */
  /* fprintf(stdout,"evts:%d\n", */
  /* 	  XEventsQueued(theDisplay, QueuedAfterFlush)); */
  //fprintf(stdout,"pending: %d",XPending(theDisplay));  
  // remember XSendEvent...
  //  rootWin.
  XSetWindowAttributes rootAttribs;
  rootAttribs.event_mask = KeyPressMask | KeyReleaseMask;
  XChangeWindowAttributes(theDisplay, rootWin,
			  CWEventMask, &rootAttribs);
  int xgkres = XGrabKeyboard(theDisplay, rootWin,
			     True, GrabModeAsync,
			     GrabModeAsync, CurrentTime);
  if(0==xgkres) {
    printf("No go\n");
    return 1;
  }
  //XAllowEvents(theDisplay, AsyncKeyboard, CurrentTime);
  XFlush(theDisplay);
  int event_no = 0;
  XEvent event;
  Bool gtfo = False;
  Bool pressedkeys[] = {False,False,False,False,False};
  Bool ignoreKeyUp = False;
  //printf("XK_q=%d");
  do {
    //fprintf(stdout,"in do\n");
    //event_no = XEventsQueued(theDisplay, QueuedAfterFlush);
    //fprintf(stdout,"ev: %d\n",event_no);
    if(XPending(theDisplay)>0) {
      XNextEvent(theDisplay, &event);
      /*if(event.type == XKeyEvent) {*/
	XKeyEvent kev = event.xkey;
	//printf("kc: %d\n",kev.keycode);
	KeySym ks;
	char *retbuf;
	retbuf = malloc(20*sizeof(char));
	//ks = XLookupKeysym(&kev, 1);
	XLookupString(&kev, retbuf, 20, &ks, NULL);
	if(kev.type == KeyPress) {
	  //printf("okayyy...\n");
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
	//else {printf("Non-press event: %d\n",kev.type);}
	// Key Release Here!!!
	if(kev.type == KeyRelease) {
	  //printf("Relea\n");
	  if(ignoreKeyUp==False) {
	    // Send a key
	    // Temporary printf
	    ignoreKeyUp = True;
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
	
	//printf("%c\n",onRelease(pressedkeys));
	/* printf("%d,%d,%d,%d,%d\n",pressedkeys[0], */
	/*        pressedkeys[1], */
	/*        pressedkeys[2], */
	/*        pressedkeys[3], */
	/*        pressedkeys[4]); */
	/* if(ks==XK_q){ */
	/*   gtfo = True; */
	/* } */
	
	/*}*/
    }
    
  } while(gtfo == False);
  
  
  //  sleep(2);
  
  XCloseDisplay(theDisplay);
  //printf("%d",(sizeof(keybinds) * sizeof(char)));
  return 0;
}


// NONSENSE FROM MAIN LOOP
	//printf("%s\n",XKeysymToString(ks));
	//printf("%s\n",retbuf);
	// q == 24
	//KeySym *ks = XGetKeyboardMapping(theDisplay, kev.keycode, arg2, arg3)
	/* printf("okayy... %d\n",ks); */
	/* if(ks==XK_q) { */
	/*   printf("it works\n"); */
	/* } */
	/* else { */
	/*   printf("no dice\n"); */
	/* } */
