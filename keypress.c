
#include "keybindings.h"
#include "keypress.h"

int boolstonum(Bool* bools) {
  int i, n;
  for(i=0,n=0;n<5;n++) {
    if(bools[n]) {
      i += 1<<n;
    }
  }
  return i;
}

char onRelease(Bool* keysdown) {
  /* !! Warning: don't unset the keyup before calling */
  /* keysdown must have 5 elements (subj. to change) */
  ushort i;
  ushort k=0;
  for(i=0;i<5;i++) {
    if(keysdown[i]) {
      k += 1<<i;
    }
  }
  return e_better_keybinds[k];
}
