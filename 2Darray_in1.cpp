#include<iostream>
using namespace std;

int main(void){
	int row,col;
	cout<<"Enter Rows:-> ";
	cin>>row;
	cout<<"Enter Cols:-> ";
	cin>>col;
	// getting values from the user.. .
	int arr[row][col];
	int *ptr=&arr[0][0];
	for(int i=0;i<(row*col);i++,ptr++){
			cout<<"arr: "<<i<<"-> ";
			cin>>*ptr;
	}
	ptr =&arr[0][0];
//	putting values on the console.. .
	cout<<"Array--v"<<endl;
	for(int i=0,size=row*col;i<size;i++,ptr++)
			cout<<(i%row?"":"{ ")<<*ptr<<((i%col-1)?", ":" }\n");
	
	return 0;
}