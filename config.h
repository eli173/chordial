
#include <X11/Xlib.h>
#include <X11/keysym.h>


/**
 * @brief holds the keys you actually press 
 *
 * Should be able to hold any number of keys, 
 * and other config should handle it
 */
KeySym keyboard_keys[] = {XK_q,XK_w,XK_e,XK_r,XK_t,
			  XK_y,XK_u,XK_i,XK_o,XK_p,
			  XK_c,XK_v,
			  XK_n,XK_m,
			  XK_space};
