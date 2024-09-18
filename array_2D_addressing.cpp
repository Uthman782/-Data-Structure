#include<iostream>
using namespace std;

int main(void){
	int row,col;
	cout<<"Enter Rows:-> ";
	cin>>row;
	cout<<"Enter Cols:-> ";
	cin>>col;
//	 getting values from the user.. .
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
	cout<<"Row Major->{ ";
	for(int i=0;i<row;i++){
		for(int j=0; j<col;j++)
			cout<<arr[i][j]<<", ";
	}
	cout<<"}\n";

//	cout<<"Transporting Array--v"<<endl;
	int arr1[col][row]; //extra array for transporting.. 
	for(int i=0;i<col;i++)
		for(int j=0; j<row;j++)
			arr1[i][j]=arr[j][i];
	cout<<"Col Major->{ ";
	for(int i=0;i<col;i++){
		for(int j=0; j<row;j++)
			cout<<arr1[i][j]<<", ";
	}
	cout<<"}\n";
	// addresses.. .
	int* BA=&arr[0][0];
	cout<<"Base address is:-> "<<BA<<endl;
	cout<<"Value at base address:-> "<<*BA<<endl;
	int k,l;
	cout<<"Want address of:"<<endl;
	cout<<"Rows-> ";
	cin>>k;
	cout<<"Cols-> ";
	cin>>l;
//	 For Row Major addressing.. .
	int *address=BA+((k*col)+l);
	cout<<"Row Major Address: "<<endl;
	cout<<"Address at "<<k<<" x "<<l<<":-> "<<address<<endl;
	cout<<"Value at "<<k<<" x "<<l<<":-> "<<*address<<endl;
//	 For Col Major addressing.. .
	address=BA+(k+(l*row));
	cout<<"Col Major Address: "<<endl;
	cout<<"Address at "<<k<<" x "<<l<<":-> "<<address<<endl;
	cout<<"Value at "<<k<<" x "<<l<<":-> "<<*address<<endl;
	return 0;
}