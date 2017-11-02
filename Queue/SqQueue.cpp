#include "SqQueue.h"
#include "iostream"

using namespace std;

int main(){
	SqQueue Q;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	int e;
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	int x;
	GetHead(Q, x);
	cout << e << " " << x << endl;
	cout << Empty(Q) << endl;
	return 0;
}