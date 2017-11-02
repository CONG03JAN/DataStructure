#include "SqStack.h"
#include "iostream"

using namespace std;

int main(){
	SqStack S;
	InitStack(S);
	Push(S, 1);
	Push(S, 2);
	int e;
	Pop(S, e);
	GetTop(S, e);
	cout << e << endl;
	return 0;
}
