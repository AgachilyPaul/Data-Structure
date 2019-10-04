#include<stdio.h>
#include<stdlib.h>

//建立描述链表结点的结构体
typedef struct LinkNode
{
    int data;
    struct LinkNode* next;
}LNode;

//尾插法
void Initialize_linkF_end(LNode* &l, int a[], int n);
//输出链表
void Display_linkF(LNode* l);
//有序插入
void List_insert(LNode *&d, int e);

void Initialize_linkF_end(LNode* &l, int a[], int n)
{
    //为头结点L开辟空间
    l = (LNode*)malloc(sizeof(LNode));
    //为链表赋值
    LNode *s, *r;
    r=l;
    for(int i=0; i<n; i++)
    {
        //通过循环不断开辟节点
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        //在尾插法中需要一个变量来跟踪尾节点

        r->next = s;
        r = s;
    }
    //将最后一个结点置为空
    r->next = NULL; 
}

void Display_linkF(LNode* l)
{
    LNode *p=l->next;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
//查找插入节点的前驱节点会是程序比较简单
void List_insert(LNode *&l, int e)
{
    LNode *p = l, *s;
    for(p; p->next != NULL && p->next->data<e; p=p->next);
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

int main(void)
{
    //初始化头结点,注意要先分配空间然后才能使用
    LNode *l;
    int a[] = {1, 2, 3, 7, 8, 9};
    //初始化表
    Initialize_linkF_end(l, a, 6);
    //打印表 
    Display_linkF(l);
    List_insert(l, 10);
    Display_linkF(l);
}