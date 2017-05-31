#ifndef _CALC_H
#define _CALC_H

#define MaxLength 100
#define LEN sizeof(struct node)
#define MAX_TREE_SIZE 100
#define QUEUE_INIT_SIZE 100

typedef struct BiTNode//二叉树
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,* BiTree;



int InitBiTree(BiTree * T);
int print(int e);
void createBiTree(BiTree *T);
int ClearBiTree(BiTree *T);
int DestoryBiTree(BiTree *T);
int BiTreeEmpty(BiTree * T);
int Value(BiTree p);
int Assign(BiTree *T,BiTree *p,int e);
int PreOrderTraverse_1(BiTree T,int(* visit)(int e));
int InOrderTraverse_1(BiTree T,int(* visit)(int e));
int PostOrderTraverse_1(BiTree T,int(* visit)(int e));
int TreeDepth(BiTree T);//求二叉树的深度

#endif //_CALC_H
