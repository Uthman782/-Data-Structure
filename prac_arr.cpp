#include<iostream>
using namespace std;

void insert(int arr[],int &cap,int ts,int ele, int index) {
	if(cap==ts) {
		cerr<<"Array is full..."<<endl;
		return;
	} else if(index<0 or index>cap) {
		cerr<<"Invalid index"<<endl;
		return;
	}
	for(int i=cap; i>=index; i--)
		arr[i+1]=arr[i];
	arr[index]=ele;
	cap++;
}
int search(int arr[],int cap,int ele) {
	for(int i=0; i<cap; i++) {
		if(ele==arr[i])
			return i;
	}
	return -1;
}
void delet(int arr[],int &cap,int ele) {
	int ind=search(arr,cap,ele);
	if(ind!=-1) {
		for(int i=ind; i<cap; i++)
			arr[i]=arr[i+1];
		cap--;
	}
}
void print(int arr[],int ts) {
	for(int i=0; i<ts; i++)
		cout<<arr[i]<<", ";
	cout<<endl;
}
int main(void) {
	int tot=10;
	int arr[tot]= {1,2,3,4,5,6,7};
	int cap=7;
	int ele=0;
	int index=3;
	print(arr,cap);
	insert(arr,cap,tot,ele,index);
	print(arr,cap);
	delet(arr,cap,4);
	print(arr,cap);
	delet(arr,cap,1);
	for(int i=0; i<cap; i++)
		cout<<arr[i]<<", ";
	cout<<endl<<cap;
	return 0;
}