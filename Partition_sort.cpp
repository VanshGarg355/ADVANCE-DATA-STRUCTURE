#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    vector<int> a;
    a.push_back(200);
    a.push_back(30);
    a.push_back(-5);
    a.push_back(150);
    a.push_back(100);

    int low = 0;
    int high = a.size() - 1;

    quickSort(a, low, high);

    for (int x : a)
    {
        cout << x << " ";
    }

    return 0;
}