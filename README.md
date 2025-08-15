satori's TinyWM
===============
this is a "fork" of nick welch's TinyWM, suited to my tastes.

files
-----
- `Makefile`:    highly advanced build system
- `tinywm.c`:    the code
- `config.h`:    macro redefinition (optional)
- `annotated.c`: nuked from orbit
- `tinywm.py`:   vanished into the aether

configuring
-----------
TinyWM is configured by editing its source code. in this way, configuring of
the program is indistinguishable from modification. however, some internal
macros can be redefined in the optional file `config.h`, as such:

    $ cat > config.h << .
    #undef MOD_KEY
    #define MOD_KEY Mod4Mask
    .
    $ make

if `config.h` does not exist, `make` will create it before compilation. macros
should be undefined before defining them again, but the default compilation
flags do not enforce this.

acknowledgements; license
-------------------------
as from the original `README`:
> TinyWM is written by Nick Welch <nick@incise.org> in 2005 & 2011.  
> This software is in the public domain
> and is provided AS IS, with NO WARRANTY.

> Another very small window manager is failsafewm. Originally I started
> hacking on it, as there was quite a bit of stuff in it that I thought was
> unneeded. I wound up rewriting it from scratch, with just the bare
> necessities, and that became TinyWM.
>
>    http://freshmeat.net/projects/failsafewm/

> Yet another small -- but in comparison to TinyWM, big -- window manager is
> aewm.  It's a good example for learning about writing a window manager.
>
>    http://www.red-bean.com/~decklin/aewm/
