/* jets/e/playcore.c
**
*/
#include "all.h"
#include <stdio.h>      // helpful for debugging, removable after development

/* sime: identity function with debug prints
*/
  u3_noun
  u3qe_playcore_sime(u3_noun n)
  {
    fprintf(stderr, "u3qe_playcore_sime\n\r");
    u3k(n);

    if ( c3y == u3a_is_cat(n) ) {
      fprintf(stderr, "it's a short atom (cat)\n\r");
    }
    else if ( c3y == u3a_is_dog(n) ) {
      fprintf(stderr, "it's a long atom or cell (dog)\n\r");
    }

    return n;
  }

  u3_noun
  u3we_playcore_sime(u3_noun cor)
  {
    fprintf(stderr, "\n\ru3we_playcore_sime\n\r");
    u3_noun a;

    if ( c3n == u3r_mean(cor, u3x_sam, &a, 0) )
    {
      return u3m_bail(c3__exit);
    }
    else {
      return u3qe_playcore_sime(a);
    }
  }
