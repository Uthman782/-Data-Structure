#include<iostream>
using namespace std;

struct stack {
	int ts,top;
	int *data;
};
stack* createStk(int ts) {
	stack* arr=new stack();
	arr->data=new int[ts];
	arr->top=-1;
	arr->ts=ts;
	return arr;
}

void push(stack *arr, int ele) {
	if(arr->top==arr->ts-1) {
		cout<<"array is full"<<endl;
		return;
	}
//	arr->top++;
	arr->data[++arr->top]=ele;
	return ;
}
void pop(stack* stk){
	if(stk->top==-1){
		cout<<"stack is empty!"<<endl;
		return ;
	}
	stk->top--;
}
void display(stack *stk) {
	if(stk->top!=-1) {
		for(int i=0; i<=stk->top; i++)
			cout<<stk->data[i]<<", ";
		cout<<endl;
	}
	return;
}
int main() {
	stack *stk=createStk(5);
	push(stk,5);
	push(stk,6);
	push(stk,7);
	push(stk,8);
	display(stk);
	pop(stk);
	pop(stk);
	display(stk);
	push(stk,9);
	pop(stk);
	display(stk);
	display(stk);
	push(stk,10);
	return 0;
}