#include <malloc.h>
#include <string.h>
#include "link_list.h"

LinkList Copy(LinkList list)
{
  LinkList old_list = (LinkList)malloc(sizeof(LinkNode));
  LinkNode *index = list;
  LinkNode *old_index = old_list;

  while (index->next != NULL)
  {
    index = index->next;
    LinkNode *temp = (LinkNode *)malloc(sizeof(LinkNode));
    temp->value = index->value;
    old_index->next = temp;
    old_index = old_index->next;
  }
  old_index->next = NULL;
  return old_list;

}

void Reverse(LinkList list)
{
  LinkNode *index = list->next;
  LinkNode *pre = list->next;
  LinkNode *next = list->next->next;
  while (next != NULL)
  {
    pre = index;
    index = next;
    next = index->next;
    //printf("pre: %d\n", pre->value);
    //printf("index: %d\n", index->value);
    //printf("next: %d\n", next->value);
    //printf("\n");
    index->next = pre;
    if (pre == (list->next))
    {
      pre->next = NULL;
    }
  }
  list->next = index;
  
  //printf("%d, %d, %d, %d\n", list->next->value, list->next->next->value, list->next->next->next->value, list->next->next->next->next->value);
}


void main()
{
  LinkList list;
  LinkList old_list;
  Initialization(&list);
  int i;
  for (i=0; i<3; i++)
  {
    InsertTail(list, i);
  }

  for (i=2; i>=0; i--)
  {
    InsertTail(list, i);
  }
  old_list = Copy(list);
  LinkNode *a = old_list;
  Reverse(list);
  PrintList(list);
  PrintList(old_list);
  LinkNode *b = list;

  while (a->next != NULL)
  {
    a = a->next;
    b = b->next;
    if ((a->value) != (b->value))
    {  
      printf("No param!\n");
      return -1;
    }
  }
  printf("Param!\n");
  //printf("List length: %d\n", ListLength(list));

}

