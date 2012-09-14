#include <malloc.h>
#include <string.h>
#include "link_list.h"
int Difference(LinkList list, LinkList list_2)
{
  return ListLength(list) - ListLength(list_2);
}

void padList(LinkList list, int diff)
{
  while (diff > 0)
  {
    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    node->value = 0;
    node->next = list->next;
    list->next = node;
    diff--;
  }
}

LinkNode *Add(LinkNode *node_1, LinkNode *node_2)
{
  int carry = 0;
  int result = 0;

  if ((node_1 == NULL) && (node_2 == NULL))
    return NULL;
  LinkNode *final = (LinkNode *)malloc(sizeof(LinkNode));
  LinkNode *last = Add((node_1 == NULL)?NULL: node_1->next, (node_2 == NULL)?NULL: node_2->next);
  if (last != NULL)
  {
    result += last->carry;
  }
  if (node_1 != NULL)
  {
    result += node_1->value;
  }
  if (node_2 != NULL)
  {
    result += node_2->value;
  }
  carry = result / 10;
  result = result % 10;
  final->value = result;
  final->next = last;
  final->carry = carry;

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
  for (i=9; i>6; i--)
  {
    InsertTail(list_2, i);
  }
  PrintList(list);
  PrintList(list_2);
  printf("List length: %d\n", ListLength(list));

  LinkList final;
  Initialization(&final);
  int diff = Difference(list, list_2);
  if (diff < 0)
  {
    padList(list, 0-diff);
  }
  else if (diff > 0)
  {
    padList(list_2, diff);
  }
  final->next = Add(list->next, list_2->next);
  PrintList(final);
}

