# Jets in the Urbit Runtime

Who you are: someone who a bit of Hoon and (ideally but not necessarily) Nock. You don't know much about the runtime or jet system.

What you'll know after reading: 
- why Urbit jets work the way they do
- what you need to do to write them
- how you'd implement a Nock interpreter that uses them
- how they're going to get easier to manage in future runtimes

And you're going to learn this all pretty quickly, because it's not that complicated!

*Note regarding Nock*
If you *don't* already know Nock, it may be useful to gain a background:
* [Nock Explanation](https://urbit.org/docs/nock/explanation/)
* [Nock for Everyday Programmers](https://blog.timlucmiptev.space/part1.html)

## Motivation

### How You'd Think Jets Work
When people see that Nock allows "hints" to be compiled into code, they assume that a jet would work roughly as follows:
1. The programmer puts a "hint" on a function, (e.g. `dec`), and that hint compiles around a chunk of code.
2. When the runtime encounters code marked with `dec`, it checks whether it has a jet called `dec`, and calls it with the current subject as the argument if such a jet exists.
3. The jet runs and returns its result.

This requires trust/verification/testing that the `dec` jet works correctly, but there are ways to handle that.

### Why Jets Don't Work That Way
**disclaimer** The code and description of the runtime in this section are imaginary.
The problem here is that any software installed on your Urbit can emit hints that label a piece of code as `dec`.  

Let's assume jets work that way, and imagine that I distribute a piece of software with a gate called `const`, which simply takes its argument and returns it. However, I hint it with the `%dec` hint: 
```
++  const
  ASSUME `dec` HINTING CODE IS HERE
  |=  x=*
  x 
```
Now, when the runtime encounters `const`, it would go ahead and run the `dec` jet if it exists.  Why is that a problem?  Well, to take one case, if the user moved his Urbit to a different runtime that *didn't* have the `dec` jet, and replayed the event log, the resulting ship state would be different.

*Aside*: the reader may note that this problem could be resolved by requiring users to check jet hints in code they install for conflicts with `hoon.hoon` jet names. As a result, there is some disagreement among Urbit developers as to whether this is a problem. For now, just know that the current runtime *does* consider it to be a problem and takes steps to avoid it, and future solutions seem likely to as well.

### A Solution
To solve this problem, Vere currently requires a specific form of hinting in Hoon, and registration of jets when the runtime is compiled. Let's look at these in order.

Hoon hinting is applied to cores (more on why in a bit), and uses the `~%` rune (or `~/` which is sugar for it). `~%` takes as args:
- a name (e.g. `%dec`)
- a wing that locates this core's "parent"
- list of "hooks" (can ignore for this discussion; usually an empty list)

Runtime jet registration happens in the `tree.c` file. There, jets must declare: 
1. their name (e.g. `%dec`)
2. the hash of their formula
3. their location in the tree of cores

#### Core Hinting and Parent Cores
**TODO** explain why we hint cores, not formulas (parent ref)
**TODO** <insert Teds diagram here>

### Current Jet Matching/Registration Process
The information above is declared in `tree.c`. "Jet matching" refers to the process of the interpreter checking whether a jet hint in Nock matches the jet registered in `tree.c`.

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

