#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MaxSize 50
typedef int ElemType;


typedef struct {
    ElemType data[MaxSize];
    int length;
}SqLisrt;


#define InitSize 100
typedef struct {
    ElemType *data;
    int capacity;
    int length;
}SeqList;


bool ListInsert(SqLisrt &L, int i, ElemType e){
    if(i < 1 || i > L.length+1){
        return false;
    }
    if(L.length > MaxSize){
        return false;
    }
    for(int j=L.length; j>=i; j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}


bool ListDelete(SqLisrt &L, int i, ElemType &e){
    if(i < 1 || i > L.length){
        return false;
    }
    e = L.data[i-1];
    for(int j=i; j<L.length; j++){
        L.data[j-1]=L.data[j];
    }
    L.length-=1;
    return true;
}


int LocateElem(SqLisrt &L, ElemType e){
    for(int i=0; i<L.length; i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}


void PrintList(SqLisrt &L){
    for(int i=0; i<L.length; i++){
        printf("%4d",L.data[i]);
    }
    printf("\n");
}

int main(){
    SqLisrt L;
    bool ret;   
    ElemType del;   

    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.length=3;


    ret=ListInsert(L,2,60);
    if(ret){
        printf("插入成功\n");
        PrintList(L);
    }else{
        printf("插入失败\n");
    }

    ret=ListDelete(L, 2, del);
    if(ret){
        printf("删除成功\n");
        printf("删除的元素的值为%d\n", del);
        PrintList(L);
    }else{
        printf("删除失败\n");
    }

    ret=LocateElem(L, 1);
    if(ret){
        printf("查找成功\n");
        printf("元素的位置为%d\n",ret);
    }else{
        printf("查找失败\n");
    }
    system("pause");

}