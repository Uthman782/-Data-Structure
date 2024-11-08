#include<iostream>
#include<stack>
using namespace std;

int main(void){			
	stack<string> st;
	// pushing to stack .. .
	st.push("red");
	st.push("yellow");
	st.push("green");
	if(!st.empty())
		cout<<"Stack size: "<<st.size()<<endl;
	else
		cout<<"Stack is empty."<<endl;		
	
	if(!st.empty())
		cout<<st.top()<<endl;
	else
		cout<<"Stack is empty."<<endl;	
	
	// poping to stack .. .
	st.pop();
	
	if(!st.empty())
		cout<<st.top()<<endl;
	else
		cout<<"Stack is empty."<<endl;
	
	st.pop();
	
	if(!st.empty())
		cout<<st.top()<<endl;
	else
		cout<<"Stack is empty."<<endl;	
	
	st.pop();
	
	if(!st.empty())
		cout<<st.top()<<endl;
	else
		cout<<"Stack is empty."<<endl;	
	return(0);
}