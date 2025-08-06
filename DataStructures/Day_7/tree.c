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

int main()
{
    return 0;
}