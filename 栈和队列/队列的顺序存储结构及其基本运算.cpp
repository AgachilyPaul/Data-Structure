#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef struct
{
    int data[MaxSize];
    int front, rear;
}SqQueue;

//队空的条件q->front == q->rear
//队满的条件q->rear == MaxSize-1

//初始化队列
void Init_queue(SqQueue *&q);
//销毁队列
void Destory_queue(SqQueue *&q);
//判断队列是否为空
bool Queue_empty(SqQueue *q);
//进队列
bool En_queue(SqQueue *&q, int e);
//出队列
bool De_queue(SqQueue *&q, int &e);

void Init_queue(SqQueue *&q)
{
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
    return;
}

void Destory_queue(SqQueue *&q)
{
    free(q);
    return;
}

bool Queue_empty(SqQueue *q)
{
    return(q->rear == -1);
}

bool En_queue(SqQueue *&q, int e)
{
   if(q->rear == MaxSize-1) //判断队列是否已满
   {
       return false;
   }
   else
   {
        q->rear++;
        q->data[q->rear] = e;
        return true;
   }
   
}

bool De_queue(SqQueue *&q, int &e)
{
    if(q->front == q->rear) //判断栈是否为空
    {
        return false;
    }
    else
    {
        e = q->data[++q->front];
        return true;
    }
    
}

int main(void)
{
    int a;
    SqQueue *q;
    Init_queue(q);
    En_queue(q, 4);
    En_queue(q, 5);
    En_queue(q, 12);
    De_queue(q, a);
    printf("%d ", a);
}