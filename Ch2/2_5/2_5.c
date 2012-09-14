#include <malloc.h>
#include <string.h>
#include "link_list.h"


LinkNode *Add(LinkNode *node_1, LinkNode *node_2, int input)
{
  int carry = 0;
  int result = 0;

  if ((node_1 == NULL) && (node_2 == NULL) && (input == 0))
    return NULL;
  if (node_1 != NULL)
    result += node_1->value;
  if (node_2 != NULL)
    result += node_2->value;
      
  result += input;
  carry = result / 10;
  result = result % 10;
   
  LinkNode *final = (LinkNode *)malloc(sizeof(LinkNode));
  LinkNode *last = Add((node_1 == NULL)?NULL: node_1->next, (node_2 == NULL)?NULL: node_2->next, carry);
  final->value = result;
  final->next = last;
  

  return final;
}

void main()
{
  LinkList list;
  LinkList list_2;
  Initialization(&list);
  Initialization(&list_2);
  int i;
  for (i=0; i<5; i++)
  {
    InsertTail(list, i);
  }
  for (i=4; i>0; i--)
  {
    InsertTail(list_2, i);
  }
  PrintList(list);
  PrintList(list_2);
  printf("List length: %d\n", ListLength(list));

  LinkList final;
  Initialization(&final);
  final->next = Add(list->next, list_2->next, 0);
  PrintList(final);
}

