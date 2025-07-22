#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef int Status;

typedef int Elemtypedef;

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
//顺序栈长度
int  StackLength(sqstack s)
{
    return s.top-s.base;

}
//清空顺序栈
Status ClearStack(sqstack *s)
{
    if(s->base)
    {
        s->top=s->base;
    }
    return OK;
}
//销毁顺序栈
Status DestoryStack(sqstack *s)
{
    if(s->base)
    {
        free(s->base);
        s->size=0;
        s->base=s->top=NULL;
    }
    return OK;
}
//进栈
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
Status Pop(sqstack *s,Elemtypedef e)

{
    if(s->base==s->top)
    {
        return ERROR;
    }
    s->top--;
    e=*s->top;
    return OK;
}

//链栈的定义
typedef struct StackNode
{
    Elemtypedef data;
    struct StackNode *next;

}StackNode,*LinkStack;

//链栈的初始化
void Init_LinkStack(LinkStack s)
{
    s=NULL;
}
Status IsEmpty_LinkStack(LinkStack s)
{
    if(s==NULL)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}

//链栈入栈
Status L_Push(LinkStack s,Elemtypedef e)
{
    LinkStack p=(Elemtypedef*)malloc(sizeof(Elemtypedef));
    p->data=e;
    p->next=s;
    s=p;
    return OK;
}
Status L_Pop(LinkStack s,Elemtypedef *e)
{
    if(s==NULL)
    return ERROR;
    LinkStack p;
    *e=s->data;
    p=s;
    s=s->next;
    return OK;

}