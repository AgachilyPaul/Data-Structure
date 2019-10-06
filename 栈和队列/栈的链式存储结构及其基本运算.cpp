#include<stdio.h>
#include<stdlib.h>

typedef struct linknode
{
    int data;
    struct linknode *next; //在链栈中没有top指针
}LNode;

//初始化栈
void Init_stack(LNode *&s);
//销毁栈
void Destory_stack(LNode *&s);
//判断栈是否为空
bool Stack_empty(LNode *s);
//进栈,头插
void Push(LNode *&s, int e);
//出栈
bool Pop(LNode *&s, int &e);
//取栈顶元素
bool Get_top(LNode *s, int &a);

void Init_stack(LNode *&s)
{
    s = (LNode*)malloc(sizeof(LNode));
    s->next = NULL;
}

void Destory_stack(LNode *&s)
{
    LNode *pre, *p;
    pre = s;
    p = pre->next;
    while(pre != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

bool Stack_empty(LNode *s)
{
    return (s->next == NULL);
}

void Push(LNode *&s, int e)
{
    LNode *p;
    p = (LNode*)malloc(sizeof(LNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

bool Pop(LNode *&s, int &e)
{
	LNode *p;
    if(s->next == NULL)
    {
        return false;
    }
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool Get_top(LNode *s, int &a)
{
	if(s->next == NULL)
    {
        return false;
    }
    a = s->next->data;
    return true;
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

int main(void)
{
    LNode *s;
    int e, a;
    Init_stack(s);
    Push(s, 4);
    Push(s, 6);
    Push(s, 12);
    Pop(s, e);
    Display_linkF(s);
}
