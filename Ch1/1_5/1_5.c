#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  int *result;
  int length = strlen(argv[1]);
  int b = 10;
  char sp[10];

  result = (int *)calloc(256, sizeof(int));

  char last = argv[1][0];
  int count = 1;
  int i;
  int size = 0;
  for (i=1; i<length; i++)
  {
    if (argv[1][i] == last)
    {
      count++;
    }
    else
    {
      last = argv[1][i];
      sprintf(sp, "%d", count);
      size = size + strlen(sp) + 1;
      count = 1;
    }
  }
  size = size + strlen(sp) + 1;

  printf("size: %d\n", size);
  if (size <= length)
  {
    i=1;
    int j=0;
    count = 1;
    last = argv[1][0];
    while (i < length)
    {
      if (argv[1][i] == last)
      {
        count++;
      }
      else
      {
      argv[1][j] = last;
      last = argv[1][i];
      j++;
      sprintf(sp, "%d", count);
      int len = strlen(sp);
      int k=0;
      while (k < len)
      {
        argv[1][j] = sp[k];
        j++;
        k++;
      }
      count = 1;
      }
      i++;
    }
    argv[1][j] = last;
    j++;
    sprintf(sp, "%d", count);
    int len = strlen(sp);
    int k=0;
    while (k < len)
    {
      argv[1][j] = sp[k];
      j++;
      k++;
    }
    argv[1][j] = '\0';
  }

  printf("result: %s\n", argv[1]);

}
