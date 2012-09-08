#include <malloc.h>
#include <string.h>

void EraseSpace(char *string)
{
  char *result = (char *)malloc(sizeof(char)*200);
  int length = strlen(string);
  printf("string length: %d\n", length);
  int i;
  int space = 0;
  for (i=0; i<length; i++)
  {
    if (*(string+i) == ' ')
      space++;
  }
  int start = length + space*2 - 1;
  i = length-1;
  while (start >= 0)
  {
    if (*(string+i) == ' ')
    {
      *(result+start) = '0';
      start--;
      *(result+start) = '2';
      start--;
      *(result+start) = '%';
      start--;
    }
    else
    {
      *(result+start) = *(string+i);
      start--;
    }
    i--;
  }

  printf("%s\n", result);

}

int main(int argc, char **argv)
{
  char *test = "Mr     John Smith";
  EraseSpace(test);
}


