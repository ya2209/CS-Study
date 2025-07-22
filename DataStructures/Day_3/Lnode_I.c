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

//循环链表的合并
LinkLnode Correct(LinkLnode Ta,LinkLnode Tb)
{
    LinkLnode p=Ta->next;
    Ta->next=Tb->next->next;
    free(Tb->next);
    Tb->next=p;
    return p;
}

//双向链表的定义
typedef struct DuLnode
{
    int data;
    struct DuLnode *prior,*next;
}DuLnode,*DuLinkLnode;


Status GetDuLnodeElem(DuLinkLnode L, int i)
{
	DuLinkLnode p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	return OK;

}
//双向链表的插入
Status DuLnodeInsert(DuLinkLnode L,int i,int e)
{
    DuLinkLnode p;
    if(!(GetDuLnodeElem(p,i)))
    return ERROR;
    DuLinkLnode s=(DuLinkLnode)malloc(sizeof(DuLnode));
    s->data=e;
    s->prior=p->prior;
    p->prior->next=s;
    s->next=p;
    p->prior=s;
    return OK;

    

}
//双向链表的删除
Status DuLnodeDestory(DuLinkLnode L,int i)
{
    DuLinkLnode p;
    if(!(GetDuLnodeElem(p,i)))
    return ERROR;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return OK;

    

}

typedef int pe;

typedef struct 

{
    pe*elem;
    int length;
}sqlist;

Status Init_sqlist(sqlist* L)
{
    L=(sqlist*)malloc(sizeof(sqlist)*MAXSIZE);
    if(!L->elem)exit(OVERFLOW);
    L->length=0;
    return OK;
}

void MergeSqlist(sqlist La,sqlist Lb)
{
    sqlist Lc;
    Init_sqlist(&Lc);
    pe *pa=La.elem;
    pe *pb=Lb.elem;
    pe *pc=Lc.elem;
    Lc.length=La.length+Lb.length;
    pe *pa_last=La.elem+La.length-1;
    pe *pb_last=Lb.elem+Lb.length-1;
    if(pa<=pb)
    {
        *pc++=*pa++;
    }
    else
    {
        *pc++=*pb++;
    }
    while(pa<=pa_last)
    {
        *pc++=*pa++;
    }
    while(pb<=pb_last)
    {
        *pc++=*pb++;
    }
}
    //链表的合并
    /*void Merge_Lnode(LinkLnode La,LinkLnode Lb,LinkLnode Lc)
    {
        Lc=La->next;
        while(La->next&&Lb->next)
        {
            if(La->data<=Lb->data)
            {
                Lc->next=La->next;
                Lc->next=La->next;
                La->next=La->next->next;
            }
            else
            {
                Lc->next=Lb->next;
                Lc=Lb->next;
                Lb->next=Lb->next->next;
            }
        }
        Lc->next=La->next?La->next:Lb->next;
    }
*/

int main()
{
    return 0;
}

