# Nouns & Vere Allocator

## Description
**TODO** explain exactly what the Loom pointer is pointing to

## Atoms and Endianness
Vere assumes that the system it is running on is little-endian, meaning that numbers are stored least-significant-byte-first. For example, the number `0xffaa` is stored internally as the bytes `{0xaa 0xff}`.

Vere represents long atoms as [arrays of words](https://github.com/urbit/urbit/blob/3fc5db758b5b27e574da4d1254768d480998ce63/pkg/urbit/include/noun/allocate.h#L53). The `c3_w` (word) buffer `buf_w` stores the words of the atom least-significant-word-first. So the number `0xdeadbeefaabbccdd` is stored internally as a `u3a_atom` with `buf_w = {0xaabbccdd, 0xdeadbeef}`. (Note that the 
 


## Nouns in Vere and the Allocator
The [definition of a u3 noun](https://github.com/urbit/urbit/blob/3fc5db758b5b27e574da4d1254768d480998ce63/pkg/urbit/include/noun/aliases.h#L35) is just a `c3_w`, i.e. a 32-bit integer.

In allocate.h, we can see [the rules for determining what type of noun](https://github.com/urbit/urbit/blob/3fc5db758b5b27e574da4d1254768d480998ce63/pkg/urbit/include/noun/allocate.h#L199) our 32-bit integer is:
* left-most bit is 0: it's an atom whose value is just the value of the integer.
* left-most bit is 1: it's a cell or a long atom

## Noun Lifecycle
Let's make this discussion more concrete by just going ahead and creating some nouns. As we do so, we can inspect them to see what is happening inside the allocator . We will also walk through the code that allocates each noun.

### Simplest: `cat` Atoms
`u3_noun cat_atom1 = u3i_word(0x11ff);`
This [just checks](https://github.com/urbit/urbit/blob/3fc5db758b5b27e574da4d1254768d480998ce63/pkg/urbit/noun/imprison.c#L292) whether the argument is < 2^32 -1, and because it is, it just casts it as a `u3_atom` and returns.

Next we have 
```
c3_y buf1[4] = {0xff, 0xff, 0xff, 0x7f};
u3_noun longest_cat = u3i_bytes(4, buf1);
```
`u3i_bytes` and `u3i_words` both assume Little Endian byte ordering, i.e. the first array element (`0xff`) is the *smallest*/*least significant* byte, so the actual number here is 0x7fffffff.  **TODO** show how little Endian happens

### a `dog` Atom


**TODO** instructions to install new jets file
**TODO** deconstruct the cell manually instead of using u3x_cell. Use u3a_to_ptr, which makes my noun into a real pointer
**TODO** do botox on the cell to show it on the Loom (see me_gain)

## Initialization
