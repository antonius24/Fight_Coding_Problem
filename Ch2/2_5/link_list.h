#ifndef _LinkList_H
#define _LinkList_H

typedef struct Node
{
  int carry;
  int value;
  struct Node *next;
}LinkNode, *LinkList;


void Initialization(LinkList *list);
void InsertTail(LinkList list, int value);
void DeleteNode(LinkList list, int value);
int ListLength(LinkList list);
void PrintList(LinkList list);

#endif
