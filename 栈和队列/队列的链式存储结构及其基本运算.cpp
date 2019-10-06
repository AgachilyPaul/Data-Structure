#include<stdio.h>
#include<stdlib.h>

//链队中数据节点的结构体类型
typedef struct qnode
{
    int data;
    struct qnode *next;
}DNode;

//链队中头节点的结构体类型
typedef struct
{
    DNode *front;
    DNode *rear;
}Link_Qu_Node;

//初始化队列
void Init_Queue(Link_Qu_Node *&q);
//销毁队列
void Destory_Queue(Link_Qu_Node *&q);
//判断队列是否为空
bool Queue_empty(Link_Qu_Node *q);
//进队列
void En_Queue(Link_Qu_Node *&q, int e);
//出队列
bool De_Queue(Link_Qu_Node *&q, int &e);

void Init_Queue(Link_Qu_Node *&q)
{
    q = (Link_Qu_Node*)malloc(sizeof(Link_Qu_Node));
    q->front = q->rear = NULL;
}

void Destory_Queue(Link_Qu_Node *&q)
{
    DNode *pre = q->front, *p;
    if(pre != NULL)
    {
        p = pre->next;
        while(pre->next != NULL)
        {
            free(pre);
            pre = p;
            p = p->next;
        }
        free(pre);
    }
    free(q);
}

bool Queue_empty(Link_Qu_Node *q)
{
    return(q->rear == NULL);
}

void En_Queue(Link_Qu_Node *&q, int e)
{
    DNode *d;
    d = (DNode*)malloc(sizeof(DNode));
    d->data = e;
    d->next = NULL;
    if(q->rear == NULL) //如果链队为空，那么该节点既是首节点又是尾节点
    {
        q->front = q->rear = d;
    }
    else
    {
        q->rear->next = d; //挂到链中
        q->rear =  d; //指向队尾
    }
}

bool De_Queue(Link_Qu_Node *&q, int &e)
{
    DNode *d;
    if(q->rear == NULL)
    {
        return false;
    }
    d = q->front;
    if(q->front == q->rear) //只有一个节点的情况
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }
    e = d->data;
    free(d);
    return true;
}

int main(void)
{
    int a;
    Link_Qu_Node *q;
    Init_Queue(q);
    En_Queue(q, 4);
    En_Queue(q, 5);
    En_Queue(q, 12);
    De_Queue(q, a);
    printf("%d ", a);
    De_Queue(q, a);
    printf("%d ", a);
}