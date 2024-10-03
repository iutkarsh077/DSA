#include <bits/stdc++.h>
using namespace std;

void RecurBubbleSort(int arr[], int i, int j, int n)
{
    if (j >= n - i - 1)
    {
        return;
    }
    swap(arr[j], arr[j + 1]);

    RecurBubbleSort(arr, i, j + 1, n);
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        RecurBubbleSort(arr, i, 0, n);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}