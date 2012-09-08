#include <string.h>
#include <malloc.h>

int main(int argc, char **argv)
{
  int length = strlen(argv[1]);

  int i=0, j=length-1;
  
  while (i < j)
  {
    char temp;
    temp = argv[1][i];
    argv[1][i] = argv[1][j];
    argv[1][j] = temp;
    i++;
    j--;
  }

  printf("result: %s\n", argv[1]);



  return 0;
}
