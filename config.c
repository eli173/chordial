
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
KeySym keyboard_keys[] = {XK_space, XK_J, XK_I, XK_O, XK_P};
unsigned long num_keys = 5;


/**
 * @brief User-defined keymapping
 *
 *
 *
 *
 */
keydef key_mapping[] = {
			(keydef){XK_A, k(1)},
			(keydef){XK_B, k(2)},
			(keydef){XK_C, k(3)},
			(keydef){XK_D, k(4)},
			(keydef){XK_E, k( 5)},

			(keydef){XK_F, k(1)|k(2)},
			(keydef){XK_G, k(1)|k(3)},
			(keydef){XK_H, k(1)|k(4)},
			(keydef){XK_I, k(1)|k(5)},
			(keydef){XK_J, k(2)|k(3)},
			(keydef){XK_K, k(2)|k(4)},
			(keydef){XK_L, k(2)|k(5)},
			(keydef){XK_M, k(3)|k(4)},
			(keydef){XK_N, k(3)|k(5)},
			(keydef){XK_O, k(4)|k(5)},

			(keydef){XK_P, k(1)|k(2)|k(3)},
			(keydef){XK_Q, k(1)|k(2)|k(4)},
			(keydef){XK_R, k(1)|k(2)|k(5)},
			(keydef){XK_S, k(1)|k(3)|k(4)},
			(keydef){XK_T, k(1)|k(3)|k(5)},
			(keydef){XK_U, k(1)|k(4)|k(5)},
			(keydef){XK_V, k(2)|k(3)|k(4)},
			(keydef){XK_W, k(2)|k(3)|k(5)},
			(keydef){XK_X, k(2)|k(4)|k(5)},
			(keydef){XK_Y, k(3)|k(4)|k(5)},

			(keydef){XK_Z, k(2)|k(3)|k(4)|k(5)},
			(keydef){XK_space, k(1)|k(2)|k(3)|k(4)},
			(keydef){XK_period, k(1)|k(3)|k(4)|k(5)},
			(keydef){XK_BackSpace, k(1)|k(2)|k(3)|k(5)}
			
			/*
  (keydef){XK_A, k(1)},
  (keydef){XK_S, k(2)},
  (keydef){XK_D, k(3)},
  (keydef){XK_F, k(4)},
  (keydef){XK_G, k(5)},
  (keydef){XK_H, k(6)},
  (keydef){XK_J, k(7)},
  (keydef){XK_K, k(8)},
  (keydef){XK_L, k(9)},
  
  (keydef){XK_Q, k(1) | k(12)},
  (keydef){XK_W, k(2) | k(12)},
  (keydef){XK_E, k(3) | k(12)},
  (keydef){XK_R, k(4) | k(12)},
  (keydef){XK_T, k(5) | k(12)},
  (keydef){XK_Y, k(6) | k(12)},
  (keydef){XK_U, k(7) | k(12)},
  (keydef){XK_I, k(8) | k(12)},
  (keydef){XK_O, k(9) | k(12)},
  (keydef){XK_P, k(10) | k(12)},
  
  (keydef){XK_Z, k(1) | k(13)},
  (keydef){XK_X, k(2) | k(13)},
  (keydef){XK_C, k(3) | k(13)},
  (keydef){XK_V, k(4) | k(13)},
  (keydef){XK_B, k(5) | k(13)},
  (keydef){XK_N, k(6) | k(13)},
  (keydef){XK_M, k(7) | k(13)}
			*/
  
};
unsigned long num_maps = 29;
  


