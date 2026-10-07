#include <bits/stdc++.h>
using namespace std;
int main()
{
    // stack<int> s;
    // s.push(1);
    // s.push(2);

    // s.push(2);

    // s.push(3);

    // s.push(4);

    // s.push(6);

    // while (!s.empty())
    // {
    //     cout << s.top() << endl;
    //     s.pop();
    // }

    // stack<char> a;
    // s.push('a');
    // s.push('b');

    // s.push('n');

    // s.push('w');

    // s.push('e');

    // s.push('r');

    // while (!a.empty())
    // {
    //     cout << a.top() << endl;
    //     s.pop();
    // }
stack<int> s;
    int n=19;
    while(n!=0){
        int r=n%2;
        s.push(2);
        n=n/2;
    }
while (!s.empty())
    {
        cout << a.top() << endl;
        s.pop();
    }


}