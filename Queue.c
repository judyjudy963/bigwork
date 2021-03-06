#include <stdio.h>
#include <stdlib.h>
#include "include/Queue.h"
#define MAXSIZE 100

int InitQuene(sq *q)//chushihua
{
 (*q).quene=(int *)malloc(MAXSIZE*sizeof(int));
  if((*q).quene==NULL)
  {
    printf("Error!\n");
    exit(-1);
  }
  (*q).front=MAXSIZE-1;
  (*q).rear=(*q).front;
  return 1;
}

int Generate(int len,sq *q)//输入值
{
  int i;
  if(len<MAXSIZE&&len>0)
  {
    printf("请输入队中元素数值：");
    for(i=((*q).front+1)%MAXSIZE;i<((*q).front+1+len)%MAXSIZE;i++)
    {
      scanf("%d",&(*q).quene[i]);
      (*q).rear=((*q).rear+1)%MAXSIZE;
    }
  }
   else
   {
    printf("输入有误!\n");
    return 0;
   }
   return 1;
 }
void DestroyQuene(sq *q)//删除队列
{
  free((*q).quene);
  (*q).quene=NULL;
  (*q).front=MAXSIZE-1;
  (*q).rear=(*q).front;
}
void ClearQuene(sq *q)
{
  (*q).front=MAXSIZE-1;
  (*q).rear=(*q).front;
}
int QueneEmpty(sq *q)
{
  if((*q).front==(*q).rear)
  return 1;
  else
  return 0;
}
int QueneFull(sq *q)
{
  if(((*q).rear+1)%MAXSIZE==(*q).front)//判断是否满
  return 1;
  else
  return 0;
}
int QueneLength(sq *q)
{
  return ((*q).rear-(*q).front+MAXSIZE)%MAXSIZE;
}
int GetHead(sq *q)
{
  if(QueneEmpty(q)==0)
  return (*q).quene[((*q).front+1)%MAXSIZE];
  else
  {
    printf("Empty!\n");
    return 0;
  }
}
void EnQuene(int x,sq *q)
{
  if(QueneFull(q)==0)
  {
    (*q).quene[((*q).rear+1)%MAXSIZE]=x;
    (*q).rear=((*q).rear+1)%MAXSIZE;
  }
  else
  {
  printf("已满!\n");
  }
}
void DeQuene(sq *q,int *e)
{
  if(QueneEmpty(q)==0)
  {
    *e=(*q).quene[((*q).front+1)%MAXSIZE];
    (*q).front=((*q).front+1)%MAXSIZE;
  }
  else
  {
  printf("空\n");
  }
}
void QueneTraverse(sq *q)//输出
{
  int i;
  if(QueneEmpty(q)==0)
  {
    for(i=((*q).front+1)%MAXSIZE;i!=((*q).rear+1)%MAXSIZE;i=(i+1)%MAXSIZE)
    {
      printf("%d ",(*q).quene[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Empty!\n");
  }
}
