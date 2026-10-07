// Postfix Evaluation program

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
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
}
class Stack
{
    vector<int> item;
    int top;

public:
    Stack(int S)
    {
        item.resize(S);
        top = -1;
    }
    void Push(int x)
    {
        if (top == item.size() - 1)
        {
            cout << "stack overflows";
            exit(1);
        }

        top++;
        item[top] = x;
    }
    int Pop()
    {
        char x;
        if (top == -1)
        {
            cout << "underflows";
            exit(1);
        }
        x = item[top];
        top--;
        return x;
    }
    int StackTop()
    {
        char x = item[top];
        return x;
    }
    bool IsEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    string postfix;
    cout << "Enter the postfix expression = ";
    cin >> postfix;
    Stack S(100);
    int i = 0;
    while (i < postfix.size())
    {
        char symbol = postfix[i];
        i++;
        if (symbol >= '0' && symbol <= '9')
        {
            S.Push(symbol - '0');
        }
        else
        {
            int b = S.Pop();
            int a = S.Pop();
            int value = Evaluate(a, b, symbol);
            S.Push(value);
        }
    }
    int x = S.StackTop();
    cout << x;
}