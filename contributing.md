# Contributor Guide

Please be sure to read the CLA below and the Software License before submitting code.

Before feeling like you have to dive right in,
[Open an Issue](https://github.com/BloodRoseorg/garter/issues)
describing what problem you're interested in fixing or what feature you are adding.
When you're ready to send code back upstream, put `RE #` + your issue number at the beginning of your commit message.
If your issue was #11, then you might

```
git commit -m "RE #11: Tighten loop optimization"
```

## Code Style

We prefer minimal, dry, and interface-based code.
Good code is code that explains what it does.
Function prototypes, type definitions,
and other common interfaces should be hoisted up
towards the top of the file so they are easy to reference.
Implementations go later in the file.

Any code which is platform-specific
should be put behind a platform-specific API layer
so that program logic and architecture details
do not co-mingle too much and muddy the water.

Simple heuristics are preferable to very complex optimized functions.
Code being easy to read, update, and understand for individual readers
is more important than performance (to a degree).

## AI Policy

Please do not contribute AI slop. 
We only serve Human-made slop here.

# Contribution Agreement

All contributions are made under the following
Contributor License Agreement:

```
“Blood Rose” refers to Blood Rose Records, including any projects operated under that name.
By submitting a contribution to this project, I hereby represent and warrant that:

1. I am the owner of the contributed work and I have the right to submit it.
2. I knowingly assign all rights in the contribution, including copyright, to Blood Rose.
3. Blood Rose may use, modify, distribute, sublicense, or relicense the contribution for any purpose, including commercial or proprietary use.
4. I accept responsibility for claims arising from contributions I submit.

Blood Rose, in response, agrees that:

1. The contribution will be made available under the license or licenses in use by the project at the time of submission.
2. The contributor will be credited for their contribution(s).

Blood Rose reserves the right to remove or replace contributions at any time without notice.
```
