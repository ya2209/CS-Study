#include<stdio.h>
#include<stdlib.h>



//顺序表的复习
#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef int Status;

/*typedef int pe;

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

//查找
int FindSq(sqlist L,pe e)
{
    int i=0;
    for(i=0;i<L.length;i++)
    {
        if(L.elem[i]==e)
        {
            return i+1;
        }
        else
        {
            return 0;
        }
    }

}
Status InsertSq(sqlist* L,pe e,int i)
{
    int j=0;
    if (L->length > MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length + 1)
		return ERROR;
    for(j=L->length-1;j>=i-1;j--)
    {
        L->elem[j+1]=L->elem[j];

    }
    L->elem[i-1]=e;
    L->length++;
    return OK;
}
 DelestSq(sqlist* L,int i)
{
    int j=0;
    for(j=i;j<=L->length-1;j++)
    {
        L->elem[j-1]=L->elem[j];
    }
    L->length--;
    return OK;
}
void printlist(sqlist* L)
{
	int i;
	printf("\n顺序表中的元素为：\n");
	for (i = 0; i < L->length; i++)
		printf("%d", L->elem[i]);
	printf("\n\n");
}//输出线性表
*/

int main()
{
    

}
