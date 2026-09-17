#include <bits/stdc++.h>
using namespace std;

vector<int> c;

void mergeSort(vector<int> &A, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);

    int i = low;
    int j = mid + 1;
    int k = 0;

    int c[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            c[k] = A[i];
            i++;
        }
        else
        {
            c[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        c[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        c[k] = A[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = c[i - low];
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    c.resize(n);
    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}