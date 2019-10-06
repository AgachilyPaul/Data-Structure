#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef struct 
{
    int data[MaxSize];
    int top; //top
}SqStack;

//初始化栈
void Init_stack(SqStack *&s);
//销毁栈
void Destroy_stack(SqStack *s);
//判断栈是否为空
bool Stack_Empty(SqStack *s);
//进栈
bool Push(SqStack *s, int e);
//出栈
bool Pop(SqStack *s, int &e);
//取栈顶元素
bool Get_top(SqStack *s, int &e);

void Init_stack(SqStack *&s)
{
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1; //栈顶指针在初始化的时候置为-1}
    return;
}

void Destroy_stack(SqStack *s)
{
    free(s);
    return;
}

bool Stack_Empty(SqStack *s)
{
    if(s->top == -1)
    {
        printf("该栈为空");
        return false;
    }
    else
    {
       printf("该栈不为空");
       return true;
    }   
}

bool Push(SqStack *s, int e)
{
    if(s->top == MaxSize-1) //首先判断栈是否为空
    {
        printf("栈已满")；
        return false;
    }
    else
    {
        s->top++;
        s->data[s->top] = e;
        return true;
    }
}

bool Pop(SqStack *s, int &e)
{
    if(s->top == -1)
    {
        printf("栈为空");
        return false;
    }
    else
    {
       e = s->data[s->top];
       s->top--;
       return true;
    }
}

bool Get_top(SqStack *s, int &e)
{
    if(s->top == -1)
    {
        printf("栈为空");
        return false;
    }
    else
    {
        e = s->data[s->top];
        return true;
    }
}

int main(void)
{
    int a=5, b=6, c=12, d, e;
    SqStack *s;
    Init_stack(s);
    Push(s, a);
    Push(s, b;
    Push(s, c);
    Pop(s, d);
    printf("%d \n", d);
    Get_top(s, e);
    printf("%d \n", e);
    return 0;
}