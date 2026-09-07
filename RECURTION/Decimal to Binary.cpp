#include <bits/stdc++.h>
using namespace std;

void DecimalToBinary(int i)
{
    if (i > 0)
    {
        DecimalToBinary(i / 2);
        cout << i % 2;
    }
}

int main()
{
    int n;
    cin >> n;

    DecimalToBinary(n);
    cout << endl;

    return 0;
}
