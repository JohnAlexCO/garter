<h1 align="center">
	<img src="./logo/blocky_snake.png" height="160px"/><br>
	Garter, by JohnAlex.CO
</h1>

# Language Description

Garter is a compiled/interpreted language with minimal syntax, symbols, and rules.
Its simultaneously simpler than C and as low-level as machine code, while also including macros and being as high-level as Python.
It's both a language that allows very quick prototyping and learning, but also allows incredible power and direct control.
Garter is in short a **High-Level Assembly language**.

**NOTE**: in this documentation and elsewhere, *Garter* refers to the language itself, and *garter* refers to the implementation as an interpreter/compiler.

# Language Specification

Until the 0.0.0 version of garter is available, I don't want to be overly specific about implementation details.
*See Below Section "Where is the Source?" for further reading.* 
I've included some very basic pseudocode here to show what Garter looks like,
and when garter has been bootstrapped, full documentation as well as tutorials will be available from
my personal website at [johnalex.co/garter](https://johnalex.co/garter), as well as here on my GitHub.
```python
func *length string
    len = 0
    *while string.len
        len++
    *return len
```

```python
markdown = *import 'https://johnalex.co/gib/?package=markdown'
a = dict: tag 'h1' content x
    tag 'p' content 'Hello, World!'
page = markdown.render(a)
*print(page)
#>> "<h1><p>Hello, World!</p></h1>"
*print *string(a), *string(x)
#>> {tag: 'h1', content: [Object x]} {tag: 'p', content: 'Hello, World!'}
```

# Building a Language 
### The Pieces
A *transpiler* that takes some subset of Garter and ports it to code in another language,<br>
[gasm](https://github.com/johnalexco/gasm), which can assemble low-level `*.gasm` code to machine binary (or a bytecode-machine program),<br>
and [garter](https://github.com/johnalexco/garter) itself, which takes `*.gy` code and compiles it down to `*.gasm`

### Methodology
First, a version of [gasm](https://github.com/johnalexco/gasm)
is written that can take `*.gasm` programs and build a machine application. *See the gasm repository for more information.*
Then a transpiler is written; it only needs to be able to handle such a subset of Garter that a proper interpreter/compiler can be built up from it.
Finally, the bootstrapping process begins. garter is written in Garter and fed into the transpiler, creating `boot.js`.
That same code is fed back into `boot.js` to be compiled into the self-hosted version, garter.
The compilation stage should target the `*.gasm` microlanguage, and gasm should be used to build the actual executables.

### Why Two Languages?
The reason I elected to write a second, smaller language primarily came down to the desire to be able to compile to assembly, 
as languages like C do, while still having assembly code that's target-ambivalent, easy to transpile or interpret, and easily human-writable too.
I wanted a compile target that is less abstract than Assembly -- more like an actual machine language -- while also easier to read and write.
Thus, [gasm](https://github.com/johnalexco/gasm), the Garter ASM was born.
Instead of necessarily needing to re-write garter in lots of languages to port it, 
only gasm has to be re-written, and then one implementation of Garter in gasm allows compiling native versions of garter on any machine. 

### Where is the Source? 
Until the 0.0.0 version is released, **no downloads or source will be available**
Once the self-hosted version of this language is built, I will be uploading its source to this repository with build instructions,
as well as uploading releases for Linux, MacOS, and Windows, as well as adding an Interpreter/REPL to my personal website.
I also intend to upload some YouTube videos of the bootstrapping process very soon to my personal channel.

### Installation

No install is available yet. See above
<!-- https://github.com/JohnAlexCO/garter/archive/refs/heads/main.zip -->

<!--
Building Garter:
- Requires [node.js](https://nodejs.org/) (recommended: v16.14.2)

1. Download the source [by clicking here](https://github.com/JohnAlexCO/garter/archive/refs/heads/main.zip)

2. Unzip and navigate to `/src/jarter`

3. Run `node jarter.js garter.gy`. It will compile `garter-linux`, `garter-mac`, and `garter-windows.exe` executables

4. **OPTIONAL &ndash;** if you'd like Garter to be installed globally,
move the compiled Garter program to wherever you'd like it to stay permanently, and then add that location to your `$PATH`.
[(Linux)](https://www.howtogeek.com/658904/how-to-add-a-directory-to-your-path-in-linux/) 
[(Windows)](https://helpdeskgeek.com/windows-10/add-windows-path-environment-variable/) 
[(MacOS)](https://wpbeaches.com/how-to-add-to-the-shell-path-in-macos-using-terminal/)
-->
*More of my work is available at <a href="https://JohnAlex.CO">JohnAlex.CO</a>*




