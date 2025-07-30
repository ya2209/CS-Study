#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define CHNUKSIZE 50
typedef int Status;

typedef struct 
{
    char ch[MAXSIZE+1];
    int length;
}SString;


typedef struct Chnuk
{
    char ch[CHNUKSIZE];
    struct Chunk *next;
}Chunk;//块的大小

typedef struct 
{
Chunk *head,*tail;//串的头指针，尾指针
int curlen//串的当前长度
}LString;

int Index_BF(SString S,SString T)
{
    int i=1;
    int j=1;
   while(i<=S.length&&j<=T.length)
   {
    if(S.ch[i]==T.ch[j])
    {
        ++i;
        ++j;
    }
    else
    {
        i=i-j+2;//回溯，重新开始匹配
        j=1;
    }
    if(j>=T.length)
    {
        return i-T.length;

    }
    else
    {
        return 0;
    }
    

   }
}//时间复杂度O(n*m)