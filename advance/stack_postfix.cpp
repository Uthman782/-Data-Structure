#include <iostream>
using namespace std;

template <class type>
class stack{
    int tsize; // Stack capacity
    int top;
    type temp;
    type *arr;

public:
    // stack constructor
    stack(int ts) : tsize(ts)
    {
        this->top = -1;
        this->arr = new type[ts];
    }
    // pushing method.. . ..
    bool push(type ele)
    {
        if (this->top != this->tsize - 1)
        {
            this->arr[++this->top] = ele;
            return (true);
        }
        cout << "stack overflow!" << endl;
        return (false);
    }
    // poping method... .. .
    bool pop(void)
    {
        if (this->top != -1)
        {
            this->temp = this->arr[this->top--];
            return (true);
        }
        cout << "stack underflow!" << endl;
        return (false);
    }
    // stack peek method.. . ...
    inline type peek(void)
    {
        if (this->top != -1)
            return this->arr[this->top];
        else
            cout << "Stack is empty!" << endl;
        return -1;
    }
    // stack isEmpty method.. . ...
    inline bool isEmpty(void)
    {
        return (this->top == -1);
    }
    // stack isFull method.. . ...
    inline bool isFull(void)
    {
        return (this->top == this->tsize - 1);
    }
    // stack size method.. . ...
    inline int size(void)
    {
        return (this->top + 1);
    }
    // stack search method.. . ...
    inline bool search(type ele)
    {
        for (int i = 0; i <= this->top; i++)
            if (this->arr[i] == ele)
                return true;
        return false;
    }
    // stack clear method.. . ...
    inline void clear(void)
    {
        this->top = -1;
        cout << "stack cleared!";
    }
    // stack show method.. . ...
    void show()
    {
        cout << "Value" << (this->top > 0 ? "s " : " ") << "-> ";
        cout << (this->top == -1 ? "{ null }" : "");
        for (int i = 0; i <= this->top; i++)
            cout << (!i ? "{ " : ", ") << arr[i] << (i == top ? " }" : "");
        cout << endl;
    }
    ~stack()
    {
        delete this->arr;
    }
};

void stackOperation(stack st ){

}
int main(void){
    stack st;
    stackOperation(&st);
    return (0);
}