#include "Sort/SelectSort.h"
#include "iostream"

using namespace std;

int main(){
    Num A[23];
    A[1].key = 13;
    A[2].key = 12;
    A[3].key = 11;
    A[4].key = 10;
    A[5].key = 9;
    A[6].key = 8;
    A[7].key = 7;
    A[8].key = 6;
    A[9].key = 5;
    A[10].key = 4;
    A[11].key = 3;
    A[12].key = 2;
    A[13].key = 1;
    A[14].key = 2;
    A[15].key = 3;
    A[16].key = 4;
    A[17].key = 5;
    A[18].key = 6;
    A[19].key = 7;
    A[20].key = 8;
    A[21].key = 9;
    A[22].key = 10;
    SelectSort(A, 22);
    for(int i = 1; i <= 22; i++){
        cout << A[i].key << endl;
    }
    return 0;
}