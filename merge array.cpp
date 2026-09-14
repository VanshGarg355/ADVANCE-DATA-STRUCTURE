#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[j] << " ";
            j++;
        }
    }

    while (i < a.size())
    {
        cout << a[i] << " ";
        i++;
    }

    while (j < b.size())
    {
        cout << b[j] << " ";
        j++;
    }

    cout << endl;
}

void UnionArray(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (b[j] < a[i])
        {
            cout << b[j] << " ";
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while (i < a.size())
    {
        cout << a[i] << " ";
        i++;
    }

    while (j < b.size())
    {
        cout << b[j] << " ";
        j++;
    }

    cout << endl;
}

// intersection
void IntersectionArray(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while (i < a.size())
    {
        cout << a[i] << " ";
        i++;
    }

    while (j < b.size())
    {
        cout << b[j] << " ";
        j++;
    }

    cout << endl;
}

// A - B
void DiffArray(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < a.size())
    {
        cout << a[i] << " ";
        i++;
    }

    cout << endl;
}

int main()
{
    vector<int> a = {1, 2, 3, 5, 9, 34};
    vector<int> b = {4, 5, 14, 21, 33, 92};

    cout << "Merge array :" << endl;
    mergeArray(a, b);

    cout << "Union of array :" << endl;
    UnionArray(a, b);

    cout << "Intersection of array :" << endl;
    IntersectionArray(a, b);

    cout << "Difference A-B :" << endl;
    DiffArray(a, b);

    return 0;
}