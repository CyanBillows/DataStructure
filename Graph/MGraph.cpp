//
// Created by DELL on 2022/7/23.
//

#include "MGraph.h"

MGraph CreateGraph(int VertexNum){
    MGraph ptr;
    ptr = (MGraph)(malloc(sizeof(struct GNode)));
    ptr->nV = VertexNum;
    ptr->nE = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            (ptr->G)[i][j] = 0;
        }
    }
    return ptr;
}

void InsertEdge(MGraph Graph,Edge E){
    (Graph->G)[E->v1][E->v2] = E->weight;
//    (Graph->G)[E->v2][E->v1] = E->weight; //无向图
}

MGraph BuildGraph(priority_queue<Edge,vector<Edge>,greaterEdge> &q) {
    MGraph Graph;
    int nV, i;
    cout << "请输入顶点个数:" << endl;
    scanf("%d", &nV);
    Graph = CreateGraph(nV);
    cout << "请输入边个数:" << endl;
    scanf("%d", &(Graph->nE));
    if (Graph->nE > 0) {
        Edge e = (Edge) malloc(sizeof(ENode));
        for (i = 0; i < Graph->nE; i++) {
            cout << "请输入边（v1,v2,weight):" << endl;
            scanf("%d,%d,%d", &(e->v1), &(e->v2), &(e->weight));
            InsertEdge(Graph, e);
            Edge tmp = (Edge) malloc(sizeof(ENode));
            tmp->v1 = e->v1;
            tmp->v2 = e->v2;
            tmp->weight = e->weight;
            q.push(tmp);
        }
    }
    return Graph;
}

//寻找邻接点并入队 O(V)
void FindNear(MGraph graph,queue<int> &q,int point){
    for(int i = 1;i<=graph->nV;i++){
        int weight = graph->G[point][i];
        if(weight != 0){
            q.push(i);
        }
    }
}

// O(V^2) 邻接矩阵
void BFS(MGraph Graph,int point){
    queue<int> q;
    int visited[Graph->nV];
    for(int i = 0;i<Graph->nV;i++){
        visited[i] = 0;
    }
    visited[point-1] = 1;
    cout << "point: " << point << endl;
    FindNear(Graph,q,point);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(visited[p-1] == 0 ){ //该点未被访问过
            visited[p-1] = 1;
            FindNear(Graph,q,p);
            cout << "point: " << p << endl;
        }
    }
}
//多连通分支情况下，即图不连通时的DFS方案
//可用于逆拓扑排序(无法判别存在环路)
//通过修改visit为三状态可判断是否成环，若访问中下一个邻接点仍处于访问中状态则表示成环
void DFSTraverse(MGraph graph){
    int visited[graph->nV];
    queue<int> q;
    for (int i = 0; i < graph->nV; ++i) {
        visited[i] = 0;
    }
    for(int i = 1;i<=graph->nV;++i){
        if(visited[i-1] == 0)
            DFS(graph,i,visited,q);
    }
}

// O(V^2)
void DFS(MGraph graph,int start,int visited[],queue<int> &q){
    visited[start-1] = 1;
//visited[start-1] = 2; 2 表示正在访问该点
    FindNear(graph,q,start);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        //if(visited[p-1] == 2) 成环条件
        if(visited[p-1] == 0){
            DFS(graph,p,visited,q);
        }
    }
//visited[start-1]=1; 1 表示访问结束
    cout << "point: " << start << endl;
}