typedef struct{
    int key;
}Num;

void BubbleSort(Num A[], int n){
    for(int i = 1; i < n; i++){
        bool flag = false;
        for(int j = n; j > i; j--){
            if(A[j].key < A[j - 1].key){
                Num temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = true;
            }
        }
        if(!flag) return;
    }
}