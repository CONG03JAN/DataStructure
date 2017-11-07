typedef struct{
    int key;
}Num;

void SelectSort(Num A[], int n){
    for(int i = 1; i <= n; i++){
        int min = A[i].key;
        int pos = i;
        for(int j = i + 1; j <= n; j++){
            if(A[j].key < min){
                pos = j;
                min = A[j].key;
            }
        }
        if(pos != i){
                Num temp = A[i];
                A[i] = A[pos];
                A[pos] = temp;
        }
    }
}