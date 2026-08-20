#include <bits/stdc++.h>
using namespace std;

class mystack
{
    int capacity;
    int top;
    char *arr;

public:
    mystack(int cap)
    {
        capacity = cap;
        top = -1;
        arr = new char[capacity];
    }

    void push(char ch)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = ch;
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    mystack st(str.size());

    int i = 0;

    while (i < str.size())
    {
        st.push(str[i]);
        i++;
    }

    while (!st.isEmpty())
    {
        char x = st.pop();
        cout << x;
    }

    return 0;
}