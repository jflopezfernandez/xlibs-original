
<h2 align="center">xLibs</h2>

<div align="center">

![GitHub](https://img.shields.io/github/license/jflopezfernandez/xlibs?color=success)
![GitHub tag (latest SemVer)](https://img.shields.io/github/v/tag/jflopezfernandez/xlibs?sort=semver)
![GitHub issues](https://img.shields.io/github/issues/jflopezfernandez/xlibs)
![GitHub pull requests](https://img.shields.io/github/issues-pr/jflopezfernandez/xlibs)
![GitHub last commit](https://img.shields.io/github/last-commit/jflopezfernandez/xlibs?color=success)

</div>

---

<p align="center">
    The xLibs project is a collection of C language extension libraries to increase productivity without sacrificing performance.
    <br />
</p>

## Table of Contents
 - [About](#about)
 - [Libraries](#libraries)
 - [Supported Platforms](#supported_platforms)
 - [Getting Started](#getting_started)
 - [TODO](./TODO.md)
 - [Contributing](./CONTRIBUTING.md)
 - [Authors](#authors)
 - [Acknowledgements](#acknowledgements)
 - [Sources](#sources)

## About <a name = "about"></a>
The aim of this project is to create freely-reusable, free
software library modules that application developers can
leverage to avoid recurring to much more general languages
or libraries, due to the computational- and memory-related
costs which such generality requires.

## Supported Platforms <a name="supported_platforms"></a>
The initial release of the xLibs library modules is targeted
towards Linux machines running on x86-64-compatible
processors.

The project is developed using [gcc][], with some modules
written in assembly language directly and assembled with
[nasm][].

The ideal is to be able to support any platform, as long as
it is capable of compiling valid C programs, and this will
be our goal after the project's initial release.

## Libraries <a name = "librarier"></a>
This project itself comprises several distinct library
modules. At the moment, there exists a single library module
upon which all of the other modules depend on, as it handles
dynamic memory allocation; more specifically, this library
ensures that the said memory allocation succeeded.

Besides this one primary-dependency module, there are two
library extension modules at the moment: the [Strings](#strings_module)
module and the [Math](#math_module) module. There are
several more planned, however.

The following list gives an overview of the library modules
currently in the planning, design, and implementation stage.

### Memory <a name = "memory_module"></a>
While every module within the project will likely depend on
this module, this module can also prove extremely handy for
application developers, as the return values from memory-
allocation functions will be checke implicitly (from their
point of view), eliding the otherwise-necessary boilerplate
after each call to `malloc(3)`.

### Strings <a name = "strings_module"></a>
The strings library module is meant to provide the
flexibility of straight-forward string operations enjoyed by
PHP, Python, and C++ programmers (particularly simple string
concatenation), without the need to invoke the bulk that any
of those languages imply.

### Math <a name = "math_module"></a>
The mathematics library module is meant to provide as
performant a foundation as possible, including a catalog of
sorting algorithms and non-cryptographic hash functions for
table lookups.

## Getting Started <a name = "getting_started"></a>
> Note: The [xLibs][] project is under active development, so this
information may change in the comming weeks or months. A
plan for a stable release, including a long-term support
schedule and feature set, is in the works.

### Prerequisites <a name = "prerequisites"></a>
The library modules have been written in standards-compliant
C, with no extensions whatsoever, save for the GCC compiler
attributes declared in each function prototype.

This shouldn't be a problem for most people, as clang
understands all of the compiler attributes used in the code.

Support for compiling and using the libraries on Windows is
not supported at the moment, although it would only be a
matter of minutes to add support for MSVC, as the compiler
attributes are defined using preprocessor macros to help
Doxygen parse the function prototypes. Extending these
preprocessor directives to allow for conditional inclusion
of GCC function attributes would not take long at all.

### Installing <a name = "installing"></a>
The project uses [GNU][] [Autotools][Autotools FAQ] toolset
to allow for easy configuration, compilation, and
installation.

#### The Short Version
The commands to install the project in your local system are
as follows.

 > Note: Most of these commands will produce a (possibly
 massive) amount of output; do not be alarmed. If there is
 an error during the build process, this will be one of the
 last messages of the output.

If you run into any problems during the build, please [let
us know][Create an Issue] by creating an issue.

```bash
$ git clone https://github.com/jflopezfernandez/xlibs.git
$ cd xlibs
$ autoreconf --install
$ ./configure
$ make
$ sudo make install
```

#### The Long Version
The goal of this section is to expand upon the short version
described above, providing context for the design and
implementation decisions affecting the build chain and
installation process.

Since we are still in pre-release, the only way to obtain
the project sources is to clone the project repository. You
must then first invoke [Autoconf][Autotools FAQ]. This takes
care of calling each subunit of the Autoconf and Automake
toolset, preparing the project for configuration.



<!--

These sections will be expanded as soon as the code base
grows where more meaningful and compelling examples can be
used.

### Using the Libraries in Your Code <a name = "using"></a>
***\<IN PROGRESS\>***

## Examples
***\<IN PROGRESS\>***

### Example 1
A helpful example.

***\<IN PROGRESS\>***

-->

## Authors <a name = "author"></a>
This is developed and maintained by [Jose Fernando Lopez Fernandez][JFLF].

## Acknowledgements <a name = "acknowledgements"></a>
The following sources were (and are currently being)
consulted extensively for the infinite wisdom they provide.
I would like to thank [Bob Jenkins][] in particular, for so
generously dedicating his work to the public domain, for all
our edification.

Likewise, I would like to declare the contents of this
library, to the extent that it is possible (excluding those
works for which the copyright is not mine to manage), are
licensed under the [GNU General Public License][GPL3].

If anyone should benefit half as much from this project as I
have from Bob Jenkins' wisdom, it will all have been worth
the effort, many times over.

## Sources

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.

1. Jenkins, B. (2005, January 22). Hash Functions for Hash Table Lookup [Personal Blog]. Random Thoughts by Bob Jenkins. https://www.burtleburtle.net/bob/hash/evahash.html

1. Jenkins, B. (2013, September 22). Hash Functions and Block Ciphers [Personal Blog]. Random Thoughts by Bob Jenkins. https://www.burtleburtle.net/bob/index.html

  [Bob Jenkins]: https://www.burtleburtle.net/bob/
  "Bob Jenkins' Home Page"
  [JFLF]: https://github.com/jflopezfernandez
  "jflopezfernandez GitHub Profile"
  
  [malloc(3)]: https://man7.org/linux/man-pages/man3/malloc.3.html
  "malloc(3)"

  [Free Software Foundation]: https://www.fsf.org/ "Free Software Foundation"
  [GNU]: https://www.gnu.org/ "GNU - Home"
  [Autotools FAQ]: https://www.gnu.org/software/automake/faq/autotools-faq.html "Autotools FAQ"
  [gcc]: https://gcc.gnu.org/ "GCC Home"

  [nasm]: https://www.nasm.us/ "NASM Home"

  [xLibs]: https://github.com/jflopezfernandez/xlibs
  "xLibs Project Home"
