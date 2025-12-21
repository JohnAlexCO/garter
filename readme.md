<a href="https://github.com/BloodRoseorg/Garter" style="margin: auto; text-align: center">
    <img src="https://bloodrose.org/garter.png" height="200px"/>
    <h1>Garter</h1>
</a>

A high-level & low-level programming language
intended to bridge the gaps between things like ANSI-C and Python
with an extremely lightweight (dare I say, apocalypse-proof) implementation.
It is both a "systems programming language" with manual control over memory,
and a high-level language intended for things like game development
with some _light_ metaprogramming features.

# **Current Project State**

As it currently stands,
Garter has a _design_ but no implementation;
it is waiting for the [Garter Assembler](https://github.com/BloodRoseorg/Gasm) to be bootstrapped.
However, this project _is still being worked on_,
I just have not updated the repo with things like my notes and plans in a while
because I did not want to spam people who have starred the repo with notifications.

That noted, the code currently in this commit
_is going to be refactored, replaced, or even erased_.
It is going to look much more like the
[`gasm/mini`](https://github.com/BloodRoseorg/Gasm/tree/mini) branch
of the assembler's tree after refactor.

The notes and documentation in this commit, however, are current.

# Language Overview

> For specific documentation on the language's syntax,
> see [the docs](./assets/docs.md)

To get the fun jargon out of the way:
Garter is a 
[procedural](https://en.wikipedia.org/wiki/Procedural_programming),
[static](https://en.wikipedia.org/wiki/Type_system#Static_typing), 
[manifest](https://en.wikipedia.org/wiki/Manifest_typing)
and strongly-typed language
that has many of the _features_ of dynamically typed languages.
The binaries it produces are always _statically compiled_;
it does not link against or depend on things like the C-standard library.

Some important highlights:

- It is able to cross-compile for **MacOS** 
without needing any 3rd party software such as `xcode` \*

- It has a very lightweight plain-English syntax (frontends for other languages planned)
which doesn't involve blocks of symbols like `::` or `<>`

- Regular code allocates memory using the stack at runtime,
meaning most Garter programs does not need rely on or mess with memory allocators

- It bundles useful cross-platform libraries for common tasks like graphics,
user input, and data manipulation

- Garter has both `types` and `classes` which together
make abstracting data manipulation very simple and transparent

- Code and instructions very tightly relate to the real machine code output,
unlike most other languages even including C

- The standard libraries are, quite literally, just single-file headers
that get bundled with the compiler

> \* The MacOS backend is not included in the main project;
it will be available as a drop-in extension

# Design Tenants

1. Before all else, keep it simple.
2. All data are numbers. All variables are pointers. Nothing is special.
3. Types and Classes simple interfaces and wrappers who minimize syntax
5. While this is not a memory safe language, it should be very easy to write code that does not touch its unsafe features

# Where are our Black Boxes?

The compiler, itself, must implement the following;

- Logic for calling functions and returning values
- The arithmatic stack
- Methods for pointers, integers, and floating point primitives

For the mostpart, everything else can just be defined in the code

# Building from Scratch

The process has exactly three external dependencies;

1. A 32-bit or 64-bit Linux system with x86-32 support \*
2. A C99-compiler such as `clang`, `gcc`, `tcc`, `chibicc`, ...
3. The [Garter Assembler](https://github.com/BloodRoseorg/Gasm)

> [!NOTE] Systems with a Linux compatibility layer,
> such and `WSL` on Windows or `Linuxulator` on BSDs are also suitable

A bootstrapping assembler and compiler are built,
then they're directed to compile and assemble self-hosting versions of themselves.
Once the self-hosting compiler and assembler are built,
they can be used to output binaries for other systems,
but the bootstrapping toolchain is made to be extremely limited
to minimize its surface area.

The entire process looks something like
```sh
#   Fetch the code
git clone https://github.com/BloodRoseorg/Gasm
git clone https://github.com/BloodRoseorg/Garter

#   Build the Bootstrappers
cd ./gasm && ./build
cd ../garter && ./build

#   Build the Self-Hosted Compiler and Assembler
./gasm/gasm -o gasm ./gasm/selfhost/org.asm
./garter/garter -o garter ./garter/selfhost/org.gy

# Copy them somewhere in the system $PATH
cp ./gasm/gasm ./garter/garter ~/.local/bin/
```

# License

Garter is made available under a permissive four-clause license
that restricts commercial redistribution of the source code and compiled binaries.
Regular users and organizations compiling _their own code_ with Garter
should not require any special licenses.
Please reach out to [Blood Rose](https://bloodrose.org) directly
if you do need to attain a commercial license.

The Garter Logo is **_All Rights Reserved &copy; Blood Rose_**.
Please do not use this logo to imply endorsement by or association
with the Garter project, its contributors, or Blood Rose.

# Contributors 

John Alex 2024-Present, [Project Lead](https://bloodrose.org)
