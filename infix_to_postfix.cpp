#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '^') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix
string infixToPostfix(string Q) {
    stack<char> stk;
    string P;
    
    // Step 1: Push '(' onto stack and add ')' to the end of Q
    stk.push('(');
    Q += ')';
    
    // Step 2: Scan Q from left to right
    for (char ch : Q) {
        // Step 3: If operand, add to P
        if (isalnum(ch)) {
            P += ch;
        }
        // Step 4: If left parenthesis, push to stack
        else if (ch == '(') {
            stk.push(ch);
        }
        // Step 5: If operator, process precedence
        else if (isOperator(ch)) {
            while (!stk.empty() && precedence(stk.top()) >= precedence(ch)) {
                P += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
        // Step 6: If right parenthesis, pop until left parenthesis is found
        else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                P += stk.top();
                stk.pop();
            }
            stk.pop(); // Remove left parenthesis
        }
    }
    
    return P;
}

int main() {
    string infix;
    
    // Input the infix expression
    cout << "Enter an infix expression: ";
    cin >> infix;
    
    // Get the postfix expression
    string postfix = infixToPostfix(infix);
    
    // Output the postfix expression
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
