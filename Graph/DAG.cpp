//
// Created by DELL on 2022/7/24.
//

#include "DAG.h"

//初始化入度数组
void initIndegree(MGraph graph,int degree[]){
    for (int i = 0; i < graph->nV; ++i) {
        degree[i] = 0;
    }
    for (int i = 1; i <= graph->nV; ++i) {
        for (int j = 1; j <= graph->nV; ++j) {
            if(graph->G[i][j] > 0)
                degree[j-1] += 1;
        }
    }
}
// 1.初始化所有点的入度Indegree，并将入度为0的点入队
// 2.出队点vi，遍历vi的邻接点，减少邻接点的入度(逻辑上删除Vi到达该点的边)。
// 3.判断入度减少后是否为0，若是则入队。
// 4.重复2,3直到队列为空
// 5.判断是否存在环路，每次出队采用count计数，若count<VertexNum，则说明存在环路
// 邻接矩阵O(V^2)，邻接表O(V+E)
void TopoLogicSort(MGraph graph){
    queue<int> q;
    int Indegree[graph->nV];
    int count = 0;
    initIndegree(graph,Indegree);
    for(int i = 0;i<graph->nV;++i){ //遍历所有点，将入度为0的入队
        if(Indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int index = q.front(); //出队入度为0的点vindex
        q.pop();
        cout << index+1 << endl;
        count++;
        for(int i = 1;i <= graph->nV;++i){ //遍历vindex的邻接点，减少其入度(删除相连边)
            if(graph->G[index+1][i] > 0) {
                if(--Indegree[i-1] == 0){
                    q.push(i-1);
                }
            }
        }
    }
    if(count < graph->nV){
        cout << "有环路" << endl;
    }
}



