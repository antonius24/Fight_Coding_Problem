#include <string.h>
#include <malloc.h>

int main(int argc, char **argv)
{
  int *record;
  int length = strlen(argv[1]);
  int length_2 = strlen(argv[2]);
  int i;
  
  record = (int *)calloc(256, sizeof(int));
  if (length != length_2)
  {
    printf("not permutation\n");
    return 0;
  }

  i = 0;
  while (i < length)
  {
    int temp = (int)argv[1][i];
    int temp_2 = (int)argv[2][i];
    *(record+temp) = *(record+temp)+1;
    *(record+temp_2) = *(record+temp_2)-1;
    i++;
  }

  i = 0;
  while (i < 256)
  {
    if (*(record+i) != 0)
    {
      printf("not pertuation\n");
      return -1;
    }
    i++;
  }

  
  printf("permutation\n");
  return 0;
}
