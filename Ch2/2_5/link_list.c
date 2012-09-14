#include <malloc.h>
#include "link_list.h"


void Initialization(LinkList *list)
{
  *list = (LinkList)malloc(sizeof(LinkNode));
  (*list)->next = NULL;

}

void PrintList(LinkList list)
{
  LinkNode *index = list;

  while (index->next != NULL)
  {
    index = index->next;
    printf("%d --> ", index->value);
  }
  printf("NULL\n");

}

void InsertTail(LinkList list, int value)
{
  LinkNode *index = list;
  while (index->next != NULL)
  {
    index = index->next;
  }
  LinkNode *new = (LinkNode *)malloc(sizeof(LinkNode));
  new->value = value;
  index->next = new;
  new->next = NULL;

}

void DeleteNode(LinkList list, int value)
{
  LinkNode *index = list;
  LinkNode *pre = list;
  while (index->next != NULL)
  {
    pre = index;
    index = index->next;
    if (index->value == value)
      break;
  }
  pre->next = index->next;
  index->next = NULL;
  free(index);

}

int ListLength(LinkList list)
{
  int length = 0;
  LinkNode *index = list;
  
  while (index->next != NULL)
  {
    index = index->next;
    length++;
  }
  return length;
}
