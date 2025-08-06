#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100
#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define CHNUKSIZE 50
typedef int Status;

// 二叉树节点结构定义
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status Creat_PreTree(BiTree T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=="#")
    {
        T->data==NULL;
    }
    else
    {
        if(!(T=(BiTNode*)malloc(sizeof(BiTNode))))
        {
            return OVERFLOW;
        }
        T->data=ch;
        Creat_PreTree(&T->lchild);
        Creat_PreTree(&T->rchild);
    }
    return OK;
}

int CopyTree(BiTree T,BiTree T1)
{
    if(T==NULL)
    {
        T1=NULL;
        return 0;
    }
    if(!(T1=(BiTNode*)malloc(sizeof(BiTNode))))
    {
        return OVERFLOW;
    }
    T1->data=T->data;
    CopyTree(T->lchild,T1->lchild);
    CopyTree(T->rchild,T1->rchild);
}

int Depth(BiTree T)
{
    int ldepth,rdepth;
    if(T==NULL)
        return 0;
    ldepth=Depth(T->lchild);
    rdepth=Depth(T->rchild);
    return (ldepth>=rdepth?ldepth:rdepth)+1;
}
int CountNode(BiTree T)
{
    if(T==NULL)
        return 0;
    return CountNode(T->lchild)+CountNode(T->rchild)+1;
}
int CountLeaf(BiTree T)
{
    if(T==NULL)
        return 0;
    if(T->lchild==NULL && T->rchild==NULL)
    {
        return 1;
    } 
    else
    {
        return CountLeaf(T->lchild)+CountLeaf(T->rchild);
    }
}