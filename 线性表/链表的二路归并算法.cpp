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
//链表的二路归并
void Union_list(LNode *LA, LNode *LB, LNode *&LC);

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

void Union_list(LNode *LA, LNode *LB, LNode *&LC)
{
    LNode *pa, *pb, *r, *s; //s用于开辟新的空间，因为对LC采用尾插法，所以需要r指向最后一个节点
    pa = LA->next;
    pb = LB->next;
    LC = (LNode*)malloc(sizeof(LNode));
    r = LC;
    while(pa != NULL && pb != NULL )
    {
        if(pa->data < pb->data)
        {
            s = (LNode*)malloc(sizeof(LNode));
            r->next = s;
            r = s;
            r->data = pa->data;
            pa = pa->next;
        }
        else
        {
            s = (LNode*)malloc(sizeof(LNode));
            r->next = s;
            r = s;
            r->data = pb->data;
            pb = pb->next;
        }
    }
    //判断哪个链表未完
    if(pa != NULL)
    {
        while(pa != NULL)
        {
            s = (LNode*)malloc(sizeof(LNode));
            r->next = s;
            r = s;
            r->data = pa->data;
            pa = pa->next;
        }
    }
    if(pb != NULL)
    {
        while(pb != NULL)
        {
            s = (LNode*)malloc(sizeof(LNode));
            r->next = s;
            r = s;
            r->data = pb->data;
            pb = pb->next;
        }
    }
    r->next = NULL;
}

int main(void)
{
    LNode *LA, *LB, *LC;
    int a[] = {1, 3, 5};
	int b[] = {2, 4, 8, 10};
	Initialize_linkF_end(LA, a, 3);
	Initialize_linkF_end(LB, b, 4);
    Union_list(LA, LB, LC);
    Display_linkF(LC);
}