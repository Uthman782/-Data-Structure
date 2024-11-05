#include<iostream>
using namespace std;

static int count=0;
inline int fibonacci(int n){
	count++;
	cout<<n<<", ";
	if(n==1 or n==0)
		return n;
	return fibonacci(n-1)+fibonacci(n-2);
}
int main(void){
	cout<<fibonacci(5);
	cout<<endl<<"Total Calls ==> "<<count;
	return 0;
}