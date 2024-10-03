#include <bits/stdc++.h>
using namespace std;

void RecurInsert(int arr[], int i, int j, int n, int val)
{
    if (j < 0 || arr[j] <= val)
    {
        arr[j + 1] = val;
        return;
    }
    arr[j + 1] = arr[j];

    RecurInsert(arr, i, j - 1, n, val);
}

int main()
{
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int val = arr[i];
        RecurInsert(arr, i, i - 1, n, val);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}