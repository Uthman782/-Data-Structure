#include<iostream>
using namespace std;

int main(void){
	int a=7;
	int b=5;
	cout<<"a:-> "<<a<<endl;
	cout<<"b:-> "<<b<<endl;
	{int c=a;a=b;b=c;}
	cout<<"a:-> "<<a<<endl;
	cout<<"b:-> "<<b<<endl;
	return 0;
}