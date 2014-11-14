
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
  /* int nexts; */
  /* printf("ooo\n"); */
  /* char** exts; */
  /* exts = XListExtensions(disp, &nexts); */
  /* int i; */
  /* printf("nexts: %d\n",nexts); */
  /* for (i=0;i<nexts;i++) { */
  /*   printf("%s\n",exts[i]); */
  /* } */
  /* printf("%d\n",True); */
  XTestFakeKeyEvent(disp,
		    XKeysymToKeycode(disp, XStringToKeysym("a")),
		    True, CurrentTime);
    
  while(1){
    printf("Hi\n");
    XTestFakeKeyEvent(disp,
		      XKeysymToKeycode(disp, XStringToKeysym("e")),
		      True, CurrentTime);
    XFlush(disp);
    sleep(slptm);
  }
  return 0;
}
