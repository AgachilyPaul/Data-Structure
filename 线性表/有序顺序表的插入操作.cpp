//在顺序表中，通常使用顺序表的指针的方式来实现顺序表
//有利于释放算法的设计和减少形参传递时为形参分配的空间
#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef struct 
{
    int data[MaxSize];
    int length;
}SqList;
//建立顺序表
void Creat_list(SqList *&s, int a[], int n);
//输出顺序表
void Display_list(SqList *s);
//向有序顺序表中插入
void Insert_list(SqList *&s, int e);

void Creat_list(SqList *&s, int a[], int n)
{
    s = (SqList*)malloc(sizeof(SqList));
    s->length = 0;
    for(int i=0; i<n; i++)
    {
        s->data[i] = a[i];
        s->length++;
    }
    return;
}

void Display_list(SqList *s)
{
    for(int i=0; i<s->length; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
    return;
}

void Insert_list(SqList *&s, int e)
{
	int i=0;
    for(i; s->data[i]<e && i<s->length; i++); //在for循环中声明i的话，i的作用域仅限于for循环
    for(int a=s->length; a>i; a--) //注意这一行代码，用a=s->length好于用a=s->length-1
    {
        s->data[a] = s->data[a-1];
    }
    s->data[i] = e;
    s->length++;
}

int main(void)
{
    SqList *s;
    int a[] = {1, 2, 3, 6, 8, 9};
    Creat_list(s, a, 6);
    Display_list(s);
    Insert_list(s, 10);
    Display_list(s);
}


