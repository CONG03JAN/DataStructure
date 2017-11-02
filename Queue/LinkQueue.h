#include "cstdlib"

typedef int ElemType;

typedef struct LinkNode{
	ElemType data;
	LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front, *rear;
}LinkQueue;

bool InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (LinkNode*)(malloc(sizeof(LinkNode)));
	Q.front->next = NULL;
	return true;
}

bool Empty(LinkQueue Q){
	return Q.front == Q.rear;
}

bool EnQueue(LinkQueue &Q, ElemType e){
	LinkNode *s = (LinkNode*)(malloc(sizeof(LinkNode)));
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}

bool DeQueue(LinkQueue &Q, ElemType &e){
	if(Q.front == Q.rear) return false;
	LinkNode *q = Q.front->next;
	Q.front->next = q->next;
	e = q->data;
	if(Q.rear == q){
		Q.rear = Q.front;
	}
	free(q);
	return true;
}
