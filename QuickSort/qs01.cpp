#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int partition(int arr[], int low, int high)
{
    int cnt = 0;
    int pivot = low;

    for (int i = low + 1; i <= high; i++)
    {
        if (pivot >= arr[i])
        {
            cnt++;
        }
    }

    int pivotIndex = low + cnt;
    swap(arr[low], arr[pivotIndex]);

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
    int arr[] = {3, 2, 1, 5, 4, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;

    quickSort(arr, low, high);

     for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}