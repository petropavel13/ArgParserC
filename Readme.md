## Arguments parser written in C

> It's a very lightwave parser for quick testing and prototyping

Example & usage:

<pre>
./myapp --test=my_arg -value +abc=13 **silent
              ||         ||     ||       ||
              \/         \/     \/       \/
            "my_arg"   "true"  "13"    "true"
</pre>


```C
int main(int argc, char** argv) {
    printf("%s\n", get_arg(argc, argv, "--test"));    // "my_arg"
    printf("%s\n", get_arg(argc, argv, "-value"));    // "true"
    printf("%s\n", get_arg(argc, argv, "-opt"));      // "false"
    printf("%s\n", get_arg(argc, argv, "+abc"));      // "13"
    printf("%s\n", get_arg(argc, argv, "**silent"));  // "true"

    return 42; // The answer of everything
}
```