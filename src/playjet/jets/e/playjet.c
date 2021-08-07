/* jets/e/playjet.c
**
*/
#include "all.h"
#include <stdio.h>      // helpful for debugging, removable after development

/* sime: identity function with debug prints
*/
  u3_noun
  u3qe_playjet_sime(u3_noun n)
  {
    fprintf(stderr, "u3qe_playjet_sime\n\r");
    u3k(n);
    return n;
  }

  u3_noun
  u3we_playjet_sime(u3_noun cor)
  {
    fprintf(stderr, "u3we_playjet_sime\n\r");
    u3_noun a;

    if ( c3n == u3r_mean(cor, u3x_sam, &a, 0) )
    {
      return u3m_bail(c3__exit);
    }
    else {
      return u3qe_playjet_sime(a);
    }
  }
