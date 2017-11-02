#include "cstdlib"
#include "cstdio"

typedef int ElemType;

typedef struct LinkNode{
	ElemType data;
	LinkNode *next;
} LinkNode, *LinkList;

// 1. InitList(&L)
bool InitList(LinkList &L){
	L = (LinkList)(malloc(sizeof(LinkNode)));
	L->next = NULL;
	return true;
}

// 2. length(L)
int length(LinkList L){
	LinkNode *p = L;
	int len = 0;
	while(p->next != NULL){
		len++;
		p = p->next;
	}
	return len;
}

// 3. Empty(L)
bool Empty(LinkList L){
	return L->next == NULL;
}

// 4. LocateElem(L, e)
LinkNode* LocateElem(LinkList L, ElemType e){
	LinkNode *p = L->next;
	while(p != NULL && p->data != e){
		p = p->next;
	}
	return p;
}

// 5. GetElem(L, i)
LinkNode* GetElem(LinkList L, int i){
	LinkNode *p = L;
	while(i-- && p->next!=NULL){
		p = p->next;
	}
	return p;
}

// 6. PrintList(L)
bool PrintList(LinkList L){
	LinkNode *p = L->next;
	while(p){
		printf("%d \n", p->data);
		p = p->next;
	}
	return true;
}

// 7. InsertElem(&L, i, e)
bool InsertElem(LinkList &L, int i, ElemType e){
	LinkNode *p = L;
	i--;
	while(p != NULL && i--){
		p = p->next;
	}
	if(p != NULL){
		LinkNode *s = (LinkNode*)(malloc(sizeof(LinkNode)));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
	return false;
}

// 8. DeleteElem(&L, i, &e)
bool DeleteElem(LinkList &L, int i, ElemType &e){
	LinkNode *p = L;
	i--;
	while(p != NULL && i--){
		p = p->next;
	}
	if(p != NULL){
		LinkNode *q = p->next;
		p->next = q->next;
		free(q);
		return true;
	}
	return false;
}

