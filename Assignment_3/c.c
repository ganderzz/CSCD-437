#include <stdio.h>

const int EXIT_FAILURE = 1;

int bar(char *arg, char *targ, int ltarg)

{

  int len, i;

  len = strlen(arg);

  if (len > ltarg)

    len = ltarg;

  for (i = 0; i <= len; i++)

    targ[i] = arg[i];

  return 0;

}

int foo(char *arg)

{

  char buf[128];

  bar(arg, buf, 140);

  return 0;

}

int main(int argc, char *argv[])

{

  if (argc != 2)

  {

    fprintf(stderr, "c: argc != 2\n");

    exit(EXIT_FAILURE);

  }

  foo(argv[1]);

  return 0;

}