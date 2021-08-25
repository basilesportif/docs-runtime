/* jets/e/playcore.c
**
*/
#include "all.h"
#include <stdio.h>

void print_atom(char* label, u3_atom a)
{
  mpz_t a_mp;
  u3r_mp(a_mp, a);
  gmp_fprintf(stderr, "%s: 0x%Zx\n\r", label, a_mp);
}
/* sime: identity function with debug prints
*/
  u3_noun
  u3qe_playcore_sime(u3_noun n)
  {
    u3k(n);   //u3k is short for u3a_lose

    u3_noun cat_atom = u3i_word(0x11ff);

    c3_y buf1[4] = {0xff, 0xff, 0xff, 0x7f};
    u3_noun longest_cat = u3i_bytes(4, buf1);

    //  words/bytes comparison
    c3_y buf2[8] = {0xdd, 0xee, 0xbb, 0x00, 0x44, 0x33, 0x22, 0x00};
    u3_noun bytes_atom = u3i_bytes(8, buf2);
    print_atom("pug, bytes_atom", bytes_atom);

    c3_w ws[2] = {0xbbeedd, 0x223344};
    u3_noun words_atom = u3i_words(2, ws);
    print_atom("pug, words_atom", words_atom);

    // u3nc is short for u3i_cell (in include/noun/aliases.h)
    u3_noun my_cell = u3nt(cat_atom, words_atom, longest_cat); 

    if ( c3y == u3a_is_pom(my_cell) )
      fprintf(stderr, "my_cell is a pom (cell)\n\r");
    
    u3_noun h = ((u3a_cell*)u3a_to_ptr(my_cell))->hed;
    u3_noun t = ((u3a_cell*)u3a_to_ptr(my_cell))->tel;

   /*
    u3_noun hed, tel;
    u3x_cell(my_cell, &hed, &tel);
    */
    fprintf(stderr, "longest_cat: 0x%x\n\r", longest_cat);
    fprintf(stderr, "head (simple cat atom): %u\n\r", h);
    fprintf(stderr, "tail (Loom pointer with left bit set): 0x%x\n\r", t);
    fprintf(stderr, "tail as a 28-bit Loom pointer: 0x%x\n\r", t & 0xfffffff);

    u3a_lose(my_cell);
    u3k(bytes_atom);

    // TODO: the below will crash
//    u3z(cat_atom);

 //   u3z(pug_atom);

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
