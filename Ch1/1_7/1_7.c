#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int result[20][10];

  int *row;
  int *col;


  row = (int *)calloc(20, sizeof(int));
  col = (int *)calloc(10, sizeof(int));
  int i,j,k;
  k=1;
  
  for (i=0; i<20; i++)
  {
    for (j=0; j<10; j++)
    {
      result[i][j] = k;
      k++;
    }
  }
  printf("\n");

  result[2][1] = 0;
  result[9][9] = 0;

  for (i=0; i<20; i++)
  {
    for (j=0; j<10; j++)
    {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for (i=0; i<20; i++)
  {
    for (j=0; j<10; j++)
    {
      if (result[i][j] == 0)
      {
         row[i] = 1;
         col[j] = 1;
      }
    }
  }

  for (i=0; i<20; i++)
  {
    for (j=0; j<10; j++)
    {
      if ((row[i] == 1) || (col[j] == 1))
        result[i][j] = 0;
    }
  }
 
  for (i=0; i<20; i++)
  {
    for (j=0; j<10; j++)
    {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}
