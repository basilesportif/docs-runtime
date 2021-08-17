/* jets/e/playcore.c
**
*/
#include "all.h"
#include <stdio.h>

/* sime: identity function with debug prints
*/
  u3_noun
  u3qe_playcore_sime(u3_noun n)
  {
    u3k(n);

    u3_noun cat_atom = u3i_chub(0x11ff);
    c3_y buf[4] = {0xff, 0xff, 0xff, 0xff};
    u3_noun pug_atom = u3i_bytes(4, buf);
    u3_noun my_cell = u3i_cell(cat_atom, pug_atom); 

    if ( c3y == u3a_is_pom(my_cell) )
      fprintf(stderr, "my_cell is a pom (cell)\n\r");
    
    u3_noun h = ((u3a_cell*)u3a_to_ptr(my_cell))->hed;
    u3_noun t = ((u3a_cell*)u3a_to_ptr(my_cell))->tel;

   /*
    u3_noun hed, tel;
    u3x_cell(my_cell, &hed, &tel);
    */
    fprintf(stderr, "head (simple cat atom): %u\n\r", h);
    fprintf(stderr, "tail (Loom pointer with left bit set): 0x%x\n\r", t);
    fprintf(stderr, "tail as a 28-bit Loom pointer: 0x%x\n\r", t & 0xfffffff);

    //TODO: why is this broken for the cell?
    //u3a_lose(my_cell);
    u3a_lose(cat_atom);
    u3a_lose(pug_atom);

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
