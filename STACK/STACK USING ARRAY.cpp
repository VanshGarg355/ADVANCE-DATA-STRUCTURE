#include <bits/stdc++.h>

#define stacksize 6
using namespace std;

struct Stack
{
    char item[stacksize];
    int top;
};

Stack s;

void initialize()
{
    s.top = -1;
}

void Push(char x)
{
    if (s.top == stacksize - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    s.top++;
    s.item[s.top] = x;
}

char Pop()
{
    if (s.top == -1)
    {
        cout << "Stack Underflow" << endl;
        exit(1);
    }

    return s.item[s.top--];
}

char stacktop()
{
    if (s.top == -1)
    {
        cout << "Stack is Empty" << endl;
        exit(1);
    }

    return s.item[s.top];
}

bool isempty()
{
    return (s.top == -1);
}

int main()
{
    initialize();

    Push('a');
    Push('b');
    Push('c');

    char x = Pop();
    cout << "Popped Element: " << x << endl;

    x = stacktop();
    cout << "Top Element: " << x << endl;

    Push('d');

    char y = Pop();
    cout << "Popped Element: " << y << endl;

    char z = Pop();
    cout << "Popped Element: " << z << endl;


    char a = stacktop();
    cout << "Top Element: " << a << endl;

    char b = Pop();
    cout << "Popped Element: " << b << endl;

    char c = Pop();
    cout << "Popped Element: " << c << endl;


    return 0;
}