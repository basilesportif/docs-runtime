# Nouns & Vere Allocator

## Description
**TODO** explain exactly what the Loom pointer is pointing to

## Nouns in Vere and the Allocator
The [definition of a u3 noun](https://github.com/urbit/urbit/blob/3fc5db758b5b27e574da4d1254768d480998ce63/pkg/urbit/include/noun/aliases.h#L35) is just a `c3_w`, i.e. a 32-bit integer.

In allocate.h, we can see [the rules for determining what type of noun](https://github.com/urbit/urbit/blob/3fc5db758b5b27e574da4d1254768d480998ce63/pkg/urbit/include/noun/allocate.h#L199) our 32-bit integer is:
* left-most bit is 0: it's an atom whose value is just the value of the integer.
* left-most bit is 1: it's a cell or a long atom

## Allocating Atoms and Cells
Let's make this discussion more concrete by just going ahead and creating some nouns. As we do so, we can inspect them to see what is happening inside the allocator.

**TODO** instructions to install new jets file
**TODO** deconstruct the cell manually instead of using u3x_cell. Use u3a_to_ptr, which makes my noun into a real pointer
**TODO** do botox on the cell to show it on the Loom (see me_gain)

## Initialization
