#include <bits/stdc++.h>

using namespace std;

class mystack
{
    int capacity;
    int top;
    char * arr;

    public:
        mystack(int cap)
        {
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
int main()
{
    mystack st(43);
    int i;
    cin >> i;
    while (i != 0) {
        int r = i % 2;
        st.push(r);
        i = i / 2;


        while (!st.isEmpty()) {
            int x = st.pop();
            cout << x << endl;
        }
    }
    return 0;
}