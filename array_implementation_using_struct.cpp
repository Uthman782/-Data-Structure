#include<iostream>
using namespace std;

struct array {
	int ts,cap;
	int *data;
};
array* createArr(int ts) {
	array* arr=new array();
	arr->data=new int[ts];
	arr->cap=0;
	arr->ts=ts;
	return arr;
}

void insert(array* arr,int index, int ele) {
	if(arr->cap==arr->ts) {
		cerr<<"array is full!"<<endl;
		return;
	} else if(index<0 or index>arr->cap) {
		cerr<<"invalid index!"<<endl;
		return;
	}
	for(int i=arr->cap; i>=index; i--)
		arr->data[i+1]=arr->data[i];
	arr->data[index]=ele;
	arr->cap++;
	return;
}
void display(array* arr) {
	for(int i=0; i<arr->cap;)
		cout<<arr->data[i++]<<", ";
	cout<<endl;
}
int search(array *arr, int ele) {
	if(arr->cap) {
		for(int i=0; i<arr->cap;) {
			if(arr->data[i++]==ele)
				return i;
		}
	}
	return -1;
}

void remove(array *arr, int ele) {
	int index=search(arr, ele);
	if(index!=-1){
		for(int i=index;i<arr->cap;i++)
			arr->data[i]=arr->data[i+1];
		arr->cap--;
	}
}
int main(void) {
	array* arr=createArr(5);
	insert(arr,0,1);
	insert(arr,0,2);
	insert(arr,0,3);
	insert(arr,0,4);
	insert(arr,0,5);
	display(arr);
	remove(arr,4);
	display(arr);
	return 0;
}