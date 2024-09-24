# Garter

is an in-development programming language heavily influenced by
DarkBasic, x86 Assembly, JavaScript, Python, and C
and built from the ground-up on its own tooling and compiler toolchain

## Update (September 24, 2024)

Getting closer to having my prerelease, just finished moving so it's been a bit
but I just refactored a lot of the internals to make it a better _toolchain_.
If you're interested, I have info over on my website about
[how the toolchain works](https://modula.dev/design),
and the first pre-0.0.0 release is basically gonna look like
```
garter
  ↳ data
    ↳ locale
    ↳ assets
  ↳ cli
    ↳ args
    ↳ daisy
  ↳ frontends
    ↳ garter-gy24
      ↳ gasm
      ↳ garter
  ↳ backends
    ↳ gyb
      ↳ linker
      ↳ disassembler
    ↳ emitters
      ↳ linux
        ↳ x86 (32-bit)
      ↳ windows
      ↳ macos
      ↳ c-lang
        ↳ 64-bit
        ↳ 32-bit
  ↳ shared
    ↳ symtables
    ↳ string
    ↳ file i/o
    ↳ error and tui functions
```


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

## Implementation

Garter is being written entirely in 
[gasm](https://github.com/JohnAlex.CO/gasm)(_Garter Assembly_)
by the combination of hand-written code and using C helper functions.
Once `garter.gasm` is written, it will be compiled to 
executable binaries for 64-bit Windows, Linux, and MacOS,
as well a bytecode file that can be run in 
[gyb](https://github.com/JohnAlexCO/gyb).

## Resources

__NOTE:__ There's a bug in the currently running version of [Weaver](https://modula.dev/weaver)
that is causing the `/garter` route that because certain browsers automagically add a `/` to
the end of the uri, and because of a small error in how uris are interally cast in the library,
causes an interal service error. If you navigate instead of `/garter?somequery`,
or just to `/documentation` instead, the pages should work correctly.
__I do plan to fix the bug in Weaver sometime soon, but finishing the assembler is my priority right now__.

- [Garter Website](https://modula.dev/garter)
- [YouTube Devlog](https://www.youtube.com/@moduladev)

## Licensing 

This project will be adopting a hybrid licensing model. The main project will ship with a Contributor License Agreement and the AGPLv3. 
Additional materials and extensions will be available under a proprietary End-User License Agreement which stipulates that modifications to the language implementation must be made publicly available under the CLA and AGPL licenses.
Usage of Garter's name and branding are permitted as long as they do not imply an endorsement by Modula or its contributors.

[ ![Unlicense logo](https://unlicense.org/pd-icon.png) ](https://www.unlicense.org/)
[ ![GNU Affero License Logo](https://www.gnu.org/graphics/agplv3-with-text-162x68.png) ](https://www.gnu.org/licenses/agpl-3.0.html)

[Modula © 2024, All Rights Reserved](https://modula.dev)
