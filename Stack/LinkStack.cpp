#include "LinkStack.h"
#include "iostream"

using namespace std;

int main(){
	LinkStack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	int e;
	Pop(S, e);
	Pop(S, e);
	GetTop(S, e);
	cout << e << endl;
	return 0;
}