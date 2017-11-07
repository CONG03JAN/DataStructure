typedef struct{
    int key;
}Num;

void BiInsertSort(Num A[], int n){
    int i, j, low, high, mid;
    for(i = 2; i <= n; i++){
        if(A[i].key < A[i - 1].key){
            low = 1; high = i - 1;
            A[0] = A[i];
            while(low <= high){
                mid = (low + high) / 2;
                if(A[mid].key > A[0].key) high = mid - 1;
                else low = mid + 1;
            }
            for(j = i - 1; j >= high + 1; j--){
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0];
        }
    }
}