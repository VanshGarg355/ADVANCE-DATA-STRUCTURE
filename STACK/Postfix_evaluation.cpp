#include <bits/stdc++.h>
using namespace std;

int Evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    case '%':
        return a % b;

    case '^':
        return pow(a, b);
    }

    return 0;
}

class mystack
{
    int capacity;
    int top;
    int *arr;

public:
    mystack(int cap)
    {
        capacity = cap;
        top = -1;
        arr = new int[capacity];
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

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return arr[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
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
    string s;

    cout << "Enter the postfix expression: ";
    cin >> s;

    mystack st(50);

    int i = 0;

    while (i < s.size())
    {
        char symbol = s[i];
        i++;

        if (symbol >= '0' && symbol <= '9')
        {
            st.push(symbol - '0');
        }
        else
        {
            int b = st.pop();
            int a = st.pop();

            int value = Evaluate(a, b, symbol);

            st.push(value);
        }
    }

    int x = st.peek();

    cout << "Answer = " << x << endl;

    return 0;
}