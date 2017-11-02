#include "cstdlib"

typedef int ElemType;

#define MaxSize 50
typedef struct{
	ElemType data[MaxSize];
	int length;
}SqList;

// 1. InitList(&L)
bool InitList(SqList &L){
	L.length = 0;
	return true;
}

// 2. length(L)
int length(SqList L){
	return L.length;
}

// 3. Empty(L)
bool Empty(SqList L){
	return L.length == 0;
}

// 4. locateElem(L, e, &pos)
bool LocateElem(SqList L, ElemType e, int &pos){
	for(int i = 1; i <= L.length; i++){
		if(L.data[i - 1] == e){
			pos = i;
			return true;
		}
	}
	return false;
}

// 5. GetElem(L, i, &e)
bool GetElem(SqList L, int i, ElemType &e){
	if(i < 1 || i > L.length){
		return false;
	}
	e = L.data[i - 1];
	return true;
}

// 6. PrintList(L)
int PrintList(SqList L){
	for(int i = 1; i <= L.length; i++){
		printf("%d ", L.data[i - 1]);
	}
	return true;
}

// 7. ListInsert(&l, i, e)
bool InsertElem(SqList &L, int i, ElemType e){
	if(i < 1 || i > L.length + 1){
		return false;
	}
	if(L.length > MaxSize){
		return false;
	}
	for(int j = L.length; j >= i; j--){
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 8. ListDelete(&L, i, &e)
int DeleteElem(SqList &L, int i, ElemType &e){
	if(i < 1 || i > L.length){
		return false;
	}
	e = L.data[i - 1];
	for(int j = i; j <= L.length; j++){
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}