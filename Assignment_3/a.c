#include <stdio.h>

const int EXIT_FAILURE = 1;

int foo(char *arg, char *out)

{

  strcpy(out, arg);

  return 0;

}

 int main(int argc, char *argv[])

{

  char buf[64];

  if (argc != 2)

  {

    fprintf(stderr, "a: argc != 2\n");

    exit(EXIT_FAILURE);

  }

  foo(argv[1], buf);

  return 0;

}