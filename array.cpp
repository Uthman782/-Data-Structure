#include<iostream>
using namespace std;

int main(void){
	int range;
	cout<<"Enter range for your array:-> ";
	cin>>range;
	int arr[range];
	for(int i=0;i<range;i++){
		cout<<"arr["<<i<<"]-> ";
		cin>>arr[i];
	}
	cout<<"\tArray:-v"<<endl<<"arr["<<range<<"]= ";
	for(int i=0, size=sizeof(arr)/sizeof(arr[0]); i<size /* or i<range*/;i++)
		cout<<((!i)?"{ ":", ")<<arr[i]<<((i==size-1)?" }":"");
		
	cout<<endl<<"\tBase Address: "<<&arr<<endl;
	
	int k;
	cout<<"Enter index [0-"<<range-1<<"]: ";
	cin>>k;
	if(k<0 or k>=range){
		cout<<"Invalid index."<<endl;
		main();
	}else{
		int* address=&arr[0]+k;
		cout<<"Address at "<<k<<": "<<&arr[k]<<endl;
		cout<<"Value at "<<k<<": "<<arr[k]<<endl;
		cout<<"\tUsing Formula (BA+index):"<<endl;
		cout<<"Address at "<<k<<": "<<address<<endl;
		cout<<"Value at "<<k<<": "<<*address<<endl;
	}
	return(0);
}