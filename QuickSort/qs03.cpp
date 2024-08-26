#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int count = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (pivot > arr[i])
        {
            count++;
        }
    }

    int pivotIndex = count + low;
    swap(arr[pivotIndex], arr[low]);
    int i = low, j = high;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
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

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}
int main()
{
    int arr[] = {5, 1, 2, 8, 7, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = n - 1;

    quickSort(arr, s, e);

    int i = 0;
    while (i < 7)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}