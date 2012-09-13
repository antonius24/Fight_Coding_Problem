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

  Partition(list, 4);
  PrintList(list);
}
void Partition(LinkList list, int value)
{
  LinkList before = NULL;
  LinkList after = NULL;

  LinkNode *index = list->next;
  LinkNode *next = NULL;
  while (index != NULL)
  {
    next = index->next;
    if ((index->value) < value)
    {
      index->next = before;
      before = index;
    }
    else
    {
      index->next = after;
      after = index;
    }
    index = next;
  }

  index = before;

  while (index->next != NULL)
  {
    index = index->next;
  }
  index->next = after;

  list->next = before;

}

