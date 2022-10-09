## Language Description

Garter is simultaneously "higher-level" than Python, while "lower-level" than C -- 
among some of its more novel features are the ability to infer enveloping, 
a macro-ing system that supports compiler flags and build routines _written in Garter_,
the ability to directly manipulate registers and define bytes in memory like you would in Assembly,
and having an inferred dynamic type system that is also nominal and statically compiled.
It's a vaguely "Pythonic" language in look and feel that is heavily inspired by BASIC, Netwide Assembler, and C89/C99.

## When will Executables and Source code be available? 

In roughly two weeks, when the 0.0.0 version is complete; while there is a partially complete compiler right now,
it isn't useful for anything except printing strings and loading things into memory. 
If you're excited to try it out, you'll either need to be on an x86-32 or x86-64 system (Windows, Linux, MacOS),
or have a _netwide assembler_ available to build the compiler.

## Language Specification

I plan on uploading the language specification as soon as possible, but the documentation is presently incomplete.
Briefly, though, the language:
- is semantically whitespaced, like Python, but does not care about whether you use tabs or spaces interchangably
- includes the following basic data-types: integers, floats, strings, _linked arrays_, and dictionaries.
- supports pointers and pointer arithmetic without including a separate explicit type
- interprets `*macro` blocks and retreives their return value to inline during compilation
- includes a small standard library with functions for manipulating strings, objects, rendering markdown and HTML,
system interrupts, and only includes what is needed, allowing it to achieve a `"Hello World"` was less than 160 bytes (x86-64 ELF for generic Linux) during testing.

## Implementation

- uses a [linear, slab-based memory allocator](https://slembcke.github.io/Custom-Allocators) based on _**"Frames"**_.
- memory allocation is [greedy](https://en.wikipedia.org/wiki/Greedy_algorithm) in exchange for not requiring a garbage collector, 
manual memory management, or an equivalent to `malloc()`
- the self-hosted compiler is itself a standalone interpreter containing the standard library, compiler, documentation, and tools. it _**does not**_ contain a REPL
- langauge was written in chunks of garter-pseudocode that's been translated by-hand to assembly; it will then be re-written in actual Garter and compiled by itself to produce the self-hosted binary 


## Additional Information

I expect to have documetation available on this repo next week, and binaries ready for testing before Halloween.
If you'd like some additional information about how Garter compares to other languages, check out the [Comparison Info](info/comparisons.md) page

To all the folk that came here from the Nullposting group, I appreciate you endlessly. I wanted to ask about interest in the project early because I'm approaching the point of having a working 0.0.0 pretty quickly, and I'm really grateful so many of you are interested in bullying me for the greater good <3 

## Okay but give me some fucking pseudocode, bro

Here is some code that the partially complete compiler can (or will be able to) run properly
```python
render = *functon object
    if object.tag == undefined | *type(object.tag) != 'string'
        return null
    string = '<'+object.tag+'>'
    k = *object.keys(object)
    l = *length(k)
    n = 0
    # the parenthesis in here de-reference the attrs
    # so that the compiler knows we mean index k by the value of variable n
    # and not to index it like a hashtable for the attribute named n
    while n++ <= l
        string += k.(n) +'="'+ object.(k.(n)) + '"'
    return string +='/>'
```
```python
set = array: 'A' 'B' "C"
x = 0
while x < *macro *length(set) # the value at compile-time, not the dynamically changing size 
	*append set x # the compiler knows you meant *append(set, x)
	x++
*print set
```

```python
x = 399
ptr @= x 
*print "the variable x is stored at memory location " ptr
```
