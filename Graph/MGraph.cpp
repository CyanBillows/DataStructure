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
//    (Graph->G)[E->v2][E->v1] = E->weight; //����ͼ
}

MGraph BuildGraph(priority_queue<Edge,vector<Edge>,greaterEdge> &q) {
    MGraph Graph;
    int nV, i;
    cout << "�����붥�����:" << endl;
    scanf("%d", &nV);
    Graph = CreateGraph(nV);
    cout << "������߸���:" << endl;
    scanf("%d", &(Graph->nE));
    if (Graph->nE > 0) {
        Edge e = (Edge) malloc(sizeof(ENode));
        for (i = 0; i < Graph->nE; i++) {
            cout << "������ߣ�v1,v2,weight):" << endl;
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

//Ѱ���ڽӵ㲢��� O(V)
void FindNear(MGraph graph,queue<int> &q,int point){
    for(int i = 1;i<=graph->nV;i++){
        int weight = graph->G[point][i];
        if(weight != 0){
            q.push(i);
        }
    }
}

// O(V^2) �ڽӾ���
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
        if(visited[p-1] == 0 ){ //�õ�δ�����ʹ�
            visited[p-1] = 1;
            FindNear(Graph,q,p);
            cout << "point: " << p << endl;
        }
    }
}
//����ͨ��֧����£���ͼ����ͨʱ��DFS����
//����������������(�޷��б���ڻ�·)
//ͨ���޸�visitΪ��״̬���ж��Ƿ�ɻ�������������һ���ڽӵ��Դ��ڷ�����״̬���ʾ�ɻ�
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
//visited[start-1] = 2; 2 ��ʾ���ڷ��ʸõ�
    FindNear(graph,q,start);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        //if(visited[p-1] == 2) �ɻ�����
        if(visited[p-1] == 0){
            DFS(graph,p,visited,q);
        }
    }
//visited[start-1]=1; 1 ��ʾ���ʽ���
    cout << "point: " << start << endl;
}