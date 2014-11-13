
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <stdlib.h>
#include <unistd.h>


int main(void) {
  Display *disp = XOpenDisplay(NULL);
  int nexts;
  printf("ooo\n");
  char** exts;
  exts = XListExtensions(disp, &nexts);
  int i;
  printf("nexts: %d\n",nexts);
  for (i=0;i<nexts;i++) {
    printf("%s\n",exts[i]);
  }
  printf("%d\n",True);
  while(1){
    printf("succ: %d\t",XTestFakeKeyEvent(disp,
		      XKeysymToKeycode(disp, XStringToKeysym("e")),
			      True, CurrentTime));
    XFlush(disp);
    printf("uh..\n");
    sleep(2);
  }
  return 0;
}
