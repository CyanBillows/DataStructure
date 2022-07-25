//
// Created by DELL on 2022/7/24.
//

#include "DAG.h"

//��ʼ���������
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
// 1.��ʼ�����е�����Indegree���������Ϊ0�ĵ����
// 2.���ӵ�vi������vi���ڽӵ㣬�����ڽӵ�����(�߼���ɾ��Vi����õ�ı�)��
// 3.�ж���ȼ��ٺ��Ƿ�Ϊ0����������ӡ�
// 4.�ظ�2,3ֱ������Ϊ��
// 5.�ж��Ƿ���ڻ�·��ÿ�γ��Ӳ���count��������count<VertexNum����˵�����ڻ�·
// �ڽӾ���O(V^2)���ڽӱ�O(V+E)
void TopoLogicSort(MGraph graph){
    queue<int> q;
    int Indegree[graph->nV];
    int count = 0;
    initIndegree(graph,Indegree);
    for(int i = 0;i<graph->nV;++i){ //�������е㣬�����Ϊ0�����
        if(Indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int index = q.front(); //�������Ϊ0�ĵ�vindex
        q.pop();
        cout << index+1 << endl;
        count++;
        for(int i = 1;i <= graph->nV;++i){ //����vindex���ڽӵ㣬���������(ɾ��������)
            if(graph->G[index+1][i] > 0) {
                if(--Indegree[i-1] == 0){
                    q.push(i-1);
                }
            }
        }
    }
    if(count < graph->nV){
        cout << "�л�·" << endl;
    }
}



