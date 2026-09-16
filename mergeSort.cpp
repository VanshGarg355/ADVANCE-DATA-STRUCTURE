#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int main()
{
    int arr[] = {5, 3, 9, 1, 4, 2};

    int n = 6;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}