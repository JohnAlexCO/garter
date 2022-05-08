## tl;dr
  <strong>An in-development compiled, object-based language
	with high-level simple syntax, 
	low-level control,
	and extreme portability.</strong>

## Language Description

Garter is 
[inferred](https://en.wikipedia.org/wiki/Type_inference), 
[nominal](https://en.wikipedia.org/wiki/Nominal_type_system), 
[dynamically](https://en.wikipedia.org/wiki/Dynamic_programming_language) typed programming language. 
All data-types can be directly stated and are static,
but objects can be reassigned and act dynamically.
It's is free of lots of arbitrary symbols and 
["sugar" rules](https://en.wikipedia.org/wiki/Syntactic_sugar),
so that it can be

1. quickly learned

2. easily understood on a low-level while retaining high-level functionality and syntax 

3. relatively quickly implemented, and 

4. easily translated into machine code or virtualized

Everything from functions to declarations have been built up
from *as few necessary pieces as possible* to make it as 
intuitive and easy to write or read as possible 
while still offering all the power of other high-level languages.

Garter is intended to be general-purpose,
with particular focus and optimization for building
applications such as games, websites, and devtools.
On top of being able to be interpreted 
or compiled directly to binary,
the standard library inclues markdown support and functions to
render and serve entire modules as dynamic web-pages.

## Where is the Source?
Until the 0.0.0 version is released, **no downloads or source will be available**
Once the unstable alpha release is available, 
tutorials, documentation, and showcases will all be available here,
as well as a quick-guide for installing Garter.

### Installation

Installing Garter (Automated):

1. Download the source [by clicking here](https://github.com/JohnAlexCO/garter/archive/refs/heads/main.zip)

2. Unzip the downloaded repo and run the installer associated with your machine: `install-linux`, `install-mac`, or `install-windows.exe`. 
This will open a command prompt/terminal that will ask where you want Garter to be installed, 
if you'd like Garter to be the default program to open `*.gy` files,
and if you'd like Garter to be added to your `$PATH`
(meaning it can be run as a command in your terminal)

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

*More of my work is available at <a href="https://JohnAlex.CO">JohnAlex.CO</a>*




