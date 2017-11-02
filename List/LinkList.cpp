#include "LinkList.h"
#include "iostream"

using namespace std;

bool Del_X1(LinkList &L, ElemType x){
	LinkNode *pre = L;
	LinkNode *p = L->next;
	while(p!=NULL){
		if(p->data == x){
			LinkNode *q = p;
			pre->next = p->next;
			p = p->next;
			free(q);
		}else{
			pre = p;
			p = p->next;
		}
	}
	return true;
}

bool Del_X2(LinkList &L, ElemType x){
	LinkNode *p = L->next;
	LinkNode *r = L;
	while(p!=NULL){
		if(p->data != x){
			r->next = p;
			r = p;
			p = p->next;
		}else{
			LinkNode *q = p;
			p = p->next;
			free(q);
		}
	}
	r->next = NULL;
	return true;
}

bool Del_Min(LinkList &L){
	LinkNode *p = L->next, *pre = L, *q;
	LinkNode *minp = p, *minpre = pre;
	ElemType min = p->data;
	while(p != NULL){
		if(min > p->data){
			minpre = pre;
			minp = p;
			min = p->data;
		}
		pre = p;
		p = p->next;
	}
	q = minp;
	minpre->next = minp->next;
	free(q);
	return true;
}

bool Reverse(LinkList &L){
	LinkNode *p = L->next, *r;
	L->next = NULL;
	while(p != NULL){
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return true;
}



LinkNode* Search_Com(LinkList &L1, LinkList &L2){
	int len1 = 0, len2 = 0;
	LinkNode *p1 = L1->next;
	LinkNode *p2 = L2->next;
	int k;
	while(p1 != NULL){
		p1 = p1->next;
		len1++;
	}
	while(p2 != NULL){
		p2 = p2->next;
		len2++;
	}
	p1 = L1->next;
	p2 = L2->next;
	if(len1 > len2){
		k = len1 - len2;
		while(k--){
			p1 = p1->next;
		}
	}else{
		k = len2 - len1;
		while(k--){
			p2 = p2->next;
		}
	}
	while(p1 == p2){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

LinkList Dis_List(LinkList &L1){
	int i = 1;
	LinkList L2;
	L2 = (LinkList)(malloc(sizeof(LinkNode)));
	L2->next = NULL;
	LinkNode *p1 = L1->next, *pre = L1, *p2 = L2;
	while(p1 != NULL){
		if(i%2 == 0){
			p2->next = p1;
			p2 = p1;
			pre->next = p1->next;
			pre = p1;
			p1 = pre->next;
			i++;
		}else{
			pre = p1;
			p1 = pre->next;
			i++;
		}
	}
	p2->next = NULL;
	return L2;
}

bool MergeList(LinkList &L1, LinkList &L2){
	LinkNode *p1 = L1->next, *p2 = L2->next, *r;
	L1->next = NULL;
	while(p1 != NULL && p2 != NULL){
		if(p1->data > p2->data){
			r = p1->next;
			p1->next = L1->next;
			L1->next = p1;
			p1 = r;
		}else{
			r = p2->next;
			p2->next = L1->next;
			L1->next = p2;
			p2 = r;
		}
	}

	if(p1 != NULL){
		while(p1 != NULL){
			r = p1->next;
			p1->next = L1->next;
			L1->next = p1;
			p1 = r;
		}
	}else{
		while(p2 != NULL){
			r = p2->next;
			p2->next = L1->next;
			L1->next = p2;
			p2 = r;
		}
	}
	return true;
}

bool Get_Com(LinkList &L1, LinkList &L2, LinkList &L3){
	LinkNode *p1 = L1->next, *p2 = L2->next, *r = L3;
	while(p1 != NULL && p2 != NULL){
		if(p1->data == p2->data){
			LinkNode *s = (LinkNode*)(malloc(sizeof(LinkNode)));
			s->data = p1->data;
			r->next = s;
			r = s;
			p1 = p1->next;
			p2 = p2->next;
		}else{
			if(p1->data > p2->data){
				p1 = p1->next;
			}else{
				p2 = p2->next;
			}
		}
	}
	return true;
}

int main(){
	LinkList L1, L2, L3; 
	InitList(L1);
	InitList(L2);
	InitList(L3);

	InsertElem(L1, 1, 9);
	InsertElem(L1, 2, 8);
	InsertElem(L1, 3, 6);
	InsertElem(L1, 4, 6);
	InsertElem(L1, 5, 5);
	InsertElem(L1, 6, 4);
	InsertElem(L1, 7, 3);

	InsertElem(L2, 1, 6);
	InsertElem(L2, 2, 5);
	InsertElem(L2, 3, 4);
	InsertElem(L2, 4, 3);
	InsertElem(L2, 5, 2);
	InsertElem(L2, 6, 1);

	// cout << Search_Com(L1, L2)->data << endl;

	Get_Com(L1, L2, L3);

	// L2 = Dis_List(L1);
	// MergeList(L1, L2);
	PrintList(L3);
	// cout << " - " << endl;
	// PrintList(L2);

	// PrintList(L);

	return 0;
}