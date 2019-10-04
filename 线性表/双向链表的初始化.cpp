#include<stdio.h>
#include<stdlib.h>

typedef struct DLinkNode
{
    int data;
    struct DLinkNode *prior;
    struct DLinkNode *next;   
}DNode;

//头插法建立双向链表
void Creat_list_head(DNode *&d, int a[], int n);
//尾插法建立双向链表，在尾插法中需要一个指针来指向最后一个节点
void Creat_list_end(DNode *&d, int a[], int n);
//输出链表
void display(DNode *d);

//注意要在d之前加&，在能够将修改回传
void Creat_list_head(DNode *&d, int a[], int n)
{
    DNode *s;
    d = (DNode*)malloc(sizeof(DNode));
    d->next = NULL;
    d->prior = NULL;
    for(int i=0; i<n; i++)
    {
        s = (DNode*)malloc(sizeof(DNode));
        s->next = d->next;
        s->prior = d;
        if(d->next != NULL)
        {
            d->next->prior = s;
        }
        d->next = s;
        s->data = a[i];
    }
    return;
}

void Creat_list_end(DNode *&d, int a[], int n)
{
    DNode *s, *p;
    d = (DNode*)malloc(sizeof(DNode));
    d->next = NULL;
    d->prior = NULL;
    p = d;
    for(int i=0; i<n; i++)
    {
        s = (DNode*)malloc(sizeof(DNode));
        s->next = p->next;
        s->prior = p;
        p->next = s;
        s->data = a[i];
        p = s;
    }
    return;
}

void display(DNode *d)
{
    //注意要先将指针指向第一个节点
    DNode *s = d->next;
    //注意此处不是s->next != NULL
    while(s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    return;
}
//只在主函数中声明一个指向头节点的指针
int main(void)
{
    DNode *d;
    int a[] = {1,2,3,4,5,6};
    Creat_list_end(d, a, 6);
    display(d);
}