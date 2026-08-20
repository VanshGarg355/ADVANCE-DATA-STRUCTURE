#include <iostream>

using namespace std;

class mystack {
    int capacity;
    int * arr;
    int top = -1;
    public:

        mystack(int cap) {
            capacity = cap;
            arr = new int[cap];
            top = -1;
        }
    void push(int x) {
        if (top == capacity - 1) {
            cout << "overflow" << endl;
        }
        arr[++top] = x;
    }
    int pop() {
        if (top == -1) {
            cout << "underflow" << endl;
        }
        return arr[top--];
    }
    bool isempty() {
        return top == -1;
    }

};
int main()
{
    mystack st(50);
    int i;
    cin >> i;
    while (i != 0) {
        int rem = i % 16;
        st.push(rem);
        i = i / 16;
    }
    while (!st.isempty()) {
        int x = st.pop();
        cout << x << endl;
    }
    return 0;
}