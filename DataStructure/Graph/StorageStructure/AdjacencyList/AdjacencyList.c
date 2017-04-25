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
    int i,j,k;
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

int main()
{
    GraphList g;
    CreateGraph(&g);
    printGraph(&g);
    return 0;
}















