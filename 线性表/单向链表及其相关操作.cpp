#include<stdio.h>
#include<stdlib.h>

//建立描述链表结点的结构体
typedef struct LinkNode
{
    int data;
    struct LinkNode* next;
}LNode;
//头插法
void Initialize_likF_head(LNode *&l, int a[], int n);
//尾插法
void Initialize_linkF_end(LNode* &l, int a[], int n);
//输出链表
void Display_linkF(LNode* l);
//判断表是否为空表
bool Lisi_empty(LNode *l);
//求线性表的长度
int List_length(LNode *l);
//求线性表中某个元素的值
bool Get_elem(LNode *l, int i, int &e);
//按元素查找
int Locate_elem(LNode *l, int e);
//插入数据元素
bool Insert_list(LNode *&l, int i, int e);
//销毁线性表
void Destory_list(LNode *&l);

void Initialize_likF_head(LNode *&l, int a[], int n)
{
    LNode *s;
    l = (LNode*)malloc(sizeof(LNode));
    l->next = NULL;
    for(int i=0; i<n; i++)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = l->next;
        l->next = s;
    }
}

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

bool Lisi_empty(LNode *l)
{
    return (l->next == NULL);
}

int List_length(LNode *l)
{
    int n=0;
    LNode *p = l;
    while(p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

bool Get_elem(LNode *l, int i, int &e)
{
    int j = 0;
    LNode *p=l;
    if(i<=0)
    {
        return false;
    }
    while(j<i && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p == NULL)
    {
        return false;
    }
    else
    {
      e = p->next;
      return true;
    }
    
}

void Destory_list(LNode *l)
{
    LNode *pre = l, *p = l->next;
    while(p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

int Locate_elem(LNode *l, int e)
{
    int i=1;
    LNode *p = l->next;
    while(p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return i;
    }
    
}

bool Insert_list(LNode *&l, int i, int e)
{
    int j = 0;
    LNode *p = l, *s;
    if(i<=0)
    {
        return false;
    }
    while(j<i-1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if(p == NULL)
    {
        return false;
    }
    else
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
    
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