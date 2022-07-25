//
// Created by DELL on 2022/7/24.
//

#include "Floyd.h"
/* 1.初始化距离矩阵dis和前驱节点矩阵path
 * 2.遍历所有路径v[j]到v[k]，允许在v0..vi中转的情况下,计算v[j][k] < v[j][i] + v[i][k]
 *   若满足则距离dis[j][k] = v[j][i] + v[i][k],前驱path[j][k] = i
 *   空间复杂度: O(V^2),时间复杂度: O(V^3)
 * 注: 需要注意dis矩阵的特殊权值初始化，考虑两点不可达的情况。
*/
void Floyd(MGraph graph){
    int dis[graph->nV][graph->nV];
    int path[graph->nV][graph->nV];
    for(int i = 1;i <= graph->nV;i++){
        for (int j = 1; j <= graph->nV; ++j) {
            if(j == i){
                dis[i-1][j-1] = 0;
            } else if(graph->G[i][j] == 0){
                dis[i-1][j-1] = INFINITY; //不可达
            } else {
                dis[i-1][j-1] = graph->G[i][j];
            }
            path[i-1][j-1] = -1;
        }
    }
    for(int i = 0;i < graph->nV;i++){ //vi为中转点
        for (int j = 0; j < graph->nV; ++j) {
            for (int k = 0; k < graph->nV; ++k) {
                if(dis[j][k] > dis[j][i] + dis[i][k] && dis[j][i] != INFINITY && dis[i][k]!=INFINITY){ //vjvi和vivk不能不可达
                    dis[j][k] = dis[j][i] + dis[i][k];
                    path[j][k] = i;
                }
            }
        }
    }
    for (int i = 0; i < graph->nV; ++i) {
        for (int j = 0; j < graph->nV; ++j) {
            cout.width(3);
            if(dis[i][j] == INFINITY){
                cout << "I";
            } else {
                cout << dis[i][j];
            }
        }
        cout << endl;
    }
}