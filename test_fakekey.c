
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv) {
  int slptm = 20;
  if(argc>1)
    slptm = atoi(argv[1]);
  printf("%d\n",slptm);
  Display *disp = XOpenDisplay(NULL);
  Window root = XRootWindow(disp, XDefaultScreen(disp));
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("a")),
		    True, CurrentTime);
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("a")),
		    False, CurrentTime);

  XGrabKeyboard(disp, root, True, GrabModeAsync,
		GrabModeAsync, CurrentTime);
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("b")),
		    True, CurrentTime);
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("b")),
		    False, CurrentTime);
  XUngrabKeyboard(disp, CurrentTime);  
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("c")),
		    True, CurrentTime);
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("c")),
		    False, CurrentTime);
  XGrabKeyboard(disp, root, True, GrabModeAsync,
		GrabModeAsync, CurrentTime);
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("d")),
		    True, CurrentTime);
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("d")),
		    False, CurrentTime);

  XUngrabKeyboard(disp, CurrentTime);
  
  while(1){
    printf("Hi\n");
    XTestFakeKeyEvent(disp,
  		      XKeysymToKeycode(disp, XStringToKeysym("e")),
  		      True, CurrentTime);
    XTestFakeKeyEvent(disp,
  		      XKeysymToKeycode(disp, XStringToKeysym("e")),
  		      False, CurrentTime);
    XFlush(disp);
    sleep(20);
  }
  return 0;
}
