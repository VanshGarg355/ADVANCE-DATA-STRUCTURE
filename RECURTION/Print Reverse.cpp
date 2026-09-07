#include<bits/stdc++.h>
using namespace std;
void PrintElements(vector<int> &arr,int i){
    if(i<arr.size()){
        PrintElements(arr,i+1);
                cout<<arr[i];

    }
}
int main(){

vector<int>arr;
arr.push_back(2);
arr.push_back(3);
arr.push_back(4);
arr.push_back(2);
arr.push_back(7);
   PrintElements(arr, 0); 
}