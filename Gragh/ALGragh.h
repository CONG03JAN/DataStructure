#include "cstdlib"
#include "iostream"

using namespace std;

typedef int VertexType;

#define MaxVertexNum 100
typedef struct ArcNode{
    int adjvex;
    ArcNode *next;
    int info;
}ArcNode;
typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGragh;


bool InitGragh(ALGragp &G){
    G.vexnum = 0; 
    G.arcnum = 0;
    return true; 
}

bool Adjacent(ALGragh G, int x, int y){
    ArcNode *arc = G.vertices[x].first;
    while(arc != NULL){
        if(arc->adjvex == y) return true;
        else arc = arc->next;
    }
    return false;
}

bool InsertVertex(ALGragh &G, int x){
    G.vertices[++vexnum].data = x;
    G.vertices[vexnum].first = NULL;
    return true;
}

bool AddEdge(ALGragh &G, int x, int y){
    if(adjacent(G, x, y)) return false;
    ArcNode *arc = (ArcNode *)(malloc(sizeof(ArcNode)));
    arc->next = G.vertices[x].first->next;
    G.vertices[x].first = arc;
    return true;
}

int FirstNeighbor(ALGragh G, int x){
    return G.vertices[x].first->adjvex;
}

