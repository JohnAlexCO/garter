# Language Comparisons

_This page is not intended to be comprehensive,
and some of the statements are open to interpretation;
the goal of this page is to give a generalized description
of how Garter compares to other major langauges,
not to act as a complete or objective technical reference._

## Build and Resource Information 
|  | Memory|Compiler Size |Binary Size | Speed|Cold Start|
|:-|:-:    |:-:           |:-:         |:-:   |:-:|
|Garter|Good*|51KB*|Minimal|Best|Best|
|Assembly|Best|3.4MB|Minimal|Best|Best|
|C|Good|700KB|Par|Good|Good|
|Cpp|Good|900KB|Par|Good|Good|
|C#|Par|30MB*|Par|Good|Subpar|
|ECMA|Poor|71MB|Subpar|Par|Subpar|
|Lua|Subpar|700KB|Par|Poor|Par|
|Nim|Good|713MB|Good|Good|Good|
|Python|Poor|150MB|Good|Par|Par|
|Ruby|Poor|20MB|Subpar|Poor|Subpar|
|Rust|Par|1GB|Poor|Good|Par|
|Zig|Good|271MB|Best|Good|Good|

\* Garter uses a greedy algorithm for allocating 
and managing memory that suffers during long runtimes
if the size of memory changes often
<br>
\** Garter's listed size is an estimate based on current implementation roadmap
\*** C# Compiler size based on clone data from a friend at Microsoft. If it's incorrect, uh. idk bro that's wild

## Low Level Features 
|  | Pointers|Mem. Safety|Registers|Data Mutability|C or ASM Embedding|
|:-|:-:      |:-:        |:-:      |:-:            |:-:               |
|Garter|	✔️ | |✔️|✔️|*|
|Assembly|	✔️ | |✔️|✔️|✔️|
|C|			✔️| | |✔️|✔️|
|Cpp|		✔️| | |✔️|✔️|
|C#|		* |✔️|| | |
|ECMA|		  |✔️|| | |
|Lua|		* |✔️| | |✔️|
|Nim|		  |✔️| | |✔️|
|Python|	  |✔️| | |*|
|Ruby|		  |✔️||||
|Rust|		✔️|✔| | |✔️|
|Zig|		✔️|✔️ | |✔️|✔️|

\* can be done without extending the language, but is not a builtin feature
<br>
\** while some languages have mutable types,
if they are not not all mutable, they aren't counted here	

## High Level Features
|  | Macros|Garbage Collection|Typedef|Inheritence|Anonymous Functions** |
|:-|:-:    |:-:               |:-:    |:-:        |:-:                   |
|Garter|		✔️ | |*|*|✔️|
|Assembly|	✔️|| | |✔️|
|C|			✔️ | |✔️ | |✔️|
|Cpp|		✔️|*|✔️ | |✔️|
|C#|		✔️|✔️|✔️|✔️|✔️|
|ECMA|		*|✔️|✔️|✔️|✔️|
|Lua|		✔️|✔️|*|*|✔️|
|Nim|		✔️|✔️|✔️|✔️|✔️|
|Python|	*|✔️|✔️|✔️||
|Ruby|		✔️|✔️|✔️|✔️|✔️|
|Rust|		✔️ | |✔️ | |✔️|
|Zig|		 ||✔️ | |✔️|

\* can be done without extending the language, but is not a builtin feature
<br>
\** specifically Multiline Anonymous functions, not inlined Lambdas


## Syntax and Style Differences 

| | Structured|Paradigm* |Inferred|Dynamic|Enveloping|Verbosity*|
|:-|:-:|:-:|:-:|:-:|:-:|:-:|
|Garter|Optional|Flexible|Yes|Yes|Whitespaced|Minimal|
|Assembly|No|Imperative|No|No||Verbose|
|C|Yes|Imperative|No|No|Braces|Moderate|
|Cpp|Yes|Imperative|Yes|No|Braces|Moderate|
|C#|Yes|Declarative|Yes|No?|Braces|Verbose|
|ECMA|Yes|Declarative|Yes|Yes|Braces|Low|
|Lua|Yes|Declarative|Yes|Yes|Blocks|Moderate|
|Nim|Yes|Declarative|Yes|No|Braces|Low|
|Python|Yes|Declarative|Yes|Yes|Whitespaced|Low|
|Ruby|Yes|Declarative|Yes|Yes|Blocks|Low|
|Rust|Yes|Imperative|Yes|No|Braces|Verbose|
|Zig|Yes|Imperative|Yes|No|Braces|Moderate|

\* Generalizations based on codebases I've seen;
a lot of these languages I don't have real personal
experience with, but I tried to do research on them all.

<!--
	https://en.wikipedia.org/wiki/Comparison_of_programming_languages_(syntax)
	https://en.wikipedia.org/wiki/List_of_programming_languages_by_type

	 | Small Binaries|< 200 KB|9 MB|23 MB|1 MB|23MB|6 KB |
	Compiler and/or binary sizes:<br>
	[Lua](https://www.bmc.com/blogs/lua-programming-language/#:~:text=Size,Lua%20library%20takes%20only%20466K.)
	[Ruby](https://www.ruby-lang.org/en/downloads/)
	cython [1](https://github.com/cython/cython/issues/2102) [2](https://obrunet.github.io/pythonic%20ideas/compilation_cython/)
	nexe [1](https://github.com/nexe/nexe/issues/621)
	rubypacker [1](https://nts.strzibny.name/making-a-ruby-executable-with-ruby-packer/)
	nim [1](https://hookrace.net/blog/nim-binary-size/)
	cpp[1](https://levelup.gitconnected.com/comparing-programming-language-efficiency-in-4-programming-languages-timing-selection-sort-29badc8a744f?gi=4871ec3b333b)
	[2](https://www.ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html)
	c# [1](https://visualstudio.microsoft.com/downloads/) 
	[2](https://medium.com/@MStrehovsky/building-a-self-contained-game-in-c-under-8-kilobytes-74c3cf60ea04)
	[3](https://www.mono-project.com/docs/about-mono/languages/csharp/)

	Benchmarks:<br>
	JavaScript v Ruby [1](https://www.educba.com/javascript-vs-ruby/) [2](https://programming-language-benchmarks.vercel.app/ruby-vs-javascript)
	JavaScript v Lua [1](https://programming-language-benchmarks.vercel.app/lua-vs-javascript)
	nim v rust [1](https://programming-language-benchmarks.vercel.app/nim-vs-rust)
	zig [1](https://programming-language-benchmarks.vercel.app/zig)
	c# v python [1](https://programming-language-benchmarks.vercel.app/csharp-vs-python)
-->
