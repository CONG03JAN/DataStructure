#include "cstdlib"
#include "iostream"

using namespace std;

#define MaxVertexNum 100
typedef int VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGragh;

bool InitGragh(MGragh G){
    G.vexnum = 0;
    G.arcnum = 0;
    return true;
}

bool Adjacent(MGragh G, int x, int y){
    return G.Edge[x][y] == 1;
}

bool InsertVertex(MGragh &G, int x){
    G.Vex[++vexnum] = x;
    return true;
}

bool AddEdge(MGragh &G, int x, int y){
    if(Adjacent[G, x, y]) return false;
    G.Edge[x][y] = 1;
    G.arcnum++;
    return true;
}

int FirstNeighbor(MGragh G, int x){
    for(int i = 1; i <= G.vexnum; i++){
        if(G.Edge[x][i] == 1) return i;
    }
    return -1;
}

int NextNeighbor(MGragh G, int x, int y){
    for(int i = y + 1; i <= G.vexnum; i++){
        if(G.Edge[x][i] == 1) return i;
    }
    return -1;
}

