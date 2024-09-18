#include<iostream>
using namespace std;

inline int input(string ms, int val=0){
	cout<<ms;
	if(!val)
		cin>>val;
	return val;
}
//display method. .. 
int delet(int[],int,int&,bool);
void display(int[], int);
int main(void){
	int tsize=input("Enter array range: ");
	int arr[tsize],usize=0;
	for(int i=0;i<tsize;i++,usize++)
		arr[i]=input("Enter array: ");
	display(arr,usize);
	char cond='y';
	while(cond=='y'){
		int val=input("Enter value to delete: ");
		delet(arr,val,usize,1);
		display(arr,usize);
		cout<<"Do you want to insert value [y/n]: ";
		cin>>cond;
	}
	return(0);
}
//deleting method body.. .
int delet(int arr[],int ind_or_val,int &used_size, bool by_val=false){
	if(!by_val and ind_or_val<used_size){
		for(int i=ind_or_val;i<used_size;i++)
			arr[i]=arr[i+1];
		cout<<"Deleting.. ... ."<<endl;
		used_size--;
	}else if(by_val){
		for(int i=0;i<used_size;i++){
			if(arr[i]==ind_or_val){
				for(int j=i;j<used_size;j++)
					arr[j]=arr[j+1];
				cout<<"Deleting.. ... ."<<endl;
				used_size--;
			}
		}
	}
	else
		cout<<"You must enter an index within 0 and "<<used_size<<endl;
	return 1;
}
void display(int arr[], int used_size){
	cout<<"arr["<<used_size<<"]: ";
	for(int i=0;i<used_size;i++)
		cout<<(!i?"{ ":"")<<arr[i]<<(i!=used_size-1?", ":" }");
	cout<<endl;
}
