#include "cstdlib"

typedef int ElemType;

#define MaxSize 50
typedef struct{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

bool InitQueue(SqQueue &Q){
	Q.front = 0;
	Q.rear = 0;
	return true;
}

bool Empty(SqQueue Q){
	return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, ElemType e){
	Q.data[Q.rear++] = e;
	return true;
}

bool DeQueue(SqQueue &Q, ElemType &e){
	if(Q.front == Q.rear){
		return false;
	}
	e = Q.data[Q.front++];
	return true;
}

bool GetHead(SqQueue Q, ElemType &e){
	e = Q.data[Q.front];
	return true;
}
