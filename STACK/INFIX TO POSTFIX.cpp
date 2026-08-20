#include <bits/stdc++.h>

using namespace std;

class mystack {
    char capacity;
    char top = -1;
    char * arr;

    public: mystack(int cap) {
        capacity = cap;
        top = -1;
        arr = new char[capacity];
    }

    void push(int ch)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = ch;
    }

    int pop() {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "stack is empty ";
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;

    }
};
bool prcd(char a, char b) {
    if (a == '^' || a == '%' || a == '/' || a == '*') {
        if (b == '^') {
            return false;
        }
        else return true;
    }
    else if (a == '+' || a == '-') {
        if (b == '+' || b == '-') {
            return true;
        }
        else return false;
    }
}
int main() {
    string s;
    cout << "enter the string" << endl;
    cin >> s;
    mystack st(50);
    int i = 0;
    string postfix;
    while (i < s.size()) {
        char symbol = s[i];
        i++;
        if (symbol >= 'a' && symbol <= 'z')
            postfix = postfix + symbol;
        else {
            while (!st.isEmpty() && prcd(st.peek(), symbol)) {
                char x = st.pop();

            }
            st.push(symbol);
        }

    }

    while (!st.isEmpty()) {
        int x = st.pop();
        postfix += x;
    }

    

    cout << postfix << endl;
    return 0;
}