#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100
#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define CHNUKSIZE 50
typedef int Status;
typedef int Elemtypedef;
typedef Elemtypedef SqBiTree[MAXSIZE];
SqBiTree bt;//顺序存储
typedef struct BtNode
{
    Elemtypedef data;
    struct BtNode *lchild,*rchild;
}BtNode,*BT;//链式存储
typedef struct TriTNode
{
    Elemtypedef data;
    struct TriTNode *lchild,*rchild,*parent;

}TriTNode,*TriTree;

Status PreOrderTraverse(BT T)
{
    if(T==NULL)
    return OK;
    else
    {
        printf("%d\n",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
Status InOrderTraverse(BT T)
{
    if(T==NULL)
    return OK;
    else
    {
        
        InOrderTraverse(T->lchild);
        printf("%d\n",T->data);
        InOrderTraverse(T->rchild);
    }
}
Status PostOrderTraverse(BT T)
{
    if(T==NULL)
    return OK;
    else
    {
        
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d\n",T->data);
    }
}
typedef struct
{
    Elemtypedef *top;
    Elemtypedef *base;
    int size;
    
}sqstack;

//顺序栈的初始化
Status Init_Sqstack(sqstack *s)
{
    s->base=(Elemtypedef*)malloc(sizeof(Elemtypedef)*MAXSIZE);
    if(!s->base)
    return ERROR;
    s->top=s->base;
    s->size=MAXSIZE;
    return OK;

    
}
//顺序栈是否为空
Status IsStackEmpty(sqstack s)
{
    if(s.base==s.top)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}
    Status Push(sqstack *s, Elemtypedef e)
{
    if(s->top-s->base==s->size)
    {
        return OVERFLOW;
    }
    *s->top = e;
    s->top++;
    return OK;
}
//出栈
Status Pop(sqstack *s,Elemtypedef *e)

{
    if(s->base==s->top)
    {
        return ERROR;
    }
    s->top--;
    *e=*s->top;
    return OK;
}
Status InOrderTraverse_stack(BT T)
{
    BT p;
    sqstack S;
    BT q;
    Init_Sqstack(&S);
    p=T;
    while(p||!IsStackEmpty(S))
    {
        if(p)
        {
            Push(&S,p->data);
            p=p->lchild;

        }
        else
        {
            Pop(&S,&q->data);
            printf("%d\n",q);
            p=q->rchild;
        }
    }
}


int main()
{
    return 0;
}