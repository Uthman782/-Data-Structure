#include<iostream>
using namespace std;

class stack{
		int tsize, top, temp;
		int* arr;
	public:
		stack(int ts):tsize(ts){
			top=-1;
			arr = new int[ts];
		}
		// pushing method.. . ..
		int push(int ele){
			if(tsize!=top){
				top++;
				arr[top]=ele;
				return(1);
			}
			return(0);
		}
		// poping method... .. .
		int pop(void){
			if(top!=-1){
				temp=arr[top];
				top--;
				return(1);
			}
			return(0);
		}
		// stack show method.. . ...
		void show(){
			cout<<"Value"<<(top>0?"s ":" ")<<"-> ";
			for(int i=0;i<=this->top;i++)
				cout<<(!i?"{ ":", ")<<arr[i]<<(i==top?" }":"");
			cout<<endl;
		}
};
int main(void){
	stack st(20);
	st.push(2);
	st.push(4);
	st.show();
	st.push(6);
	st.show();
	st.push(8);
	
	st.show();
	
	st.pop();
	st.show();
	
	st.pop();
	st.show();
	return(0);
}