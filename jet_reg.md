# Jets in the Urbit Runtime

Who you are: someone who a bit of Hoon and (ideally but not necessarily) Nock. You don't know much about the runtime or jet system.

What you'll know after reading: 
- why Urbit jets work the way they do
- what you need to do to write them
- how you'd implement a Nock interpreter that uses them
- how they're going to get easier to manage in the future.

And you're going to learn this all pretty quickly, because it's not that complicated!

## Motivation

### How You'd Think Jets Work
When people see that Nock allows "hints" to be compiled into code, they assume that a jet would work roughly as follows:
1. The programmer puts a "hint" on a function, like `dec`, and that hint compiles around a chunk of code.
2. When the runtime encounters code marked with `dec`, it checks whether it has a jet called `dec`, and calls it with the current subject as the argument if such a jet exists.
3. The jet runs and returns its result.

This requires trust/verification that the `dec` jet works correctly, but there are ways to handle that.

### Why Jets Don't Work That Way
**disclaimer** The code and description of the runtime in this section are imaginary.
The problem here is that any software installed on your Urbit can emit hints, labeling a piece of code as `dec`.  

Let's assume jets work that way, and imagine that I distribute a piece of software with a gate called `const`, which simply takes its argument and returns it. However, I hint it with the `%dec` hint: 
```
++  const
  ~/  %dec
  |=  x=*
  x 
```
Now, when the runtime encounters `const`, it would go ahead and run `dec` if the `dec` jets exists.  Why is that a problem?  Well, to take one case, if the user moved his Urbit to a different runtime that *didn't* have the `dec` jet, and replayed the event log, the resulting ship state would be different.

*Aside*: the reader may note that this problem could be resolved by simply requiring users to vet any jet hints in code they install, and to make sure they don't use the same names as core jets. As a result, there is some disagreement among Urbit developers as to whether this is a problem. For now, just know that the current runtime *does* consider it to be a problem and takes steps to avoid it, and future solutions seem likely to as well.

### A Solution
One solution (currently used in Vere) to this problem is to register jets with the runtime, so that the runtime can detect whether a given hint it encounters is valid. Currently, jets must declare:
1. their name (e.g. `%dec`)
2. the hash of their formula
3. their location in the tree of cores

Point 3 requires a bit of explanation. The Urbit standard library is set up as a tree of cores, where any core holds its parent in its context.
**TODO** <insert Teds diagram here>
Think back to our "evil" jet, `const`. If we had registered `%dec` and said that its parent must be the core in which `+dec` is declared in `hoon.hoon`, then the runtime could have looked back when it encountered `const`'s hint, and seen that this `%dec` didn't occur in the "proper" place.

### Current Jet Matching/Registration Process
In the current implementation of the Urbit runtime:
* developers write cores hinted with jets
* those jets are registered with the runtime
* the runtime uses that registration to check whether a given jet hint is valid

#### At Code Writing Time
When a developer hints a core, he must explictly give a path to the core's "parent".
**TODO**: note that cores, not formulas, are hinted.

#### At Registration Time


#### Jet Validation at Runtime

-------------------------------
## Jet Writing Process

