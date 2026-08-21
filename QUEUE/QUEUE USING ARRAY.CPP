#include <bits/stdc++.h>
using namespace std;

void ArrayInsertion(vector<int>& arr, int i, int x) {

    int n = arr.size();

    arr.push_back(0);

    for (int j = n; j > i; j--) {
        arr[j] = arr[j - 1];
    }

    arr[i] = x;
}

int ArrayDeletion(vector<int>& arr, int i) {

    int n = arr.size();

    if (i < 0 || i >= n) {
        cout << "Invalid Index" << endl;
        return -1;
    }

    int x = arr[i];

    for (int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
    }

    arr.pop_back();

    return x;
}

void EnQueue(vector<int>& arr, int x) {

    ArrayInsertion(arr, arr.size(), x);
}

int DeQueue(vector<int>& arr) {

    if (arr.size() == 0) {
        cout << "Queue is Underflow" << endl;
        return -1;
    }

    return ArrayDeletion(arr, 0);
}

void Display(vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {

    vector<int> arr;

    EnQueue(arr, 10);
    EnQueue(arr, 20);
    EnQueue(arr, 30);
    EnQueue(arr, 40);

    cout << "Queue after EnQueue: ";
    Display(arr);

    int x = DeQueue(arr);

    cout << "Deleted Element: " << x << endl;

    cout << "Queue after DeQueue: ";
    Display(arr);

    ArrayInsertion(arr, 1, 50);

    cout << "After Array Insertion: ";
    Display(arr);

    x = ArrayDeletion(arr, 2);

    cout << "Deleted Element: " << x << endl;

    cout << "After Array Deletion: ";
    Display(arr);

    return 0;
}