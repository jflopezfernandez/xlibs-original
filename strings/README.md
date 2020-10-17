
<div align="center">

<h2>xStrings</h2>
<h3>C Strings Functions Extensions Library</h3>

</div>

--- 

<div align="center">

Welcome to the xLibs strings manipulation and utilities
extensions module repository!

This library is a part of the [xLibs][] project.

</div>

  [xLibs]: https://github.com/jflopezfernandez/xlibs
  "xLibs Project Repository Home"

## Table of Contents
 * [Edit Distance](#edit-distance)

## Edit Distance
The strings extension library allow for the calculation of
the edit distance edit distance between two strings using
several different edit distance metrics.

The current library code base supports calculating the
[Levenshtein distance][] between two strings using a C
implementation of the [Wagner-Fischer algorithm][].

### Example
This section assumes you have successfully installed the
[xLibs][] libraries on your local system and are able to
successfully link against them. If that is not the case,
please consult the main [xLibs][] project documentation
to get started.

The following code sample demonstrates how the edit distance
string matching calculations may be carried out.

 > Note: The only functional implementation at the moment is
 the Levenshtein distance calculation. All other algorithms
 return a non-sensical value of `18446744073709551615` as
 the result, regardless of the input.

```C
#include <stdio.h>
#include <stdlib.h>

#include <xlibs/mathematics.h>
#include <xlibs/strings.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "No input(s).\n");
        return EXIT_FAILURE;
    }

    const char* a = argv[1];
    const char* b = argv[2];
    
    printf("EditDistance(%s,%s):\n", a, b);
    printf("=========================================\n\n");
    printf("    Levenshtein Distance: %lu\n", calculate_edit_distance(LEVENSHTEIN_DISTANCE, a, b));
    printf("    Longest Common Subsequence: %lu\n", calculate_edit_distance(LONGEST_COMMON_SUBSEQUENCE, a, b));
    printf("    Hamming Distance: %lu\n", calculate_edit_distance(DAMERAU_LEVENSHTEIN_DISTANCE, a, b));
    printf("    Jaru Distance: %lu\n", calculate_edit_distance(JARO_DISTANCE, a, b));
    printf("\n");

    return EXIT_SUCCESS;
}
```
After compilation, the following output demonstrates how
client code might leverage the library functionality.
```bash
$ ./edit-distance sitting kitten
EditDistance(sitting,kitten):
=========================================

    Levenshtein Distance: 3
    Longest Common Subsequence: 18446744073709551615
    Hamming Distance: 18446744073709551615
    Jaru Distance: 18446744073709551615

```

  [Levenshtein distance]: https://en.wikipedia.org/wiki/Levenshtein_distance
  "Levenshtein Distance - Wikipedia"
  [Wagner-Fischer algorithm]: https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm
  "Wagner-Fischer algorithm - Wikipedia"
