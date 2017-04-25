//
//  Queue.h
//  AdjacencyList
//
//  Created by 李家豪 on 2017/4/25.
//  Copyright © 2017年 koogong. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#define TRUE 1
#define FASLE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define QUEUEEMPTY -3

typedef int Status;
typedef int ElemType;


typedef struct LNode {
    ElemType elem;
    struct LNode *next;
}Node,*LinkList;

typedef struct queue {
    LinkList front;
    LinkList rear;
}QUEUE;

void InitQueue(QUEUE *Q);
void EnQueue (QUEUE *Q,ElemType elem);
void DeQueue (QUEUE *Q,ElemType *elem);
void GetFront (QUEUE *Q,ElemType *elem);
Boolean QueueEmpty (QUEUE Q);


void InitQueue (QUEUE *Q)
{
    Q->front = (LinkList)malloc(sizeof(Node));
    if(Q->front == NULL) exit(ERROR);
    Q->rear = Q->front;
}

void EnQueue (QUEUE *Q,ElemType elem)
{
    LinkList s;
    s = (LinkList)malloc(sizeof(Node));
    if(!s) exit(ERROR);
    s->elem = elem;
    s->next = NULL;
    Q->rear ->next = s;
    Q->rear = s;
}

void DeQueue (QUEUE *Q,ElemType *elem)
{
    LinkList s;
    if(QueueEmpty(*Q))exit(ERROR);
    
    *elem = Q->front->next->elem;
    
    s = Q->front ->next;
    Q->front ->next = s->next;
    free(s);
}

void GetFront1 (QUEUE Q,ElemType *elem)
{
    if(QueueEmpty(Q))exit(ERROR);
    *elem = Q.front->next ->elem;
}

Boolean QueueEmpty (QUEUE Q)
{
    if(Q.front == Q.rear) return TRUE;
    return FASLE;
}



#endif /* Queue_h */
