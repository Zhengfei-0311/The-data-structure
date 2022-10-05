#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;   
}LNode,*LinkList;

//头插法新建链表   LinkList 代表的是一个地址
LinkList CreatList1(LinkList &L){
    LNode *s;int x=0;
    L=(LinkList)malloc(sizeof(LNode));//带头结点的链表
    L->next=NULL;
    // printf("%d",&x);
    while (x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        printf("%d\n",x);
        x++;
    }
    return L;
}

//尾插法新建链表
LinkList CreatList2(LinkList &L){
    int x=0;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    L->next=NULL;
    while (x!=9)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        // printf("%d\n",x);
        x++;
    }
    r->next=NULL;
    return L;
}

//按序号查找结点值
LNode *GetElem(LinkList L, int i){
    int j=1;
    LNode *p=L->next;
    if(i==0){
        return 0;
    }
    if(i<1){
        return NULL;
    }
    while (p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList L, ElemType e){
    LNode *p=L->next;
    while (p!=NULL && p->data!=e)
    {
        p=p->next;
    }
    return p;
}

//新结点插入第i个位置
bool ListFrontInsert(LinkList L, int i, ElemType e){
    LinkList p=GetElem(L,i-1);
    if(p==NULL){
        return false;
    }
    LinkList s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//删除第i个结点
bool ListDelete(LinkList L, int i){
    LinkList p=GetElem(L,i-1);
    if(p==NULL){
        return false;
    }
    LinkList q;
    q=p->next;
    p->next=q->next;
    free(q);
    return true;
}

void PrintList(LinkList L){
    L=L->next;
    while (L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
    
}



int main(){
    LinkList L;
    LinkList search;
    CreatList2(L);
    PrintList(L);
    search=GetElem(L,2);
    if(search!=NULL){
        printf("按序号查找成功");
        printf("%d\n",search->data);
    }
    search=LocateElem(L,6);
    if(search!=NULL){
            printf("按值查找成功");
            printf("%d\n",search->data);
    }
    ListFrontInsert(L,2,99);
    PrintList(L);
    ListDelete(L,4);
    PrintList(L);
    system("pause");
}