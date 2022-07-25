//
// Created by DELL on 2022/7/23.
//

#include "Dijkstra.h"

void init(int a[],int n,int num){
    int i;
    for(i=0;i<n;i++){
        a[i] = num;
    }
}
//1.初始化数组path(各点前驱节点),final(初始点到该点的最短路径是否确定),dis(初始点到该点的最短路径)
//2.n-1轮处理: 遍历所有顶点，找到还没确定最短路径，且dis最小的顶点vi,令final[i]=true,并检查所有邻接自vi的顶点
//  vj,若final[j] == false && dis[i]+arcs[i][j](vi到vj的边权值) < dis[j]，
//  则令dis[j] = dis[i]+arcs[i][j];path[j]=i;
void Dijkstra(MGraph graph,int start){ //start最小为1
    int path[graph->nV],final[graph->nV],dis[graph->nV];
    init(path,graph->nV,-1); //前驱节点
    init(final,graph->nV,0); //是否确定最短路径
    init(dis,graph->nV,INT_MAX); //路径大小
    final[start-1] = 1;
    dis[start-1] = 0;
    for(int i = 1;i<=graph->nV;i++){ //找到初始点的邻接点，更新路径权重和前驱节点
        int weight = graph->G[start][i];
        if(weight != 0){
            dis[i-1] = weight;
            path[i-1] = start-1;
        }
    }
    int findAll = 0;
    while(!findAll){
        int min = INT_MAX;
        int index;
        for(int j = 0;j<graph->nV;j++){ //遍历寻找还没确定最短路径，且dis最小的邻接点vi
            if(final[j] == 0 && dis[j] <= min){
                min = dis[j];
                index = j;
            }
        }
        final[index] = 1;
        for(int i = 1;i<=graph->nV;i++){ //遍历vi的邻接点，更新路径权重和前驱节点
            int weight = graph->G[index+1][i];
            if(weight != 0){
                if( dis[index] + weight < dis[i-1]) { //通过最新确立的最短路径到达的代价小于之前的路径时
                    dis[i-1] = weight + dis[index];
                    path[i-1] = index;
                }
            }
        }
        findAll = 1;
        for(int k = 0;k<graph->nV;k++){ //若未找全最短路径，则继续循环
            if(final[k] == 0) {
                findAll=0;
                break;
            }
        }
    }
    for(int i = 0;i<graph->nV;i++){
        cout << "dis[" << i << "]: " << dis[i] << endl;
    }
}