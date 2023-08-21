#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usage.h"

#define FLAG_SIZE 1
#define HEADER_FLAG 0

typedef struct
{
  char flags[FLAG_SIZE];
  char *filename;
} INPUT;

int main(int argc, char *argv[])
{
  int i;
  INPUT input;
  input.filename = NULL;
  if (argc < 3)
  {
    print_usage(stderr, argv[0]);
    exit(1);
  }

  for (i = 1; i < argc; i++)
  {
    if (strncmp(argv[i], "-h", 2) == 0)
    {
      input.flags[HEADER_FLAG] = 1;
    }
    else
    {
      if (input.filename != NULL)
      {
        fprintf(stderr, "You can only specify one file name.\n");
        exit(1);
      }
      input.filename = argv[i];
    }
  }

  if (input.flags[HEADER_FLAG])
  {
    /*
      print header flag
    */
  }

  return 0;
}