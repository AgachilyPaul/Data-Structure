/*因为在之前的顺序队列中，因为堆满条件设置的不合理，
因此当队满的时候，队中仍然可能存在空位，使用环形数组可以避免这个问题*/
//队空条件p->front == p->rear
//队满条件(q->rear+1)%MaxSize == q->front, 这样使得环形队列中最多存储MaxSize-1个数据

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef struct
{
    int data[MaxSize];
    int front, rear;
}SqQueue;

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
    q->front = q->rear = 0;
    return;
}

void Destory_queue(SqQueue *&q)
{
    free(q);
    return;
}

bool Queue_empty(SqQueue *q)
{
    return(q->front == q->rear);
}

bool En_queue(SqQueue *&q, int e)
{
    if((q->rear+1)%MaxSize == q->front)
    {
        return false;
    }
    else
    {
        q->rear = (q->rear+1)%MaxSize;
        q->data[q->rear] = e;
        return true;
    }
}

bool De_queue(SqQueue *&q, int &e)
{
    if(q->front == q->rear)
    {
        return false;
    }
    else
    {
        q->front = (q->front+1)%MaxSize;
        e = q->data[q->front];
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