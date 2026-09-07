#include <bits/stdc++.h>
using namespace std;
void DecimalToOctal(int i)
{
    if (i > 0)
    {
        DecimalToOctal(i / 8);
        cout << i % 8 << endl;
    }
}
int main()
{
    int n;
    cin>>n;
     DecimalToOctal(n);
     cout << endl;
}