<h1 align="center">
	<img src="./blocky_snake.png" height="160px"/><br>
	Garter, Icon Conventions
</h1>

### Measurements and Definitions
```
h = length andor width of whole document; should be square
	"Tier" = h/3
	"Row" = h/5
	"Layer" = h/9 
	"Bold" = h/50
```
When definition a shape or point, it is always x, then y
For coordinates, 0 is top and left.
```
Red = #f00;
Gray = #404040 or #444;
White = #fff;
Yellow = Paint.NET Yellow, #FFD800;
```
 ### Instructions for Recreation
 
The Body

> The head is a five-point polygon, snapped to `row`+`layer` on x and `tier` on y
the two other body-parts are perfect rectangles
The each part has a height of one `Tier`
They all have a `Black` border of `Bold` thickness
and their backgrounds are all `Gray`.
Nothing may appear over the border, or outside of it.

The yellow stripes

> The stripes are all bottom-aligned to `tier` and fill the `x` axis.
> They are each one `layer` tall and filled `Yellow` with no border.

The white body stripes
> These are all x-aligned to `layer` and y-aligned to `tier` at the tops.
> They are each one `layer` wide, one `tier` tall, and filled with `White` with no border.
> They are placed at: (`4*layer`, `tier`) (`6*layer`, `tier`) (`2*layer`, `2*tier`) (`5*layer`, `2*tier`) (`7*layer`, `tier`)

The red bodystripes
> These triangles are of size `2*layer`, `layer` and point upwards with a red fill.
> They repeat filling the x-axis at heights `4*layer` and `7*layer`.
> The pattern at height `4*layer` should be x-offset by `layer*0.5` for effect

The white headstripe
> The head-stripe is at the very top, is of `Bold` height, fills the x-axis, and has a `White` fill.

The Eye
> The eye is a black dot of radius `Bold*2` centered at `3*layer`,`1*layer`
