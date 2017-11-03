#include "cstdlib"
#include "cstdio"

typedef int ElemType;

#define MaxSize 50
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

bool InitStack(SqStack &S){
	S.top = -1;
	return true;
}

bool Empty(SqStack S){
	return S.top == -1;
}

bool Push(SqStack &S, ElemType e){
	S.data[++S.top] = e;
	return true;
}

bool Pop(SqStack &S, ElemType &e){
	e = S.data[S.top--];
	return true;
}

bool GetTop(SqStack S, ElemType &e){
	e = S.data[S.top];
	return true;
}

