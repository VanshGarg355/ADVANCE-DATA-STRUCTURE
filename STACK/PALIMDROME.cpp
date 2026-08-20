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

    char peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return '\0';
        }
        return arr[top];
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

    // Push all characters
    for (int i = 0; i < str.size(); i++)
    {
        st.push(str[i]);
    }

    bool palindrome = true;

    // Compare string with stack
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != st.pop())
        {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << "Palindrome";
    else
        cout << "Not a Palindrome";

    return 0;
}