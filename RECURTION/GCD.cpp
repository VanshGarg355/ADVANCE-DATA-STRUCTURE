#include<bits/stdc++.h>
using namespace std;
int gcd(int a ,int b){
    if(a>b)
    return gcd(a%b,b);
    else if (b>a)
    return gcd(a,b%a);
    else if(a==0)
    return b;
    else return a;
}
int main(){
cout<<gcd(27,33)<<endl;
}


