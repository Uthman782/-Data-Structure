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
	// address.. .
	int* BA=&arr[0][0];
	cout<<"Base address is:-> "<<BA<<endl;
	cout<<"Value at base address:-> "<<*BA<<endl;
//	 For Row Major addressing.. .
	int k,l;
	cout<<"Want address of:"<<endl;
	cout<<"Rows-> ";
	cin>>k;
	cout<<"Cols-> ";
	cin>>l;
	cout<<"Row Major Address: "<<endl;
	cout<<"Address at "<<k<<" x "<<l<<":-> "<<&arr[k][l]<<endl;
	cout<<"Value at "<<k<<" x "<<l<<":-> "<<arr[k][l]<<endl;

//	 For Col Major addressing.. .
	cout<<"Transporting Array--v"<<endl;
	int arr1[col][row]; //extra array for transporting.. 
	for(int i=0;i<col;i++)
		for(int j=0; j<row;j++)
			arr1[i][j]=arr[j][i];
	int *ptr=&arr1[0][0];
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++,ptr++)
			arr[i][j]=*ptr;
	for(int i=0;i<col;i++)
		for(int j=0; j<row;j++)
			cout<<(j?"":"{ ")<<arr1[i][j]<<(j!=row-1?", ":" }\n");
	for(int i=0;i<row;i++)
		for(int j=0; j<col;j++)
			cout<<(j?"":"{ ")<<arr[i][j]<<(j!=col-1?", ":" }\n");
			
	
//	cout<<"Col Major Address: "<<endl;
	cout<<"Address at "<<k<<" x "<<l<<":-> "<<&arr[l][k]<<endl;
	cout<<"Value at "<<k<<" x "<<l<<":-> "<<arr[l][k]<<endl;
	return 0;
}