#include <malloc.h>
#include <string.h>
#include "link_list.h"

void main()
{
  LinkList list;

  Initialization(&list);
  int i;
  for (i=0; i<10; i++)
  {
    InsertTail(list, i);
  }
  PrintList(list);
  printf("List length: %d\n", ListLength(list));

  NtoLast(list, 3);
}

int NtoLast(LinkList list, int n)
{
  int i;
  
  if (list == NULL)
    return 0;
  
  i = NtoLast(list->next, n) + 1;
  if (i == n)
  {
    printf("output: %d\n", list->value);
  }
  return i;
}

