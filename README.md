# garter
A self-hosted, compiled, object-based language with high-level simple syntax and low-level control.

### Where is the Source?
Until the 0.0.0 version is complete, no code is going to uploaded to this repo. 
I'm doing this to keep this repo as clean and organized as possible. 
Once it is complete, though, everything is going to be transfered over from my private repo to this public one.

### Installation
Requirements:
- [node.js](https://nodejs.org/) (recommended: v16.14.2)
- [pkg](https://www.npmjs.com/package/pkg) (recommended: 5.6.0)

Building Garter (Automated):
1. Download this repo [by either clicking here](https://github.com/JohnAlexCO/garter/archive/refs/heads/main.zip) or clicking the **Code** button and selecting "Download ZIP"
2. Unzip the downloaded repo and run the installer associated with your machine: `install-linux`, `install-mac`, or `install-windows.exe`. 
This will open a command prompt/terminal that will ask where you want Garter to be installed, 
if you'd like Garter to be the default program to open `*.gy` files,
and if you'd like Garter to be added to your `$PATH`
(meaning it can be run as a command in your terminal)

Building Garter (using Node):
1. Download this repo like before
2. Unzip and navigate to `/src/jarter`
3. Run `node jarter.js garter.gy`. It will compile `garter-linux`, `garter-mac`, and `garter-windows.exe` executables
4. **OPTIONAL &ndash;** if you'd like Garter to be installed globally,
move the compiled Garter program to wherever you'd like it to stay permanently, and then add that location to your `$PATH`.
[(Linux)](https://www.howtogeek.com/658904/how-to-add-a-directory-to-your-path-in-linux/) 
[(Windows)](https://helpdeskgeek.com/windows-10/add-windows-path-environment-variable/) 
[(MacOS)](https://wpbeaches.com/how-to-add-to-the-shell-path-in-macos-using-terminal/)
