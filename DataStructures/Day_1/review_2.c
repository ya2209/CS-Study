//链表
//链表的定义iostream>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef int Status;

typedef struct Lnode
{
    int data;
    struct Lnode* next;

}Lnode,*LinkLnode;

//链表初始化
void InitLnode(LinkLnode L)
{
    L=(LinkLnode)malloc(sizeof(Lnode));
    L->next=NULL;
    L->data=0;
}
//头插法创建链表
 void Creat_R_Lnode(LinkLnode L,int n)
{

    LinkLnode p;
    L=(LinkLnode)malloc(sizeof(Lnode));
    L->next=NULL;
    int i=0;
    for(i=n;i>0;n--)
    {
        p=(LinkLnode)malloc(sizeof(Lnode));
        scanf(&p->data);
        p->next=L->next;
        L->next=p;
    }

}
 //后插法
 void Creat_L_Lnode(LinkLnode L,int n)
 {
    int i=0;
    LinkLnode r=(LinkLnode)malloc(sizeof(Lnode));
    L->next=NULL;
    r=L;
    for(i=0;i<n;i++)
    {
        LinkLnode p=(LinkLnode)malloc(sizeof(Lnode));
        scanf(&p->data);
        p->next=NULL;
        r->next=p;
        p=r;

    }
    
 }
 //链表的销毁
  void Destory(LinkLnode L)
 {
    LinkLnode p;
    
    while(p)
    {
        p=L;
        L=L->next;
        free(p);
    }

 }
 //链表的清理
 void Clear(LinkLnode L)
 {
    LinkLnode p,q;
    p=L->next;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
 }
 //查找链表元素,返回地址
 int  GetData(LinkLnode L,int e)
 {
    LinkLnode p=L->next;
    while(p&&p->data!=e)
    {
        p=p->next;

    }
    return p;
 }
//查找链表元素，返回值
int GetData_B(LinkLnode L,int e)
{
    LinkLnode p=L->next;
    int j=1;
    while(p&&p->data!=e)
    {
        p=p->next;
        j++;
    }
    if(p){ return j;}
    else{return 0;}
}
//获取链表元素
Status GetLnodeElem(LinkLnode L, int i, int* e)
{
	LinkLnode p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;

}
//插入
Status LnodeInsert(int i, int e, LinkLnode L)
{
	LinkLnode p = L->next;LinkLnode s;
	int j = 1;
	while (p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkLnode)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;


}
Status LnodeDelete(LinkLnode L, int i,int *e)
{
	LinkLnode p = L->next;LinkLnode q;
	int j = 1;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	q = p->next;
	*e = q->data;//为什么保存e，因为题目要求删除第i个元素，并返回其值，所以保存q的data
	p->next = p->next->next;
	free(q);
	return OK;

}
