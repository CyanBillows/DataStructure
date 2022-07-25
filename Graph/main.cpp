#include "Dijkstra.h"
#include "Floyd.h"
#include "DAG.h"
using namespace std;

int main() {
    priority_queue<Edge,vector<Edge>,greaterEdge> edges;
    MGraph Gra = BuildGraph(edges);
    TopoLogicSort(Gra);

    DFSTraverse(Gra);
}
