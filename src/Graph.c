#include "Graph.h";
#include <stdio.h>
#include <limits.h>
/**
建立无向带权邻接矩阵
将矩阵A的每个元素都初始化为最大值。然后读入边和权值（i，j，wij），将A的相应元素设为wij。算法如下：
vertex是顶点的意思
arc是弧
**/
int createGraph(WGraph *g)
{
    int i, j, an, vn, w;
    char ch;
    scanf("%d, %d", an, vn);
    g->arcnum = an;
    g->vexnum = vn;
    for (i = 0; i < g->vexnum; i++)
    {
        scanf("%c", &ch);
        g->vexs[i] = ch;
    }
    for (i = 0; i < g->vexnum; i++)
    {
        for (j = 0; j < g->vexnum; j++)
        {
            g->arcs[i][j] = INT_MAX;
        }
    }
    for (int k = 0; k < g->arcnum; k++)
    {
        scanf("%d, %d, %c", &i, &j, &w);
        //读入顶点坐标和权值，无向带权图的邻接矩阵是对称矩阵
        g->arcs[i][j] = w;
        g->arcs[j][i] = w;
    }
}

/**
遍历的含义及方法：
●图的遍历——从图G中某一顶点v出发，顺
序访问各顶点一次。
●方法：
深度优先搜索法 类似先序遍历DFS
广度优先搜索法 类似层次遍历
为克服顶点的重复访问，设立辅助数组visited[n]。1 顶点i已被访问过0 顶点i未被访问过

Dfs (Graph g, int v){ 
访问 v；
visited[v]=1; // visited[v]初值都为0，顶点v已被访问，就置为1
找出g中v的第一个邻接点w；
while (w存在){ 
if w 未被访问Dfs(g,w);
w=g中v的下一个邻接点；} 
}
   1  V1 1

V2  1 V4   V3 

 1 V5 1 V6 1
从V1出发, DFS:
V1，V2， V4， V5， V3，V6
 **/

//深度优先搜索法算法： 对图按深度优先遍历的递归算法（邻接表）
int visited[20];
int GraphDFS(GPTable gp, int v)
{ //从第v个顶点出发递归地深度优先遍历图g，图以邻接表作为存储结构
    ArcNode *p;
    printf("%d", v);
    /* 访问起始顶点v*/
    visited[v] = 1;             /* 置“已访问”标记*/
    p = gp.adjlist[v].firstarc; /* 取顶点表中v的边表头指针*/
    while (p != NULL)           /* 依次搜索v的邻接点*/
    {
        if (!visited[p->adjvex]) /*v的一个邻接点未被访问*/
            Dfs(gp, p->adjvex);  /*沿此邻接点出发继续DFS*/
        p = p->nextarc;          /* 取v的下一个邻接点*/
    }
}

/**
 * 对图按深度优先遍历的递归算法（邻接矩阵）：
 * **/
void ArrayGraphDFS(WGraph gp, int v)
{
    //从第v个顶点出发递归地深度优先遍历图g，图以邻接矩阵作为存储结构
    visited[v] = 1;  /* 置“已访问”标记*/
    printf("%d", v); /* 访问起始顶点v*/
    for (int i = 0; i < gp.vexnum; i++)
    {                          /* 顶点数，j为顶点编号*/
        int m = gp.arcs[v][i]; /*顺序访问矩阵的第v行结点*/
        if (m && !visited[i])
        {                         /*如果v与j邻接，且j未被访问*/
            ArrayGraphDFS(gp, i); /*递归访问j*/
        }
    }
}

//void 对图按广度优先遍历的算法：
// ▲广度优先遍历算法基本思想：
// 1. 所有结点标记置为“未被访问”标志；
// 2. 访问起始顶点，同时置起始顶点“已访问”标记; 3. 将起始顶点进队列；
// 4. 当队列不为空时重复执行以下步骤；
// 1）取当前队头顶点；
// 2）对与队头顶点相邻接的所有未被访问过的顶点依次做：
// (a)访问该顶点；
// (b)置该顶点为“已访问”标记,并将它进队列；
// 3）当前队头元素顶点出队；
// 4）重复进行，直到队空时结束。

// 从顶点v出发，按广度优先遍历图g，图用邻接表表示
void bfs(GPTable g, int v)
{
    printf("%d", v);
    ArcNode *p;
    int visited[v]; /*访问初始顶点vi*/
    visited[v] = 1;
    int rear = 1;
    int front = 0;
    int queue[rear];
    queue[rear] = 1; /* 起始顶点（序号）入队*/
    while (front != rear)
    {                              /*队列不空，则循环*/
        front = (front + 1) % 20;  /*置队头*/
        v = queue[front];          /* 队头元素出队*/
        p = g.adjlist[v].firstarc; /*取刚出队顶点v的边表的头指针*/
        while (p != NULL)
        { /* 依次搜索v的邻接点*/
            {
                if (!visited[p->adjvex]) /*v的一个邻接点未被访问*/
                {
                    printf("%d", p->adjvex); /*访问此邻接点*/
                    visited[p->adjvex] = 1;
                    rear = (rear + 1) % 20;  /*队尾指针增1*/
                    queue[rear] = p->adjvex; /*访问过的顶点入队*/
                }
                p = p->nextarc;
            } /* 找v的下一个邻接点*/
        }
    } /*bfs*/
}
//连通图的广度优先搜索
// void Bfs(GPTable g, int v)
// {
//     LkQue Q; //Q为链队列
//     int j;
//     InitQueue(&Q);
//     printf("%d", v); //v为访问的起始结点
//     visited[v] = 1;  //访问过的标志
//     EnQueue(&Q, v);
//     while (!EmptyQueue(Q)) //判队列是否为空
//     {
//         v = Gethead(&Q);
//         OutQueue(&Q);           //出队列
//         for (j = 0; j < n; j++) //n为顶点数，变化j依次尝试v的可能邻接点
//         {
//             m = g->arcs[v][j];
//             if (m && !visited[j]) //判断是否邻接点，且未被访问
//             {
//                 printf("%d", j);
//                 visited[j] = 1; //置被访问标志
//                 EnQueue(&Q, j); //邻接点入队列
//             }
//         }
//     }
// }


/**
最小生成树定义
给定一个带权图，构造带权图的一棵生成树，
使树中所有边的权总和为最小(n-1)。
最小生成树的构造算法: Prim算法和kruskal算法
**/

/**
最小生成树的构造方法（Prim法）
基本思想：
假设G=(V,E)是一个无向带权图，生成的最小生成树为MinT=(V,T),
其中V为顶点的集合，T为边的集合。求T的步骤如下：
1. 初始化U={u0}，T={ }；其中U为一个新设置的顶点的集合，初
始U中只含有顶点u0，这里假设在构造最小生成树时，从顶点u0
出发；
2. 对所有u∈U，v∈V-U(其中u，v表示顶点)的边(u,v)中，找一条
权最小的边(u’,v’)，将这条边加入到集合T中，将顶点v’加入到
集合U中；
3. 如果U=V，则算法结束；否则重复2、3步。
**/