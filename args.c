#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(char* src, char key) {
  char* c = strchr(src, key);
  return c == NULL ? -1 : c - src;
}

char *substrFromIndex(char *src, int index) {
  char *str = (char *)malloc(strlen(src) - index);
  return strcpy(str, &(src[index]));
}

char *substrUntil(char *src, int index) {
  char *str = (char *)malloc(index);
  return strncpy(str, src, index);
}

char *getArg(int argc, char** argv, char* key) {

  int i = 0;
  for(; i < argc; i++) {
    int index = indexOf(argv[i], '=');
    char *strToComp = (index == -1) ? argv[i] : substrUntil(argv[i], index);
    if(strcmp(strToComp, key) == 0) {
      if(index != -1) {
	return substrFromIndex(argv[i], index+1);
      } else {
	if(argv[i+1] && indexOf(argv[i+1], '-') != 0) {
	  return argv[i+1];
	} else {
	  return "true";
	}
      }
    }
  }
  return "false";
}

// --------------------------------------------------------------------
//
// ./a.out --test=my_arg -value
//              ||         ||
//              \/         \/
//             my_arg     true
//
// I choose to return "true" and "false" rather than void pointers that would
// need a cast. 
// It's better to deal with string only, I think.
// -------------------------------------------------------------------
int main(int argc, char** argv) {

  printf("%s\n", getArg(argc, argv, "--test")); // "my_arg"
  printf("%s\n", getArg(argc, argv, "-value")); // "true"
  printf("%s\n", getArg(argc, argv, "-opt"));   // "false"
  
  return 42; // The answer of everything
}
