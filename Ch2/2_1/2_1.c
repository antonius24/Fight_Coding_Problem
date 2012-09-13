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

  InsertTail(list, 5);
  FindDup(list);
}

void FindDup(LinkList list)
{
  LinkNode *cur = list;
  LinkNode *index;
  LinkNode *pre;
  while (cur->next != NULL)
  {
    cur = cur->next;
    index = cur;
    pre = cur;
    while (index->next != NULL)
    {
      pre = index;
      index = index->next;
      if (cur->value == index->value)
      {
        printf("dup: %d\n", cur->value);
        pre->next = index->next;
        index->next = NULL;
        index = pre;
      }
    }
  }
}

