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
	for(int i=0;i<row;i++){
		for(int j=0; j<col;j++){
			cout<<"arr["<<i<<"]["<<j<<"]-> ";
			cin>>arr[i][j];
		}
	}
//	putting values on the console.. .
	cout<<"Array--v"<<endl;
	for(int i=0;i<row;i++)
		for(int j=0; j<col;j++)
			cout<<(j?"":"{ ")<<arr[i][j]<<(j!=col-1?", ":" }\n");
	
//  Searching ... . 
	int search, if_found=0;
	cout<<"Enter value to search: ";
	cin>>search;
	for(int i=0;i<row;i++)
		for(int j=0; j<col;j++)
			if(search==arr[i][j])
				if_found=1;
	
	if(if_found)
		cout<<"Yes value found.";
	else
		cout<<"Value not found.";
			
	return 0;
}