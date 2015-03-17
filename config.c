
#include "config.h"

#define k(n) (((unsigned long)1)<<(n-1))


#include <X11/Xlib.h>
#include <X11/keysym.h>



/**
 * @brief holds the keys you actually press 
 *
 * Should be able to handle up to 32 keys, 
 * and other config should handle it
 */
KeySym keyboard_keys[] = {XK_Q,XK_W,XK_E,XK_R,XK_T,
			  XK_Y,XK_U,XK_I,XK_O,XK_P,
			  XK_C,XK_V,
			  XK_N,XK_M,
			  XK_space};
unsigned long num_keys = 15;


/**
 * @brief User-defined keymapping
 *
 *
 *
 *
 */
keydef key_mapping[] = {
  (keydef){XK_q, k(1)},
  (keydef){XK_a, k(1) | k(12)},
  (keydef){XK_z, k(1) | k(13)}
};
unsigned long num_maps = 3;
  


