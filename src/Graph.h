typedef struct VertexType{
    char c;
};
typedef struct WeightType {
    char c;
};
//邻接矩阵的类型定义
typedef struct gp{
    char vexs[20]; //顶点信息
    int arcs[20][20]; //邻接矩阵
    int vexnum, arcnum; //顶点数 边数
} WGraph;

/***
adj表示一个矩阵的伴随矩阵
邻接表：
定义：对图G中每个顶点都建立一个单链表，第i个单链表（称边表）链接图中与顶点Vi相邻接的所有顶点。
adjvex——邻接点域（顶点域）：存放与顶点Vi相邻接顶点Vj的序号j；
nextarc——链域：指向Vi的下一个邻接点；

每个链表均设一表头结点（以向量存储，称顶点表）
表头结点： vertex firstarc
V[i]—第i个链表的表头结点；
V[i].vertex — 存放顶点Vi的信息；
V[i].firstarc — 指向Vi的邻接链表的第一个结点。

1）n个顶点、e条边的无向图，则其邻接表的表头结点数为n，
链表结点总数为2e； 
2）对于无向图，第i个链表的结点数为顶点Vi的度；
对于有向图，第i个链表的结点数为顶点Vi的出度；
3）在边稀疏时，邻接表比邻接矩阵省单元；
4）邻接表表示在检测边数方面比邻接矩阵表示效率要高。
 * **/
typedef struct arcnode{
    int adjvex; //下一条边的顶点编号
    struct arcnode *nextarc; //指向下一条边的指针。
    int weight; //带权图的权值
} ArcNode;
typedef struct vexnode{
    int vertex; //顶点编号
    ArcNode* firstarc; //指向第一条边
} AdjList[20];
typedef struct gpTable{
    int vernum, arcnum; //顶点数/边数
    AdjList adjlist;
} GPTable;