#ifndef CONFIG_H
#define CONFIG_H

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
KeySym keyboard_keys[] = {XK_q,XK_w,XK_e,XK_r,XK_t,
			  XK_y,XK_u,XK_i,XK_o,XK_p,
			  XK_c,XK_v,
			  XK_n,XK_m,
			  XK_space};


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
  


#endif
