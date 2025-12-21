<a href="https://github.com/BloodRoseorg/Garter" style="margin: auto; text-align: center">
    <img src="https://bloodrose.org/garter.png" height="200px"/>
    <h1>Garter &ndash; Documentation</h1>
</a>

Garter's syntax is very plain and minimal.
A few notes on that; 
- commas are just whitespace and can go anywhere they make the code pretty,
but future linters should complain if you put them in the middle of statements
- `()`, `{}`, and `[]` are all interchangable and in some contexts can be omitted,
- besides basic arithmatic `+-*/%.`, bitwise `<>&|^`, address `@`, and assignment `=:`, special symbols are not used in the Garter language; they are also not used outside of these contexts

# Full Documentation

_TODO: Table of contents listing links to pages on_
_specific functions, keywords, and some tutorials_

# Variables are Pointers

Declaring variables in Garter is very simple.
Declare the type, give them a name,
and that becomes a "variable".

```go
int x               // a void int; it is not assigned to anything
```
Once a name is defined, there's two ways we can manipulate it

- `=`, "assignment", tells the compiler to overwrite the _value_ of the variable
- `:` "redefinition", tells the compiler to change the _definition_ of a variable
(to somewhere else in memory)

```go
x: new int          // x becomes "an int allocated in our stack frame"
x = 0xf00bad        // and its value gets overwritten
```

**"Do I have to define all my variables like that? That seems tedious"**

Of course not, silly! `new` is a compiler macro 
(this will get elaborated on later), and it allows the much prettier syntax
```go
new int x 500       // assign a named variable with the given value
```
Which magically unrolls into something like this at compile time
```go
int x               // define a variable
x: new int          // allocate it space and bind it
x = 500             // assign a value to it
```

## Arrays

Arrays of data are allocated and defined with the same syntax,
but with more _stuff_ after the first data-point
```go
new char name "Hello, world"
```
The "string" is an array of characters;
`new` allocates space for them and copies their data in,
then points `name` to the beginning of the character data.

All variables in Garter are just pointers, and pointers can be indexed.
**Any** variable can be indexed with the `.` index postfix operator.
This means that all variables are _also_ raw, unsafe arrays under the hood,
and bounds-checked, safe arrays should be preferred to raw indexing.

```go
new char hello "Hello, World!"
print hello.7           // prints "World!"
```


## Memory Allocation, `new`, and `return`

**"How exactly does `new` work??"**

It's a macro over a function which returns a pointer.
That's really all there is to it,
and that's why you can do something like `name: new someType`.
The size of the data is resolved at compile-time,
room gets allocated in the current stack-frame,
and data gets copied into the newly created _thing_.

If `new` is invoked with just a type,
it simply allocates space and returns a pointer.

But if it's invoked with a type and a name (and optionally a value),
then it unrolls to allocate space, declare the name, bind it, and assign the value.

**"And how do we get that memory? What happens to it when we return something?"**

Garter keeps the full contents of variables within the stack frame,
and when we `return` a variable, the data is 
[flattened](https://en.wikipedia.org/wiki/Serialization)
and adopted into the previous scope.
Because of this, we can write code 
without needing a special memory allocator like C's `malloc`, 
without needing a garbage collector like many other high-level languages,
while still keeping memory tidy and a low profile.

That noted, Garter has nothing _against_ memory allocators;
things like `malloc`, arena allocators, and garbage collected memory
are all allowed, they are simply not part of the language core itself.
Garter's standard library _does_ include a simple bump-allocator as well.

# Functions and Dependency Injection

The `fn` keyword is how we define and assign function implementations;
it's followed by the name of the function, type the function returns,
then optionally the arguments it accepts.
If it returns nothing, it should be `void` typed.
If it accepts no arguments, its arguments should be `void`, not empty

If a function is _not_ followed by the function's implementation,
then it is called a _function prototype_ and only defines the function signature.

```go
fn foo int ( char baz ) // Function signature, no implementation body
```

The keyword `void` is reserved, and used in function definitions
to mean "nothing at all", like in cases where a function
literally does not return anything or accepts no arguments

Functions calls and return procedures are _inlined_
because it's intuitive, it's simpler to implement, and it's efficient.
However, where it does become a bit complicated is **function pointers**.
We still want to be able to use runtime-defined addresses
so we can do things like dynamic loading and
[dependency injection](https://en.wikipedia.org/wiki/Dependency_injection).

We can call variables like functions
if their type defines a `call` method,
but that's not really what we're looking for here.
We want to tell the compiler,
"this variable contains an address, 
and I want to call it like a function with _this_ signature"

We can reuse the `fn` keyword but re-arrange the arguments;
if we put the signature first and **then** the name,
the compiler knows we are casting something as a function.
```go
fn bar int (int f, int i, char c) {
    // a function taking int and char, returning int
    fn (int, int char) x: f // define function x as being at f
    return x (i, c)
}
```
Function casting can get a little messy, but have no fear!
We can use the keyword `proto` as a shorthand for
"use this function's interface here"
```go
fn bar int (int f, int i, char c) {
    fn (proto knownFunction) x: f
    return x (i, c)
}
```
> [!NOTE] `proto` is a macro expansion,
> and is technically legal within the definition of a function,
> but its use in that context is strongly discouraged.
> Linters should complain or perhaps even explode on sight


# Types and Classes

As alluded to before, `type` and `class` are two separate
but tightly related concepts in Garter.
A `type` is the underlying organization of its memory,
and a `class` is the methods and interfaces that manipulate that memory.

There are a few helpful compile-time macros
which we can use to help define our types and classes, too,
such as `sizeof` (works the same as in C)

## Types

We define a type with the `type` keyword, followed by the name
and the chronological order of the named data it contains.
If a named field should be an _array_ of data instead of a single unit,
we can put a number after the name for _how many entries_

```go
type album {
    int uuid
    char artist     16
    char name       16
}
```

## Classes

Similar to type definitions,
we define a class with the `class` keyword, followed by the name
and then a list of methods which act upon it.
Some class names are pre-defined and have specific purposes,
and some are _required_ for a class to be valid.

The `new` function is not expected to return anything;
it accepts an option pointer to an instance to copy,
and address to copy itself to.
The amount of space allocated by default
is the size of the underlying type.

The `size` function accepts a reference to `self`,
and returns `int` of how much room is currently being used up by it

And the `flatten` function accepts a reference to `self` 
and returns a serialized version of itself

> [!NOTE] Classes need to be defined _after_ the underlying type they interface
> since the `new` method depends on the type's definition

```go
class album {
    fn new album        ( album source ) { 
        album self
        memcpy(self, source, sizeof(album))
        return self 
    }
    fn size int         ( album source ) { return sizeof(album) }
    fn flatten album    ( album source ) { return source }
}
```
The above example is a fixed-size, so its methods aren't super complicated,
but things like dynamic arrays, hashmaps, and iterators
might have much more complex definitions.

And **yes**, methods within a class can also be prototyped and defined later,
just like functions can.

## List of Common Method Names

In the given table, "self" refers to the instance, 
"kind" refers to the type being implemented.
Methods marked with \* are mandatory for all classes

\*\* If _assign_ is not defined, then the default compiler behavior
is to basically just `memcpy(self, other, sizeof(kind))`

| Name      | Returns | Accepts     | Description |
|--         |--       |--           |-- |
| new \*    | kind    | kind        | create a _kind_ and return it |
| size \*   | int     | kind        | return amount of memory used up by _self_ |
| flatten \*| kind    | kind        | return a serialized / continuous _self_ |
| assign \*\*|kind    | kind, kind  | assigns the value of another _kind_ to _self_ |
| string    | char    | kind        | return a string representation of _self_ |
| int       | int     | kind        | return an integer-cast of _self_ |
| float     | float   | kind        | return a float-cast of _self_ |
| add       | kind    | kind, kind  | perform addition between two of _self_ |
| sub       | kind    | kind, kind  | perform subtraction between two of _self_ |
| mul       | kind    | kind, kind  | perform multiplication between two of _self_ |
| div       | kind    | kind, kind  | perform division between two of _self_ |
| modulo    | kind    | kind, kind  | perform modulo division between two of _self_ |
| ...       |         |             | _other arithmetic, bitwise, logical, et al_ |


## Under the Hood

During compilation, the compiler has a note 
associating each variable to a type,
and the assembly code it emits, the inline function calls and such,
are determined by those type notes.

The `class` definition associated with the type
tells the compiler how (and if) we can, for example,
add two `album`-type together.
And when we _cast_ a variable to a type,
really we're just updating that note to the compiler.

There's no runtime magic going on here,
this stuff is resolved at compilation time and inlined.

# Data Types

Without any standard libraries,
the compiler itself defines the "primitive" types
and many useful methods for interfacing with them.

### Numbers

- Unsigned integers: `u8` `u16` `u32` `u64`
- Signed integers: `i8` `i16` `i32` `i64`
- Floating point: `f32` `f64`
<br>

**Aliases**

- `char`, `byte`, `word`, `short`, and `long`
are all unsigned and fixed in size
- `uint`, `int`, and `float` use the architecture default size,
like 64-bit on 64-bit systems
- `float` uses the architecture default size
- `single` and `double` are fixed in size

<!--
    TODO
    int address = @variable
    Implementation stuff after each docpage for those interested
    Footer which has related links
-->