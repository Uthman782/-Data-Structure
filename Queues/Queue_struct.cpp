#include <iostream>
using namespace std;

struct queue{
	int rear;
	int cap;
	int *arr;
	int front;
};
queue* create(int ts){
	queue* ar=new queue();
	ar->cap=ts;
	ar->arr=new int[ts];
	ar->rear=ar->front=-1;
	return ar;
}
// function to check: the queue is full.
inline bool isFull(queue *q){
	if(q->rear==q->cap-1)
		return 1;
	return 0;
}
// function to check: the queue is empty.
inline bool isEmpty(queue *Q){
	if(Q->front==-1 or Q->front>Q->rear)
		return 1;
	return 0;
}
// Insertion function.
void enqueue(queue *Q, int ele){
	if(isFull(Q)){
		cout<<"Queue Overflow."<<endl;
		return;
	}
	Q->front=(Q->front==-1)?0:Q->front;
	Q->arr[++Q->rear]=ele;
	return;
}
// Deleting for the Queue function.
void dequeue(queue *Q){
	if(isEmpty(Q)){
		cout<<"Queue Underflow."<<endl;
		return;
	}
	Q->front++;
	return;
}
// display method for queue... 
void display(queue *Q){
		cout<<"values-> { ";
	if(Q->front!=-1)
		for(int i=Q->front;i<=Q->rear;i++)
			cout<<Q->arr[i]<<(i!=Q->rear?", ":" ");
	cout<<"}"<<endl;
	return ;
}
int main(){
	queue* q;
	q=create(3);
	display(q);
	enqueue(q,2);
	display(q);
	enqueue(q,3);
	display(q);
	enqueue(q,4);
	display(q);
	enqueue(q,5);
	display(q);
	dequeue(q);
	display(q);
	dequeue(q);
	display(q);
	dequeue(q);
	display(q);
	dequeue(q);


//	q->arr[0]=1;
//	++q->rear;
//	q->arr[1]=3;
//	++q->rear;
//	q->arr[2]=4;
//	++q->rear;
//	q->front;
//	cout<<q->rear<<endl;


	return 0;
}