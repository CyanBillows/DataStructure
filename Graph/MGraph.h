//
// Created by DELL on 2022/7/23.
//

#ifndef MST_MGRAPH_H
#define MST_MGRAPH_H

#define N 10
#include <queue>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;
typedef struct GNode{
    int nV; //顶点数
    int nE;  //边数
    int G[N][N]; //邻接矩阵(权重)
}*MGraph;

typedef struct ENode{
    int v1,v2; //邻接点
    int weight; //边权重
}*Edge;

struct greaterEdge //重写仿函数
{
    bool operator() (Edge a, Edge b)
    {
        return a->weight > b->weight; //小顶堆
    }
};

MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph,Edge E);
MGraph BuildGraph(priority_queue<Edge,vector<Edge>,greaterEdge> &q);
void FindNear(MGraph graph,queue<int> &q,int point);
void BFS(MGraph Graph,int point);
void DFS(MGraph graph,int start,int visited[],queue<int> &q);
void DFSTraverse(MGraph graph);
#endif //MST_MGRAPH_H
