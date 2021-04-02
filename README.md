# libll

A simple double linked-list implementation for c. libll aims to be a small
yet comprehensive library. Occassionally new operations will be added to the
library. One good feature of libll is the ability to have linked-lists of
multiple types, as you might see in higher level languages
(there're more, see ***Cool Features*** below).

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

## Examples

For examples on how to use libll, look in the `examples` directory and
EXAMPLES.md

## Contributing

libll is very straight-forward, so developing should be easy. To keep things
clean and consistant, libll should be formatted with clang-format using the
Google style. Also, libll uses [MinUnit](https://github.com/siu/minunit) for
tests.

## Bindings

libll has some bindings for other languages. Here is a list of the bindings
availble for libll (to add more, please submit a pull request):
* C++: libll (obviously)
* Golang: [goll](https://github.com/michaelfm1211/goll)

## License

libll is licensed under the MIT license. See LICENSE.txt for more information
