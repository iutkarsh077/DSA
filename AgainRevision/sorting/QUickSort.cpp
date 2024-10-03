#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int cnt = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = cnt + low;
    swap(arr[low], arr[pivotIndex]);

    int i = low;
    int j = high;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }

        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void QuickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int p = partition(arr, low, high);
    QuickSort(arr, low, p - 1);
    QuickSort(arr, p + 1, high);
}
int main()
{
    int arr[] = {4, 1, 2, 5, 3, 2, 8, 564, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    QuickSort(arr, low, high);

    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}