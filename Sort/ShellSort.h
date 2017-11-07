typedef struct{
    int key;
}Num;

void ShellSort(Num A[], int n){
    int i, j;
    for(int d = n / 2; d >= 1; d /= 2){
        for(i = d + 1; i <= n; i++){
            if(A[i].key < A[i - d].key){
                A[0] = A[i];
                for(j = i - d; j > 0 && A[j].key > A[0].key; j-=d){
                    A[j + d] = A[j];
                }
                A[j + d] = A[0];
            }
        }
    }
}