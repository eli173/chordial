
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
  /* (keydef){XK_a, k(1)}, */
  /* (keydef){XK_s, k(2)}, */
  /* (keydef){XK_d, k(3)}, */
  /* (keydef){XK_f, k(4)}, */
  /* (keydef){XK_g, k(5)}, */
  /* (keydef){XK_h, k(6)}, */
  /* (keydef){XK_j, k(7)}, */
  /* (keydef){XK_k, k(8)}, */
  /* (keydef){XK_l, k(9)}, */
  
  /* (keydef){XK_q, k(1) | k(12)}, */
  /* (keydef){XK_w, k(2) | k(12)}, */
  /* (keydef){XK_e, k(3) | k(12)}, */
  /* (keydef){XK_r, k(4) | k(12)}, */
  /* (keydef){XK_t, k(5) | k(12)}, */
  /* (keydef){XK_y, k(6) | k(12)}, */
  /* (keydef){XK_u, k(7) | k(12)}, */
  /* (keydef){XK_i, k(8) | k(12)}, */
  /* (keydef){XK_o, k(9) | k(12)}, */
  /* (keydef){XK_p, k(10) | k(12)}, */
  
  /* (keydef){XK_z, k(1) | k(13)}, */
  /* (keydef){XK_x, k(2) | k(13)}, */
  /* (keydef){XK_c, k(3) | k(13)}, */
  /* (keydef){XK_v, k(4) | k(13)}, */
  /* (keydef){XK_b, k(5) | k(13)}, */
  (keydef){XK_n, k(6) | k(13)},
  /* (keydef){XK_m, k(7) | k(13)} */
  (keydef){XK_v, k(3) | k(12)},
  (keydef){XK_p, k(10)}
  
};
unsigned long num_maps = 3;
  


