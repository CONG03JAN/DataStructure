bool visited[MaxVexNum];

void BFSTraverse(Gragh G){
    for(int i = 0; i < G.vexnum; i++){
        visited[i] = false;
    }
    Queue Q;
    InitQueue(Q);
    for(int i = 0; i < G.vexnum; i++){
        if(!visited[i]){
            BFS(G, i);
        }
    }
}

void BFS(Gragh G, int v){
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);
    while(!IsEmpty(Q)){
        DeQueue(Q, v);
        for(int n = FirstNeighbor(G, v); n >= 0; n = NextNeighbor(G, v, n)){
            if(!visited[n]){
                visit(n);
                visited[n] = true;
                EnQueue(Q, n);
            }
        }
    }
}
