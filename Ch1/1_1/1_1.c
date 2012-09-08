#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define ASCII 256

int main(int argc, char **argv)
{
  int *record;

  printf("Input length: %d\n", strlen(argv[1]));
  if (strlen(argv[1]) > ASCII)
  {
    printf("Maximum reached.\n");
    return 0;
  }
  record = (int *)calloc(ASCII, sizeof(int));
  int i;
  /*
  for (i=0; i<ASCII; i++)
  {
    printf("record %d: %d\n", i, *(record+i));
  }
  */
  int temp;
  for (i=0; i< strlen(argv[1]); i++)
  {
    temp = (int)argv[1][i];
    if (*(record+temp) == 0)
      *(record+temp) = 1;
    else
    {
      printf("Duplicate found: %c\n", argv[1][i]);
      break;
    }
  }
  return 0;
}
