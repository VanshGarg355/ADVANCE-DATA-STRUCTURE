#include <iostream>
#include <string>
using namespace std;

class mystack {
    int capacity;
    char *arr;
    int top;

public:
    mystack(int cap) {
        capacity = cap;
        arr = new char[capacity];
        top = -1;
    }

    void push(char x) {
        if (top == capacity - 1) {
            cout << "Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (top == -1) {
            return '\0';
        }
        return arr[top--];
    }

    bool isempty() {
        return top == -1;
    }
};

int main() {
    string s;
    cout << "Enter parentheses: ";
    cin >> s;

    mystack st(s.length());

    bool valid = true;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push('(');
        } else if (s[i] == ')') {
            if (st.isempty()) {
                valid = false;
                break;
            }
            st.pop();
        }
    }

    if (!st.isempty())
        valid = false;

    if (valid)
        cout << "Valid\n";
    else
        cout << "Invalid\n";

    return 0;
}