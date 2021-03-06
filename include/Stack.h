#ifndef _CALC_H
#define _CALC_H

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct//栈
{
    int *base;
    int *top;
    int  stacksize;
}Sqstack;


int InitStack(Sqstack* S);
int ClearStack(Sqstack *S);
int DestoryStack(Sqstack *S);
int Push(Sqstack *S,int x);
int StackLength(Sqstack S);
int Pop(Sqstack *S,int *x);
int Gettop(Sqstack *S,int *x);
int StackEmpty(Sqstack  *S);
int PrintStack(Sqstack *S);

#endif //_CALC_H
