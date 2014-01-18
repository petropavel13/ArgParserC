#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_arg(const int argc, char** argv, const char* const key) {
    int i = 0;

    for(; i < argc; ++i) {
        if (strstr(argv[i], key) != NULL) {
            if (strchr(argv[i], '=') != NULL) {
                return &(argv[i][strlen(key) + 1]);
            } else {
                return "true";
            }
        }
    }

    return "false";
}

// --------------------------------------------------------------------
//
// ./myapp --test=my_arg -value +abc=13 **silent
//                ||        ||     ||      ||
//                \/        \/     \/      \/
//             "my_arg"   "true"  "13"   "true"
//
// I choose to return "true" and "false" rather than void pointers that would
// need a cast.
// It's better to deal with string only, I think.
// -------------------------------------------------------------------
int main(int argc, char** argv) {

  printf("%s\n", get_arg(argc, argv, "--test")); // "my_arg"
  printf("%s\n", get_arg(argc, argv, "-value")); // "true"
  printf("%s\n", get_arg(argc, argv, "-opt"));   // "false"
  printf("%s\n", get_arg(argc, argv, "+abc"));   // "13"
  printf("%s\n", get_arg(argc, argv, "**silent"));   // "true"

  return 42; // The answer of everything
}
