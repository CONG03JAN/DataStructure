#include "SqList.h"

// ******************* 1. **************************
bool Del_Min(SqList &L, ElemType &e){
	if(L.length == 0){
		cout << "SqList is empty !!!" << endl;
		return false;
	}
	ElemType min = L.data[0];
	int pos = 1;
	for(int i = 2; i <= L.length; i++){
		if(L.data[i - 1] < min){
			min = L.data[i - 1];
			pos = i;
		}
	}
	e = min;
	L.data[pos - 1] = L.data[L.length - 1];
	return true;
}

// ******************* 2. **************************
bool Reverse(SqList &L){
	for(int i = 1; i <= L.length/2; i++){
		ElemType temp = L.data[i - 1];
		L.data[i - 1] = L.data[L.length - i];
		L.data[L.length - i] = temp;
	}
		return true;
}

// ******************* 3. **************************
bool Del_x_l(SqList &L, ElemType x){
	int k = 0;
	for(int i = 1; i <= L.length; i++){
		if(L.data[i - 1] != x){
			L.data[k] = L.data[i - 1];
			k++;
		}
	}
	L.length = k;
	return true;
}

// ******************* 4. **************************
bool Del_s_t(SqList &L, ElemType s, ElemType t){
	if(s > t || L.length == 0){
		return false;
	}
	int i, j;
	for(i = 1; L.data[i - 1] < s; i++);
	if(i > L.length) return false;
	for(j = i; L.data[j - 1] < t; j++);
	for(int k = j + 1; k <= L.length; k++){
		L.data[i - 1] = L.data[k - 1];
		i++;
	}
	L.length = i - 1;
	return true;
}

// ******************* 6. **************************
bool Del_same(SqList &L){
	int k = 0;
	for(int i = 1; i < L.length; i++){
		if(L.data[i] == L.data[k]){
			continue;
		} else {
			L.data[++k] = L.data[i];
		}
	}
	L.length = k + 1;
	return true;
}

// ******************* 7. **************************
bool Merge(SqList &L1, SqList &L2, SqList &L3){
	int i = 0, j = 0, k = 0;
	while(i < L1.length && j < L2.length){
		if(L1.data[i] < L2.data[j]){
			L3.data[k++] = L1.data[i++];
		} else {
			L3.data[k++] = L2.data[j++];
		}
	}
	if(i < L1.length){
		for(; i < L1.length; i++){
			L3.data[k++] = L1.data[i];
		}
		L3.length = k;
		return true;
	}
	if(j < L2.length){
		for(; j < L2.length; j++){
			L3.data[k++] = L2.data[j];
		}
		L3.length = k;
		return true;
	}
	return true;
}

// ******************* 10. **************************



int main(){
	SqList L1, L2, L3;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	
	InsertElem(L1, 1, 1);
	InsertElem(L1, 2, 3);
	InsertElem(L1, 3, 5);
	InsertElem(L1, 4, 7);
	InsertElem(L1, 5, 9);
	InsertElem(L1, 6, 10);

	InsertElem(L2, 1, 2);
	InsertElem(L2, 2, 4);
	InsertElem(L2, 3, 6);
	InsertElem(L2, 4, 8);
	InsertElem(L2, 5, 10);
	InsertElem(L2, 6, 11);

	Merge(L1, L2, L3);

	PrintList(L3);

	return 0;
}
