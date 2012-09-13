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
  LinkNode *index = list;
  i=0;
  while(i<5)
  {
    index = index->next;
    i++;
  }
  Delete(index);
  PrintList(list);
}
void Delete(LinkNode *node)
{
  printf("test\n");
  LinkNode *next = node->next;

  node->value = next->value;
  node->next = next->next;
  next->next = NULL;
  free(next);
}

