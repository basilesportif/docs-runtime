# More Jets: Cores, Jets and Hints
In the [current jets explainer](jets_current.md), we looked at how jet matching is done. Now, we'll move on to an explanation of Urbit's core stack, detailed examples of a jet and its registration, and the mechanics of how hints are implemented.

## Intro

### New Tools
`!=` will be useful throughout this explainer. It lets you enter Hoon at the dojo and see what Nock that Hoon compiles to.  We can do this because every dojo command is run against the current subject, so dojo commands are just Nock formulas.

Examples:
```
> =x 56
> !=(x)
[0 2]
::  x is located at address 2 in my Dojo subject; yours might be different

> !=(add)
[9 36 0 2.047]
::  "get the core at slot 2047, and then pull the arm at slot 36 in it"
::  remember, add is an arm that *generates* a gate

::  running that Nock against the subject produces the same gate as
::  pulling the add arm directly:
> =(add .*(. [9 36 0 2.047]))
```

### Reminders
It's easy to get confused between arms and cores, particularly because arms can produce cores/gates. Remember: arms are just Nock formulas, while cores have formulas on the left side of their tree, and data (context) on the right side.

## The Core Stack
**TODO** note that the final element of any gate is `140`

## Jet Walkthrough
Now we will walk through the Hoon, Nock, and runtime registrations of the `add` jet in full. Before starting, run the below code, which sets `add-arm` to the formula that produces the `add` gate:
```
=add-arm .*(. [7 [0 2.047] 0 36])
```
Note that this is similar to Nock `[9 36 0 2.047]`--we just don't pull the arm against the subject yet.

### The Compiled Hint
**TODO** walk through the compilation of the hint at the `sggl` level
`add-arm` is a Nock 7 that composes two operations. The first (starting with `[8...`) is just  the formula that produces the add gate. The second operation is our jet hint:
```
 11
  [1.953.718.630 1 6.579.297 [0 7] 0]
  0
  1
```
The hint finishes with `[0 1]`, so it just returns the current subject after hinting. We care about `[1.953.718.630 1 6.579.297 [0 7] 0]`. This is the form of Nock 11 where the hint is a cell: 
* head: a static value
* tail: a Nock formula that the runtime can compute

`@t` aura on the head gives `'fast'`, so the runtime knows this is a jet hint using the fast-hint system (current jetting system).

The tail is a `1` formula that produces `'add'` (`6.579.297`) followed by `[0 7]` (the parent axis) and `0` (the empty list `~`).


### Registration
https://github.com/urbit/urbit/blob/b0c9fd1940fe1c119438947ac0a45bafec135860/pkg/urbit/jets/tree.c#L1975


## Custom Hinting

