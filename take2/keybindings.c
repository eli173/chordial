
#include<stdbool.h>
#include<unistd.h>

char* e_keybinds = "0abcdefghijklmnopqrstuvwxyz .,-\b";

char* e_usrkeys = " kop'";

char* e_better_keybinds = {"0abfcgjpdhkqmsvzeilrntw oux.y,-\b"};


char
get_char(bool* keysdown) {
  ushort i;
  ushort k;
  for(i=0,k=0;i<5;i++){
    if(keysdown[i]) {
      k += 1<<i;
    }
  }
  return e_better_keybinds[k];
}




/* int */
/* boolstonum(bool* bools) { */
/*   // bools must have 5 bools in it */
/*   int i,n; */
/*   for(i=0,n=0;n<5;n++) { */
/*     if(bools[n]) { */
/*       i += 1<<n; */
/*     } */
/*   } */
/*   return i; */
/* } */
