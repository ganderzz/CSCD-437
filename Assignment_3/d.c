#include <stdio.h>

const int EXIT_FAILURE = 1;

int foo(char *arg, short arglen)
{

  char buf[1024];
  int i, maxlen = 1024;

  if (arglen < maxlen)
  {
    printf("strlen arg: %i\n", strlen(arg) );
    printf("arglen: %i\n", arglen);

    for (i = 0; i < strlen(arg); i++)
      buf[i] = arg[i];
  }

  return 0;
}

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    fprintf(stderr, "d: argc != 2\n");

    exit(EXIT_FAILURE);
  }

  printf("strlen arv: %i\n", strlen(argv[1]) );

  foo(argv[1], strlen(argv[1]));

  return 0;

}