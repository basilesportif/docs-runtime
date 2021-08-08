# Runtime Workflow
The goal of this lesson is to set up a workflow for iteratively inspecting data structures and operations in the runtime. At the end, we'll have a C file (`playcore.c`) that we can edit and re-compile to inspect the runtime.

To do this lesson, you should have gone through the [jet](https://github.com/timlucmiptev/docs-runtime/blob/master/jets1_current.md) [explainers](https://github.com/timlucmiptev/docs-runtime/blob/master/jets2_examples.md) and know [how to set up a fakeship](https://github.com/timlucmiptev/gall-guide/blob/master/workflow.md).

## Setup
1. Clone the urbit/urbit project
2. Make a new branch in it to work from (`git checkout -b playcore`)
3. Edit the following files in that project:
  - `jets/tree.c`
```
/* Jet registration of ++sime arm under playcore*/
static u3j_harm _140_hex__playcore_sime_a[] = {{".2", u3we_playcore_sime, c3y}, {}};
/* Associated hash */
static c3_c* _140_hex__playcore_sime_ha[] = {
  "2759a6931e9ef9a52c8eee43108843d94d3932a6b04f86cb6ba1555343293a28",
  0
};

static u3j_core _140_hex__playcore_d[] =
  { { "sime", 7, _140_hex__playcore_sime_a, 0, _140_hex__playcore_sime_ha },
  {}
  };
static c3_c* _140_hex__playcore_ha[] = {
  "2759a6931e9ef9a52c8eee43108843d94d3932a6b04f86cb6ba1555343293a28",
  0
};
```
  - find `_140_hex_d` in tree.c, and add:
  ```
  { "playcore",   31, 0, _140_hex__playcore_d, _140_hex__playcore_ha  },
  ```

  - `include/jets/q.h`
```
u3_noun u3qe_playcore_sime(u3_noun);
```
  - `include/jets/w.h`
```
u3_noun u3we_playcore_sime(u3_noun);
```

4. Switch to the src directory in this repo.
5. Copy the jet C file from src/
```
DIR=path/to/urbit/urbit
cp src/playjet/jets/e/playcore.c $DIR/pkg/urbit/jets/e/
```
6. back in the `urbit/urbit project`, compile:
```
cd pkg/urbit
nix-shell
./configure
make -j10
```
Now you have a compiled binary `build/urbit`.

7. Go back to this repo, and copy our hinted jet file to a fakeship
```
PIER=path/to/urbit/fakeship
cp src/playcore/lib/playcore.hoon $PIER/home/lib/
```

8. In your fakeship, commit the code and build the file
```
|mount %
|commit %home
=pc -build-file %/lib/playcore/hoon
```

## Using Our Workflow
Now we can play with our jetted `sime` gate in the dojo.  For each of the below expressions, you'll see prints happen, saying what type of noun you typed.  This uses the [allocate.h noun-type macros](https://github.com/urbit/urbit/blob/3fc5db758b5b27e574da4d1254768d480998ce63/pkg/urbit/include/noun/allocate.h#L199). 

You can look at src/playcore/jets/e/playcore.c to see the full source, and edit it if you want.
```
> (sime:pc 5)
> (sime:pc 7.182.192.928)
> (sime:pc [3 4])
```

## Summary
You now have a simple jet whose noun input you can manipulate and inspect. You can modify the jet by editing its source, copying it to `pkg/urbit/jets/e/` in your `urbit/urbit` project, recompiling, and running the binary.

In the following lessons, we'll use this as our base for playing with the runtime and printing out results.

## Exercises
1. For nouns that are `dog`s, do a further check as to whether they're `pug`s (long atoms) or `pom`s (cells). The necessary macros are in `allocate.h`.
