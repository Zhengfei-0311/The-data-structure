#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct  DNode *prior,*next;
}DNode,*DLinkList;

//双向链表的标头插法
DLinkList Dlist_head_insert(DLinkList &DL){
    DNode *s;int x;
    DL=(DLinkList)malloc(sizeof(DNode));
    DL->next=NULL;
    DL->prior=NULL;
}