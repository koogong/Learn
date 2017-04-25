//
//  main.c
//  AdjacencyList
//
//  Created by 李家豪 on 2017/4/24.
//  Copyright © 2017年 koogong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define DEBUG
#define MAXVEX 1000             //最大顶点数

typedef char VertexType;        //顶点类型应由用户定义
typedef int EdgeType;           //边上的权值类型应由用户定义

typedef struct EdgeNode         //边表结点
{
    int adjvex;             //邻接点域，存储该顶点对应的下标
    EdgeType weigth;        //用于存储权值，对于非网络图可以不需要
    struct EdgeNode *next;  //链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode       //顶点表结构
{
    VertexType data;            //顶点域，存储顶点信息
    EdgeNode *firstedge;        //边表头指针
}VertexNode,AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges;   //图中当前顶点数和边数
}GraphList;

int Locate ( GraphList *g , char ch)
{
    int i;
    for ( i = 0 ; i < MAXVEX ; i++)
    {
        if ( ch == g->adjList[i].data)
            break;
    }
    if ( i >= MAXVEX)
    {
        fprintf(stderr, "there is no vertex.\n");
        return -1;
    }
    return i;
}

//建立图的邻接表结构
void CreateGraph ( GraphList *g)
{
    int i,k;
    EdgeNode *e;
    EdgeNode *f;
    printf("输入顶点数和边数：\n");
    scanf("%d%d",&(g->numVertexes),&(g->numEdges));
    
#ifdef DEBUG
    printf("%d,%d\n",g->numVertexes,g->numEdges);
#endif 
    
    for ( i = 0 ; i < g->numVertexes ; i++)
    {
        printf("请输入顶点%d：\n",i);
        g->adjList[i].data = getchar();     //输入顶点信息
        g->adjList[i].firstedge = NULL;     //将边表设为空表
        while ( g->adjList[i].data == '\n')
            g->adjList[i].data = getchar();
    }
    
    //建立边表
    for ( k = 0 ; k < g->numEdges ; k++)
    {
        printf("输入边（vi，vj）上的顶点序号：\n");
        char p,q;
        p = getchar();
        while ( p == '\n')
            p = getchar();
        
        q = getchar();
        while ( q == '\n')
            q = getchar();
        
        int m,n;
        m = Locate(g, p);
        n = Locate(g, q);
        if ( m == -1 || n == -1)
            return;
        
#ifdef DEBUG 
        printf("p = %c \n",p);
        printf("q = %c \n",q);
        printf("m = %d \n",m);
        printf("n = %d \n",n);
#endif
        
        //向内存申请空间，生成边表结点
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        if ( e == NULL)
        {
            fprintf(stderr, "malloc() error.\n");
            return;
        }
        
        //邻接序号为 j
        e->adjvex = n;
        
        //将 e 指针指向当前顶点指向的结构
        e->next = g->adjList[m].firstedge;
        
        //将当前顶点的指针指向 e
        g->adjList[m].firstedge = e;
        
        f = (EdgeNode *)malloc(sizeof(EdgeNode));
        if ( f == NULL)
        {
            fprintf(stderr, "malloc() error.\n");
            return;
        }
        f->adjvex = m;
        f->next = g->adjList[n].firstedge;
        g->adjList[n].firstedge = f;
    }
}




void printGraph ( GraphList *g)
{
    int i = 0;
#ifdef DEBUG
    printf("printGraph() start.\n");
#endif
    
    while ( g->adjList[i].firstedge != NULL && i < MAXVEX)
    {
        printf("顶点：%c ",g->adjList[i].data);
        
        EdgeNode *e = NULL;
        
        e = g->adjList[i].firstedge;
        
        while ( e != NULL)
        {
            printf("%d ",e->adjvex);
            e = e->next;
        }
        i++;
        printf("\n");
    }
}



//================================================
//深度优先遍历 Deep First Search
//================================================

typedef int Boolean;
Boolean visited[MAXVEX];
#define TRUE 1
#define FALSE 0

//邻接表的深度递归算法
void DFS ( GraphList g,int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ",g.adjList[i].data);        //打印顶点，也可以其他操作
    p = g.adjList[i].firstedge;
    while ( p )
    {
        if ( !visited[p->adjvex])
            DFS(g, p->adjvex);              //对访问的邻接顶点递归调用
        
        p = p->next;
    }
}

//邻接表的深度遍历操作
void DFSTraverse ( GraphList g)
{
    int i;
    for ( i = 0 ; i < g.numVertexes ; i++)
        visited[i] = FALSE;
    
    for ( i = 0 ; i < g.numVertexes ; i++)
    {
        if ( !visited[i])
            DFS(g, i);
    }
}



//================================================
//广度优先遍历 Breadth First Search
//================================================
#include "Queue.h"

void BFSTraverse ( GraphList g)
{
    int i;
    EdgeNode *p;
    QUEUE q;
    for ( i =0 ; i < g.numVertexes ; i++)
        visited[i] = FALSE;
    
    InitQueue(&q);
    for ( i = 0 ; i < g.numVertexes ; i++)//对每个顶点做循环
    {
        if ( !visited[i])       //若是未访问过
        {
            visited[i] = TRUE;
            printf("%c ",g.adjList[i].data);  //打印结点，也可以其他操作
            EnQueue(&q, i);
            while ( !QueueEmpty(q))
            {
                int m;
                DeQueue(&q, &m);
                p = g.adjList[m].firstedge;
                while ( p )
                {
                    if ( !visited[p->adjvex])
                    {
                        visited[p->adjvex] = TRUE;
                        printf("%c ",g.adjList[p->adjvex].data);
                        EnQueue(&q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
    
}



int main()
{
    GraphList g;
    CreateGraph(&g);
    //printGraph(&g);
    printf("Deep First Search:\n");
    DFSTraverse(g);
    printf("\n");
    
    printf("Breadth First Search:\n");
    BFSTraverse(g);
    printf("\n");
    return 0;
}















