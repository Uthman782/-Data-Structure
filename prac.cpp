#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int precedence(char op) {
	if(op=='+' or op=='-') return 1;
	else if(op=='*' or op=='/' or op=='^' or op=='%') return 2;
	return 0;
}
bool isop(char op) {
	return (op=='+' or op=='-' or op=='/' or op=='*' or op=='^' or op=='%');
}

void reverseParentheses(string &Q){
	for(char &ch:Q){
		if(ch=='(') ch=')';
		else if(ch==')') ch='(';	
	}
}
string infixToPostfix(string Q) {
	stack<char> stk;
	string p;
//	step 1, push '(' into stack and add ')' to Q..
	stk.push('(');
	Q+=')';

	//step 2: Scan Q and repeate step 3,4
	for(char ch : Q) {
		if(isalnum(ch))
			p+=ch;
		else if(ch=='(')
			stk.push(ch);
		else if(isop(ch)) {
			while(precedence(ch)<precedence(stk.top())){
				p+=stk.top();
				stk.pop();
			}
			stk.push(ch);
			}
		else if(ch==')'){
			while(stk.top() != '('){
				p+=stk.top();
				stk.pop();
			}
			stk.pop();
		}
	}
		return p;
}

string infixToPrefix(string Q){
	reverse(Q.begin(),Q.end());
	reverseParentheses(Q);
	string postfix=infixToPostfix(Q);
	reverse(postfix.begin(),postfix.end());
	return postfix;
}
int main(void){
	string infix="((a+b)*d)^(e-f)";
//	cout<<infixToPostfix(infix)<<endl;
	cout<<infixToPrefix(infix)<<endl;
	
	return 0;
}