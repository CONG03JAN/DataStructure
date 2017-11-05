bool visited[MaxVexNum]

void DFSTraverse(Gragh G){
    for(int i = 0; i < G.vexnum; i++){
        visited[i] = false;
    }
    for(int i = 0; i < G.vexnum; i++){
        if(!visited[i]){
            DFS(G, i);
        }
    }
}

void DFS(Gragh G, int v){
    visit(v);
    visited[v] = true;
    for(int n = FirstNeighbor(G, v); n >= 0; n = NextNeighbor(G, v, n)){
        DFS(G, n);
    }
}