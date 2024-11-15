#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;	
};
class linkedList{
	private:
		node *head;
		node *tail;
};
void travers(node *head){
	cout<<"Values-> { ";
	while(head!=NULL){
		cout<<head->data<<", ";
		head=head->next;
	}
	cout<<"}"<<endl;
}
void isEmpty(){
	
}
int main(){
	// linked list node declarations... 
	node* n1;
	node* n2;
	node* n3;
	node* n4;
	node* n5;
	// Memory allocations for these nodes... 
	n1=new node();
	n2=new node();
	n3=new node();
	n4=new node();
	n5=new node();
	// Node [1]
	n1->data=2;
	n1->next=n2;
	// Node [2]
	n2->data=4;
	n2->next=n3;
	// Node [3]
	n3->data=5;
	n3->next=n4;
	// Node [4]
	n4->data=6;
	n4->next=n5;
	// Node [5]
	n5->data=7;
	n5->next=NULL;
	// calling  Traversal function...
	travers(n1);
	return 0;
}