#include <stdio.h>
#include <malloc.h>

#include "include/Tree.h"
#include "include/Queue.h"
#include "include/Stack.h"

#define MAXSIZE 100
typedef struct//栈
{
    int *base;
    int *top;
    int  stacksize;
}Sqstack;


typedef struct //队列
{
    int front;
    int rear;
    int **queue;
}sq;



void StackTest(){
    Sqstack S;
    int i,x;
    InitStack(&S);
    int len;
    printf("请输入需要生成的长度:\n");
    scanf("%d",&len);
    int t[len];
    printf("请输入元素数值：\n");
    for(i=0;i<len;i++)
    {
        scanf("%d",&t[i]);
        Push(&S,t[i]);
    }
    printf("是否栈空（1->空  0->不空）：");
    printf("%d\n",StackEmpty(&S));

    printf("此时栈为：");
    PrintStack(&S);

    printf("删除栈中元素：\n");
    Pop(&S,&x);
    printf("%d\n",x);
    Pop(&S,&x);
    printf("%d\n",x);

    printf("取栈顶：");
    Gettop(&S,&x);
    printf("%d\n",x);

    printf("此时栈为：");
    PrintStack(&S);
    printf("此时栈的长度为：");
    printf("%d\n",StackLength(S));

    ClearStack(&S);
    DestoryStack(&S);
}

    
void QueueTest()
{
    sq Q;
    sq *q=NULL;
    q=&Q;
    InitQuene(q);
    int len;
    printf("请输入需要生成的队的长度：");
    scanf("%d",&len);
    Generate(len,q);
    printf("以下是原队的内容：");
    QueneTraverse(q);
    printf("队列是否为空（0为非空，1为空）：%d\n",QueneEmpty(q));
    int e;
    DeQuene(q,&e);
    printf("以下是删除操作后队的内容：");
    QueneTraverse(q);
    printf("队中被删的队头元素是：%d\n",e);
    printf("请输入要插入队中的元素：");
    scanf("%d",&e);
    EnQuene(e,q);
    printf("以下是插入操作后队的内容：");
    QueneTraverse(q);
    printf("队头元素是%d\n",GetHead(q));
    printf("队长是%d\n",QueneLength(q));
    ClearQuene(q);
    printf("以下是清空队操作后队的内容：");
    QueneTraverse(q);
    printf("队列是否为空（0为非空，1为空）：%d\n",QueneEmpty(q));
    DestroyQuene(q);
}


void TreeTest()
{
    BiTree T,q,c;
    printf("请先序输入一棵二叉树：\n");
    createBiTree(&T);
    InitBiTree(&c);
    int len;
    len=TreeDepth(T);
    printf("二叉树的深度:%d\n",len);
    if(!BiTreeEmpty(&T))
    {   q=T->lchild;q=q->rchild;//定一个q
        printf("先序遍历：");       
        PreOrderTraverse_1(T,print);printf("\n");//先序
        printf("中序遍历：");
        InOrderTraverse_1(T,print);printf("\n");//中序
        printf("后序遍历：");
        PostOrderTraverse_1(T,print);printf("\n");//后序
        printf("q结点的值：");
        printf("%d\n",Value(q));//打印
        Assign(&T,&q,10);//给q赋值10
        PreOrderTraverse_1(T,print);printf("\n");
        ClearBiTree(&T);
    }
}



int main(){
   printf("stack:\n");
   StackTest();
	printf("\n");

   printf("queque:\n");
   QueueTest();
   printf("\n");

   printf("tree:\n");
   TreeTest();
   printf("\n");
   return 0;
}
