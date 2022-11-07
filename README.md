<h1 align="center">
	<img src="./logo/blocky_snake.png" height="160px"/><br>
	Garter, by JohnAlex.CO
</h1>

## Language Description

Garter is simultaneously "higher-level" than Python, while "lower-level" than C -- 
among some of its more novel features are the ability to infer enveloping, 
a macro-ing system that supports compiler flags and build routines _written in Garter_,
the ability to directly manipulate registers and define bytes in memory like you would in Assembly,
and having an inferred dynamic type system that is also nominal and statically compiled.
It's a vaguely "Pythonic" language in look and feel that is heavily inspired by BASIC, Netwide Assembler, and C89/C99.

## UPDATED: When will Executables and Source code be available? 

Because of other comissions and work I have at the moment, I don't have release date at the moment. 
I do have some changes I'm making to the roadmap, and I hope I can have more updates soon.
Demos will be up on my YouTube soonish, and the release date is, until then, **TBD**.


## Language Specification

I plan on uploading the language specification as soon as possible, but the documentation is presently incomplete.
Briefly, though, the language:
- is semantically whitespaced, like Python, but does not care about whether you use tabs or spaces interchangably
- includes the following basic data-types: integers, floats, strings, _linked arrays_, and dictionaries.
- supports pointers and pointer arithmetic without including a separate explicit type
- interprets `*macro` blocks and retreives their return value to inline during compilation
- includes a small standard library with functions for manipulating strings, objects, rendering markdown and HTML,
system interrupts, and only includes what is needed, allowing it to achieve a `"Hello World"` was less than 160 bytes (x86-64 ELF for generic Linux) during testing.
