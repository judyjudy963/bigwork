#include <stdio.h>
#include <stdlib.h>
#include "include/Tree.h"
#define MAX_TREE_SIZE 100
#define QUEUE_INIT_SIZE 100

int InitBiTree(BiTree * T)
{
    (*T)=(BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data=0;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
    return 1;
}

int print(int e)
{
    printf("%d ",e);
    return 1;
}

void createBiTree(BiTree *T)//
{
    int ch;
    scanf("%d",&ch);
    if(ch==0)  (*T)=NULL;
    else
    {
        if(!((*T)=(BiTNode *)malloc(sizeof(BiTNode))))   exit(-1);
        (*T)->data=ch;
        createBiTree(&((*T)->lchild));
        createBiTree(&((*T)->rchild));
    }
}

int ClearBiTree(BiTree *T)
{
    if(*T) {(*T)=NULL;printf("Clear success!\n");return 1;}
    else   {printf("Clear fail!\n");return 0;}
}

int DestoryBiTree(BiTree *T)
{
    if(T)  {free(T);printf("Destroy success!\n");return 1;}
    else   {printf("Destroy fail!\n");return 0;}
}

int BiTreeEmpty(BiTree * T)
{
    if(*T==NULL)
        return 1;
    else
        return 0;
}

int Value(BiTree p)
{
    int a;
    if(p)   {a=(p)->data;return (p)->data;}
    else return -1;
}

int Assign(BiTree *T,BiTree *p,int e)//
{
    (*p)->data=e;
    return 1;
}

int PreOrderTraverse_1(BiTree T,int(* visit)(int e))
{
    if(T)
    {
        if(visit(T->data))
            if(PreOrderTraverse_1(T->lchild,visit))
                 if(PreOrderTraverse_1(T->rchild,visit))  return 1;
        return 0;
    }else   return 1;
}

int InOrderTraverse_1(BiTree T,int(* visit)(int e))
{
    if(T)
    {
        if(InOrderTraverse_1(T->lchild,visit))
            if(visit(T->data))
                 if(InOrderTraverse_1(T->rchild,visit))  return 1;
        return 0;
    }else   return 1;
}

int PostOrderTraverse_1(BiTree T,int(* visit)(int e))
{
    if(T)
    {
        if(PostOrderTraverse_1(T->lchild,visit))
            if(PostOrderTraverse_1(T->rchild,visit))
                if(visit(T->data)) return 1;
        return 0;
    }else   return 1;
}

int TreeDepth(BiTree T)//求二叉树的深度
{
  int dep1,dep2;
  if(T==NULL) return 0;
  else
  {
    dep1=TreeDepth(T->lchild);
    dep2=TreeDepth(T->rchild);
    if(dep1>dep2) return 1+dep1;
    else
    return 1+dep2;
  }
}
