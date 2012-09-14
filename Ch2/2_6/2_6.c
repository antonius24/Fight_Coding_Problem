#include <malloc.h>
#include <string.h>
#include "link_list.h"



LinkNode *Find(LinkList list)
{
  LinkNode *slow = list->next;
  LinkNode *fast = list->next;
  
  while(1)
  {
  if ((slow->next != NULL) && (fast->next->next != NULL))
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  else
    return NULL;
  if (slow == fast)
     break;
  }
  slow = list->next;
  while (1)
  {
    if ((slow->next != NULL) && (fast->next != NULL))
    {
      slow = slow->next;
      fast = fast->next;
    }
    if (slow == fast)
      return fast;
  }
}


void main()
{
  LinkList list;

  Initialization(&list);
  int i;
  for (i=0; i<10; i++)
  {
    InsertTail(list, i);
  }
  LinkNode *a = list->next->next->next;
  printf("value: %d\n", a->value);
  LinkNode *b = list;
  while (b->next != NULL)
  {
    b = b->next;
  }
  b->next = a;
  //PrintList(list);
  //printf("List length: %d\n", ListLength(list));

  LinkNode *result = Find(list);
  printf("result: %d\n", result->value);
}

