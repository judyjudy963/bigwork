#include <stdio.h>
#include <stdlib.h>
#include "include/Stack.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

int InitStack(Sqstack* S)//栈的初始化
{
  (*S).base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
  if((*S).base==NULL)
  exit (-1);
  (*S).top=(*S).base;//栈空
  (*S).stacksize =STACK_INIT_SIZE;
  return 1;
}
int ClearStack(Sqstack *S)
{
  while((*S).top>(*S).base)
  {
    --(*S).top;
    *((*S).top)=0;
  }
  if((*S).top==(*S).base)
  {
    printf("clear successfully!\n");
    return 1;
  }
  else
  {
    printf("clear fail!\n");
    return 0;
  }
}
int DestoryStack(Sqstack *S)
{
  if((*S).base)
  {
    free((*S).base);
    printf("destroy successfully!\n");
    return 1;
  }
   else
   {
     printf("destroy fail!\n");
     return 0;
   }
}
int Push(Sqstack *S,int x)//入栈
{
  if(((*S).top-(*S).base)>=(*S).stacksize)
  {
    (*S).base=(int *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(int));
    if(!(*S).base)
    exit(-1);
    (*S).top=(*S).base+(*S).stacksize;
    (*S).stacksize+=STACKINCREMENT;
   }
    *((*S).top)=x;
    (*S).top++;
    return 1;
}
int StackLength(Sqstack S)
{
  return (S.top-S.base);
}
int Pop(Sqstack *S,int *x)//出栈
{
  if ((*S).top==(*S).base)
  {
    printf("栈空！\n");
    return 0;
  }
  else
  {
  *x=*(--(*S).top);
  return 1;
  }
}
int Gettop(Sqstack *S,int *x)//取栈顶
{
  if ((*S).top==(*S).base)
  {
    printf("栈空！\n");
    return 0;
  }
  else
  {
    *x=*((*S).top-1);
    return 1;
  }
}

int StackEmpty(Sqstack  *S)
{
    if ((*S).top==(*S).base)
                  return  1 ;
    else
                  return  0 ;
}

int  PrintStack(Sqstack *S)
{
    int *p;
    for(p=(*S).base;p<(*S).top;p++)
        printf("%d ",*p);
    printf("\n");
    return 1;
}

