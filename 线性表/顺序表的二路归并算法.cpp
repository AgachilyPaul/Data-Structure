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
//二路归并
void Union_list(SqList *LA, SqList *LB, SqList *&LC);

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

void Union_list(SqList *LA, SqList *LB, SqList *&LC)
{
    int i=0, j=0, k=0;
    LC = (SqList*)malloc(sizeof(SqList));
    while(i<LA->length && j<LB->length)
    {
        if(LA->data[i] < LB->data[j])
        {
            LC->data[k] = LA->data[i];
            k++;
            i++; //因为是LA中的数字较小，所以是i++
        }
        else
        {
            LC->data[k] = LB->data[j];
            k++;
            j++; //因为是LB中的数字较小，所以是j++
        }
    }
    //判断LA，LB 哪一个还没扫描wan
    if(i<LA->length)
    {
        for(i; i<LA->length; i++)
        {
            LC->data[k] = LA->data[i];
            k++;
        }
    }
    if(i<LB->length)
    {
        for(j; j<LB->length; j++)
        {
            LC->data[k] = LB->data[j];
            k++;
        }
    }
    LC->length = k;
}

int main(void)
{
	SqList *LA, *LB, *LC;
	int a[] = {1, 3, 5};
	int b[] = {2, 4, 8, 10};
	Creat_list(LA, a, 3);
	Creat_list(LB, b, 4);
    Union_list(LA, LB, LC);
    Display_list(LC);
}