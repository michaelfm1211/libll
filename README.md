# libll

A simple double linked-list implementation for c. libll is only suitable for a
one specific purpose, having a list which can be appened too. libll doesn't
have too many features, but enough for simple usage. More operations may come
later, but libll was build to be small and minimal. One good feature of libll
is the ability to have linked-lists of multiple types, as you might see in
higher level languages (there're more, see ***Cool Features*** below).

#### Cool Features
* Python-like negative indexing supported
* `LL_ITER` macro for iterating over a list shorthand
* Linekd-Lists with different types (ie: a list with an `int` and a `bool`)

## Building

libll is only avaible as a static library at this moment, although if you need
a shared library, you could modify the Makefile, as it isn't that complicated.
To build libll, just run `make`, and the rest should be automated! This has so
far only been tested on macOS, but other UNIX-like operating systems should
also work (its so simple, it'll probably work on non-UNIX operating systems
too). Once make is done, you should have `libll.a` in the project root. That's
it! You probably want to move libll.a someone like /usr/local/lib though, or
somehwere else where your linker can find it. Same goes for the header (ll.h)
Also, to keep things clean, you can also run `make clean`.

## Contributing

libll is very straight-forward, so developing should be easy. To keep things
clean and consistant, libll should be formatted with clang-format using the
Google style. Also, libll uses [MinUnit](https://github.com/siu/minunit) for
tests.

## License

libll is licensed under the MIT license. See LICENSE.txt for more information