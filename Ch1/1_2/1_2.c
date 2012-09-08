#include <string.h>
#include <malloc.h>

int main(int argc, char **argv)
{
  int length = strlen(argv[1]);

  char *result;

  result = (char *)calloc(length, sizeof(char));
  int i,j;
  j=0;
  for (i=length-1; i>=0; i--)
  {
    *(result+i) = argv[1][j];
    j++;
  }

  printf("result: %s\n", result);
  return 0;
}
