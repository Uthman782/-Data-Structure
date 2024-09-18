#include<iostream>
using namespace std;

int main(void){
	int range;
	cout<<"Enter range:-> ";
	cin>>range;
	// getting values from the user.. .
	int arr[range];
	for(int i=0;i<range;i++){
		cout<<"arr["<<i<<"]-> ";
		cin>>arr[i];
	}
//	putting values on the console.. .
	cout<<"Your Array-> arr["<<range<<"]->{ ";
	for(int i=0;i<range;i++)
		cout<<arr[i]<<(i!=range-1?",":" }");
		
	int m,n;
	cout<<"\nHow do you want to represent your array."<<endl;
	cout<<"Enter rows:-> ";
	cin>>m;
	cout<<"Enter cols:-> ";
	cin>>n;
	int newArr[m][n];
	bool invalid=false;
	if(m*n==range){
		int *arrPtr=&arr[0];
		for(int i=0;i<m;i++){
			for(int j=0; j<n;j++,arrPtr++){
				newArr[i][j]=*arrPtr;
			}
		}
	}else{
		invalid=true;
		cout<<"Invalid-> "<<n*m<<"!="<<range;
	}
	if(!invalid){
	cout<<"You Want your Array-v"<<endl;
	cout<<"arr["<<m<<"]["<<n<<"]-v\n{ ";
	for(int i=0;i<m;i++){
		for(int j=0; j<n;j++)
			cout<<(!j?"{ ":"")<<newArr[i][j]<<(j!=n-1?", ":" }\n");
//		cout<<" }"<<endl;
	}
	}
	return 0;
}