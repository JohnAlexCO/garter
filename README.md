<h1 align="center">
	<img src="https://johnalex.co/gy.png?github-johnalexco" height="160px"/><br>
	Garter, by JohnAlex.CO
</h1>

## Language Description

Garter is planned to be a vaguely "Pythonic" language in look and feel, and is heavily inspired by BASIC, Netwide Assembler, and C89/C99.
It compiles to x86 Assembly _(additional targets only planned in the future)_ and will include support for macros, object-based programming, direct access to syscalls, and is built on what I believe to be the minimum amount of abstraction necessary to still allow it to be free of unnecessary boiler-plating and remain very easy to read.  

## FINAL GITHUB UPDATE:

With the announcement of GitHub's new mandatory 2FA policy and other weirdness around GitHub in general, I've decided that
instead of just having the documentation on my website, the whole project will be moving to [my personal website](https://johnalex.co/garter).
I'm planning to do some [YouTube videos](https://youtube.com/@garterlang) showing parts of the self-hosting process,
showing how to use the language,
and of course announcing when it becomes available to download / try online.

## LANGUAGE HIGHLIGHTS:

- language balances high-level control flow and simple syntax with source still being very close to how it compiles and runs
- partially semantic whitespacing like Python; allows use of mixed spaces and tabs, and ignores indentation past the beginning of the line
- supports pointers and pointer arithmetic without using special types
- very small cross-platform standard library
- produces extremely small assembly or binary files with an extremely minimal runtime
- type system can be extended using structs and macros
- can transpile and be linked into assembly or C

