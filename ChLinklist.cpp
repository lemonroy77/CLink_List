#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList &L){
    L=(LNode*)malloc(sizeof(LNode));
    if(L==NULL)return false;
    L->next=L;
    return true;
}
int LengthList(LinkList L){
    int len=0;
    LNode*p=L->next;
    while(p!=L){
        len++;
        p=p->next;
    }
    return len;}
LinkList List_TailInsert(LinkList&L,int a[],int n){//尾插法，带头结点
    L=(LinkList)malloc(sizeof(LNode));
    LNode*s,*r=L;//r表示表尾指针
    for(int i=0;i<n;i++){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=L;
    return L;
}
LinkList List_HeadInsert(LinkList&L,int a[],int n) {//头插法，带头结点
    LNode*s,*r;
    int i=0;
    bool isFirst = true;
    while(i<n){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
        if(isFirst){
            r=s;
            isFirst=false;
        }
    }
    r->next=L;
    return L;
}
LNode* GetElem(LinkList L, int i){
        if(i < 1) return NULL;
        LNode *p = L->next;
        int j = 1;
        while(p!=L && j < i){
            p = p->next;
            j++;
        }
        return p;
    }
LNode* LocateElem(LinkList L,int e){//按值查找
    if(!L) return NULL;
    LNode*p=L->next;
    while(p!=L&&p->data!=e){
        p=p->next;
        if(p==L) return NULL;
        else return p;
    }
    return p;
}
void printList(LinkList L){
    LNode* p = L->next; // 跳过头节点
    while (p != NULL && p != L) {
        printf("%d\t", p->data);
        p = p->next;
    }
}
int main(){
    int a[]={1,2,3,4,5,6,7};
    LinkList L;
    List_TailInsert(L,a,7);
    printList(L);
    return 0;
}