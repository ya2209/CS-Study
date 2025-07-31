#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define MAXQSIZE 100
typedef int Status;

typedef int Elemtypedef;
typedef struct 
{
    Elemtypedef *base;
    int front;
    int rear;
}SqQueue;
Status Init_SqQueue(SqQueue *Q)
{
    Q->base=(Elemtypedef*)malloc(sizeof(Elemtypedef)*MAXQSIZE);
    if(!Q->base)exit(OVERFLOW);
    Q->front=Q->rear=0;
    return OK;
}
Status Push_Q(SqQueue *Q,Elemtypedef e)
{
    if((Q->rear+1)%MAXQSIZE==Q->front)
   {
    return ERROR;
   }
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXQSIZE;
    return OK;
}
Status Pop_Q(SqQueue *Q,Elemtypedef *e)
{
    if(Q->front==Q->rear)
    {
        return ERROR;
    }
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXQSIZE;
    return OK;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

Elemtypedef GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear)
    return Q.base[Q.front];
}
Status QueueEmpty(SqQueue Q)
{
    return Q.front==Q.rear;
}


//链队
typedef struct Qnode
{
    Elemtypedef data;
    struct Qnode *next;
    
}Qnode,*QueuePtr;

typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


Status Init_LQnode(LinkQueue *Q)
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(Qnode));
    Q->front->next=NULL;
    return OK;
    
}

Status DestoryLQueue(LinkQueue *Q)
{
    QueuePtr p;
    while(Q->front)
    {   
        p=Q->front->next;
        free(Q->front);
        Q->front=p;
       
    }
     return OK;
}//p换成Q->rear;

Status PushLQueue(LinkQueue *Q,Elemtypedef e)
{
    QueuePtr p=(Qnode*)malloc(sizeof(Qnode));
    if(!p)exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return OK;

}

Status PopLQueue(LinkQueue *Q,Elemtypedef *e)
{
    if(Q->front==Q->rear)
    {
        return ERROR;
    }
    QueuePtr p=Q->front->next;
    *e=p->data;
    Q->front=p->next;
    if(Q->rear==p)
    Q->rear=Q->front;

    free(p);
    
}
Status GetQnodeHead(LinkQueue Q,Elemtypedef *e)
{
    if(Q.front=Q.rear)
    {
        return ERROR;
    }
    *e=Q.front->next->data;
    return OK;
}
int main()
{
    return 0;
}




