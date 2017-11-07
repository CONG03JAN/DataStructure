typedef struct{
    int key;
}Num;

void InsertSort(Num A[], int n){
    int i, j;   
    for(i = 2; i <= n; i++){
        if(A[i].key < A[i - 1].key){
            A[0] = A[i];
            for(j = i - 1; A[j].key > A[0].key; j--)
                A[j + 1] = A[j];
            A[j + 1] = A[0];
        }
    }
}
