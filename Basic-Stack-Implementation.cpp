#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;
template<class t>
class stack {
    int top;
    t item[MAX_SIZE];
public:
    stack() : top(-1) {}

    void push(t element) {
        if (top >= MAX_SIZE - 1) { //0 - 99
            cout << "Stack full push";
        } else {
            top++;
            item[top] = element;
        }
    }

    bool isEmpty() {
        return top < 0;
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        } else {
            cout << "stack empty on pop";
        }
    }

    void getTop(t &stackTop) { // we add references to have the same memory address to use same variable
        if (!isEmpty()) {
            stackTop = item[top];
            top--;
        } else {
            cout << "stack empty on getTop";
        }
    }

    void print() {
        cout << "[";
        for (int i = top; i >= 0; --i) {//first item in the stack should be print ( last in first out )
            cout << item[i] << " ";
        }
        cout << "]";
    }
};

int main() {
    stack<string>s;
    s.push("aa");
    s.push("bb");
    s.push("cc");
    s.push("dd");
    s.pop();
    s.print();

    return 0;
}

