
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
