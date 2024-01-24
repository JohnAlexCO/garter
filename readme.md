# Garter

is an in-development programming language heavily influenced by
DarkBasic, x86 Assembly, JavaScript, Python, and C
and built from the ground-up on its own tooling and compiler toolchain.

## What's Included

Out of the box, Garter provides a compiler toolchain
[(compiler)](https://github.com/JohnAlexCO/garter)
[(assembler)](https://github.com/JohnAlexCO/gasm)
[(interpreter)](https://github.com/JohnAlexCO/gyb), 
and a lightweight standard library comparable to glibc.
_Eventually_ Garter will also include additional libraries, 
a [language server](https://github.com/JohnAlexCO/gyls), 
and a [package manager](https://github.com/JohnAlexCO/gib).
Documentation will also be available over at [Modula.dev](https://modula.dev/garter)

## Installation

Garter will be available as standalone binaries for 
64-bit Windows, Linux, and MacOS. 
For major versions, I plan to also make binaries for 
[FreeBSD](https://www.freebsd.org/) and
[ravynOS](https://ravynos.com/).

To build Garter from source, you'll need 
[gasm](https://github.com/JohnAlex.CO/gasm), 
and if you're building `gasm` from source,
you'll also need 
[gyb](https://github.com/JohnAlexCO/gyb).
From there, building Garter look something like:
```
gyb -v && gasm -v
> gyb 0.0.0
> gasm 0.0.0
gasm garter.gasm garter
> "garter" assembled as Linux ELF in 33kiB
./garter -v
> garter 0.0.0
```

## Implementation

Garter is being written entirely in 
[gasm](https://github.com/JohnAlex.CO/gasm)(_Garter Assembly_)
by the combination of hand-written code and using C helper functions.
Once `garter.gasm` is written, it will be compiled to 
executable binaries for 64-bit Windows, Linux, and MacOS,
as well a bytecode file that can be run in 
[gyb](https://github.com/JohnAlexCO/gyb).

## Resources

- [Garter Website](https://modula.dev/garter)
- [YouTube Devlog](https://www.youtube.com/@moduladev)

## Licensing 

This project will be adopting a hybrid licensing model. The main project will ship with a Contributor License Agreement and the AGPLv3.2. All of the language's documentation will be under the Unlicense.
Additional materials and extensions will be available under a proprietary End-User License Agreement which stipulates that modifications to the language implementation must be made publicly available under the CLA and AGPL licenses.
Usage of Garter's name and branding are permitted as long as they do not imply an endorsement by Modula or its contributors.

[ ![Unlicense logo](https://unlicense.org/pd-icon.png) ](https://www.unlicense.org/)
[ ![GNU Affero License Logo](https://www.gnu.org/graphics/agplv3-with-text-162x68.png) ](https://www.gnu.org/licenses/agpl-3.0.html)

Modula.dev © JohnAlex.CO 2024