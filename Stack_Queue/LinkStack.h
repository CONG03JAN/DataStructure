#include "cstdlib"
#include "cstdio"

typedef int ElemType;

typedef struct LinkNode{
	ElemType data;
	LinkNode *next;
}LinkNode, *LinkStack;

bool InitStack(LinkStack &S){
	S = NULL;
	return true;
}

bool Empty(LinkStack S){
	return S == NULL;
}

bool Push(LinkStack &S, ElemType e){
	LinkNode *s = (LinkNode*)(malloc(sizeof(LinkNode)));
	s->data = e;
	s->next = S;
	S = s;
	return true;
}

bool Pop(LinkStack &S, ElemType &e){
	if(S == NULL){
		return false;
	}
	LinkNode *p = S;
	S = S->next;
	free(p);
	return true;
}

bool GetTop(LinkStack S, ElemType &e){
	if(S == NULL){
		return false;
	}
	e = S->data;
	return true;
}

