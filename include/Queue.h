#ifndef _CALC_H
#define _CALC_H

#define MAXSIZE 100
typedef struct
{
  int front;
  int rear;
  int *quene;
}sq;

int InitQuene(sq *q);
int Generate(int len,sq *q);
void DestroyQuene(sq *q);
void ClearQuene(sq *q);
int QueneEmpty(sq *q);
int QueneFull(sq *q);
int QueneLength(sq *q);
int GetHead(sq *q);
void EnQuene(int x,sq *q);
void DeQuene(sq *q,int *e);
void QueneTraverse(sq *q);

#endif //_CALC_H
