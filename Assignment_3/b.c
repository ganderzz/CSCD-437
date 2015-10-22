#include <stdio.h>

const int EXIT_FAILURE = 1;

int foo(char *arg)
{

  char buf[128];
  int len, i;

  len = strlen(arg);

  if (len > 136)
    len = 136;

  for (i = 0; i <= len; i++)
    buf[i] = arg[i];

  return 0;

}

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    fprintf(stderr, "b: argc != 2\n");

    exit(EXIT_FAILURE);
  }

  foo(argv[1]);

  return 0;

}