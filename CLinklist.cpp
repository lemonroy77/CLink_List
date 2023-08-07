#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode, *LinkList;
bool InitList(LinkList &L){
    L = NULL; // 将链表指针置为NULL
    return true;
}
int LengthList(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p != NULL){
        len++;
        p = p->next;
        if(p == L) break; // 到达循环终点，跳出循环
    }
    return len;
}
LinkList List_TailInsert(LinkList &L, int a[], int n){
    LNode *r = NULL; // 表尾指针
    for(int i = 0; i < n; i++){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        if(L == NULL){ // 第一个节点
            L = s;
            r = s;
        }else{
            r->next = s;
            r = s;
        }
        r->next = L; // 循环指向头节点
    }
    return L;
}
LinkList List_HeadInsert(LinkList&L,int a[],int n) {
    LNode*s,*r;
    int i=0;
    bool isFirst = true;
    while(i<n){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        s->next=L;
        L=s;
        if(isFirst){
            r=s;
            isFirst=false;
        }
    }
    r->next=L;
    return L;
}
LNode* GetElem(LinkList L, int i){
    if (i < 1) return NULL;
    LNode *p = L;
    int j = 1;
    while(p != NULL && j < i){
        p = p->next;
        j++;
        if(p == L) break; // 到达循环终点，跳出循环
    }
    return p;
}
LNode* LocateElem(LinkList L, int e){
    if(L == NULL) return NULL;
    LNode *p = L;
    while(p != NULL && p->data != e){
        p = p->next;
        if(p == L) return NULL; // 到达循环终点，未找到元素
    }
    return p;
}
void printList(LinkList L){
    LNode* p = L;
    while (p != NULL) {
        printf("%d\t", p->data);
        p = p->next;
        if(p == L) break; // 到达循环终点，跳出循环
    }
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    LinkList L;
    InitList(L);
    L = List_TailInsert(L, a, 7);
    printList(L);
    return 0;
}

