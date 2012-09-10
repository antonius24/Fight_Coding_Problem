#include <malloc.h>
#include <string.h>


int main()
{
  int pic[10][10];
  int i,j,k;
  k=1;
  for (i=0; i<10; i++)
  {
    for (j=0; i<10; j++)
    {
      pic[i][j] = k;
      k++;
    }
  }


  for (i=0; i<10; i++)
  {
    for (j=0; j<10; j++)
    {
      printf("%d ", pic[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  int layer=0;
  int top;
  for (layer=0; layer<5; layer++)
  {
    for (i=layer; i<9-layer; i++)
    {
      top = pic[layer][9-i];
      //printf("%d ", pic[layer][9-i]);
      pic[layer][9-i] = pic[i][layer]; //left ->top
      //printf("%d ", pic[i][layer]);
      pic[i][layer] = pic[9-layer][i]; // bottom -> left
      //printf("%d ", pic[9-layer][i]);
      pic[9-layer][i] = pic[9-i][9-layer]; // right ->bottom
      //printf("%d ", pic[9-i][9-layer]);
      pic[9-i][9-layer] = top;  //top->right
      //printf("*********\n");
    }
  }


  for (i=0; i<10; i++)
  {
    for (j=0; j<10; j++)
    {
      printf("%d ", pic[i][j]);
    }
    printf("\n");
  }


  return 0;
}
