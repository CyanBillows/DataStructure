//
// Created by DELL on 2022/7/23.
//

#include "Kruscal.h"

/*1.优先队列从小到大存储各个边 O(eloge)
  2.出队最小边,使用并查集判断生成树加入此边后是否成环 O(e)
  3.若成环(v1,v2属于同一根节点)，则跳过;否则合并两点到同一集合
  总体时间复杂度O(eloge)
*/
void Kruscal(){
    priority_queue<Edge,vector<Edge>,greaterEdge> edges;//优先队列从小到大存储边集
    MGraph Gra = BuildGraph(edges);
    for(int i =1;i<=Gra->nV;i++){
        for(int j =1;j<=Gra->nV;j++){
            cout.width(3);
            cout << Gra->G[i][j];
        }
        cout << endl;
    }
    int matchTree[Gra->nV];
    initArray(matchTree,Gra->nV);
    int count = 0;
    while(!edges.empty()){
        Edge e = edges.top();
        edges.pop();
        int findV1 = Find(matchTree,e->v1-1);
        int findV2 = Find(matchTree,e->v2-1);
        if(findV1 != findV2){
            Union(matchTree,e->v1-1,e->v2-1);
            count += e->weight;
            cout << "(" << e->v1 << "," << e->v2 << "): " << e->weight << endl;
        } else {
            continue;
        }
    }
    cout << "count: " << count << endl;
}
